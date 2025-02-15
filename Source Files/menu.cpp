#include "menu.h"
#include "files.h"
#include "game.h"
#include "mensagens.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <utilapiset.h>
#include <Windows.h>
#include <mmsystem.h>


using namespace std;

Menu::Menu() {}

void Menu::imprimirMenu() {
    Jogo jogo;
    mensagens mensagem;

    while (true) {
        mensagem.Menu();
        mensagem.getEscolha();

        opcaoMenu = mensagem.escolha;

        if (opcaoMenu == 1) {
            continuarSalvo = false;
            novoJogo();
        } else if (opcaoMenu == 2) {
            continuarSalvo = true;
            escolhaModo=1;
            dificuldade();
        } else if (opcaoMenu ==3) {
            tutorial();

        } else if (opcaoMenu == 4) {
            estatisticas();
        } else if (opcaoMenu == 5) {
            top10();
            //Tutorial
        } else if (opcaoMenu == 6) {
            sairMenu();
            break;
        }
        else {
            mensagem.opcaoInvalida();
            imprimirMenu();
        }
        break;

    }
}

// Opcao 1 - Novo Jogo
void Menu::novoJogo() {
    Jogo jogo;
    mensagens mensagem;

    system("cls");

    mensagem.LinhaS();
    cout << "Caso comece um novo jogo," << endl << "O jogo anterior sera eliminado!" << endl;
    mensagem.LinhaS();
    mensagem.temCerteza();
    mensagem.getEscolha();

    if(mensagem.escolha == 1){
        modo();
    }else {
        imprimirMenu();
    }
}

//Escolher Modo de Funcionamento
int Menu::modo() {
    mensagens mensagem;
    Jogo jogo;

    mensagem.Modo();
    mensagem.getEscolha();
    escolhaModo = mensagem.escolha;

    // Verifica se o input está dentro do intervalo válido
    if (escolhaModo < 1 || escolhaModo > 4) {
        mensagem.opcaoInvalida();
        return modo(); // Chama recursivamente a função para lidar com o input inválido
    }
    system("cls");
    mensagem.LinhaL();

    switch (escolhaModo) {
    case 1:
        cout << "[Modo] Jogador contra Computador" << endl;
        mensagem.LinhaL();
        dificuldade();
        break;
    case 2:
        cout << "[Modo] Jogador contra Jogador" << endl;
        break;
    case 3:
        cout << "[Modo] Computador contra Computador" << endl;
        mensagem.LinhaL();
        dificuldade();
        dificuldade2();
        break;
    case 4:
        system("cls");
        mensagem.LinhaS();
        cout << "Esta prestes a voltar ao Menu." << endl;
        mensagem.LinhaS();
        mensagem.temCerteza();
        mensagem.getEscolha();
        escolha = mensagem.escolha;
        if(escolha == 1 || escolha == 2) {
            imprimirMenu();
        } else {
            mensagem.opcaoInvalida();
            return modo(); // Chame a função dificuldade novamente se a opção não for 1 ou 2
        }
        break;
    }
    return escolhaModo;
}

// Escolher a dificuldade dos Bots
int Menu::dificuldade() {
    mensagens mensagem;

    mensagem.Dificuldade();
    cout << " Escolha um nivel de dificuldade para o computador" << endl;
    mensagem.LinhaL();

    mensagem.getEscolha();
    escolhaJogo = mensagem.escolha;

    if (escolhaJogo < 1 || escolhaJogo > 6) {  // Verifica Intervalo
        return dificuldade();
    }
    if (escolhaJogo == 5) { // Gerar aleatório
        srand(time(nullptr));

        escolhaJogo = rand() % 4 + 1;
    }
    system("cls");
    mensagem.LinhaL();
    cout << "Sistema: Escolheu a opcao " << escolhaJogo;

    switch (escolhaJogo) {
    case 1:
        cout << " (Elementar)" << endl;
        mensagem.LinhaL();
        cout << endl << "O mais facil? Esta bem..." << endl << endl;
        break;
    case 2:
        cout << " (Basico)" << endl;
        mensagem.LinhaL();
        cout << endl << "Hm... A aquecer?" << endl <<endl;
        break;
    case 3:
        cout << " (Medio)" << endl;
        mensagem.LinhaL();
        cout << endl << "Entao queres um desafio? Tenta acompanhar..." << endl << endl;
        break;
    case 4:
        cout << " (Impossivel)" << endl;
        mensagem.LinhaL();
        cout << endl << "Boa sorte, e impossivel eu perder!" << endl << endl;
        break;
    case 6:
        system("cls");
        mensagem.LinhaS();
        cout << "Esta prestes a voltar aos Modos." << endl;
        mensagem.LinhaS();
        mensagem.temCerteza();
        mensagem.getEscolha();
        escolha = mensagem.escolha;
        if(escolha == 1 || escolha == 2) {
            modo();
        } else {
            mensagem.opcaoInvalida();
            return dificuldade(); // Chame a função dificuldade novamente se a opção não for 1 ou 2
        }
        break;
    }
    return escolhaJogo;
}

int Menu::dificuldade2() {
    mensagens mensagem;

    mensagem.Dificuldade();

    cout << "   Escolha um nivel de dificuldade para o bot 2" << endl;
    mensagem.LinhaL();

    mensagem.getEscolha();
    escolhaJogo2 = mensagem.escolha;

    if (escolhaJogo2 < 1 || escolhaJogo2 > 6) {  // Verifica Intervalo
        return dificuldade2();
    }
    if (escolhaJogo2 == 5) { // Gerar aleatório
        srand(time(nullptr));

        escolhaJogo2 = rand() % 4 + 1;
    }
    system("cls");
    mensagem.LinhaL();
    cout << "Sistema: Escolheu a opcao " << escolhaJogo2;

    switch (escolhaJogo2) {
    case 1:
        cout << " (Elementar)" << endl;
        mensagem.LinhaL();
        cout << endl << "O mais facil? Esta bem..." << endl << endl;
        break;
    case 2:
        cout << " (Basico)" << endl;
        mensagem.LinhaL();
        cout << endl << "Hm... A aquecer?" << endl <<endl;
        break;
    case 3:
        cout << " (Medio)" << endl;
        mensagem.LinhaL();
        cout << endl << "Entao queres um desafio? Tenta acompanhar..." << endl << endl;
        break;
    case 4:
        cout << " (Impossivel)" << endl;
        mensagem.LinhaL();
        cout << endl << "Boa sorte, e impossivel eu perder!" << endl << endl;
        break;
    case 6:
        system("cls");
        mensagem.LinhaS();
        cout << "Esta prestes a voltar aos Modos." << endl;
        mensagem.LinhaS();
        mensagem.temCerteza();
        mensagem.getEscolha();
        int escolha = mensagem.escolha;
        if(escolha == 1 || escolha == 2) {
            modo();
        } else {
            mensagem.opcaoInvalida();
            return dificuldade2(); // Chame a função dificuldade novamente se a opção não for 1 ou 2
        }
        break;
    }
    return escolhaJogo2;
}


// Opcao 3 - Estatisticas
void Menu::estatisticas() {
    mensagens mensagem;
    system("cls");

    CListaInteiros estatisticas;
    estatisticas.carregaDados("exemplo.txt");
    estatisticas.ordenaTop();
    estatisticas.escreveLista();
    cout << "[1] Voltar" << endl << "[2] Limpar Estatisticas" << endl;

    mensagem.getEscolha();

    if (mensagem.escolha == 1) {
        imprimirMenu();
    } else if (mensagem.escolha == 2) {
        estatisticas.limparEstatisticas();
        imprimirMenu();
    } else {
        mensagem.opcaoInvalida();
    }
}

// Opcao 4 - Top10
void Menu::top10() {
    mensagens mensagem;
    CListaInteiros estatisticas;
    system("cls");

    estatisticas.carregaDados("exemplo.txt");
    estatisticas.ordenaTop();
    estatisticas.escreveLista10();
    cout << "[1] Voltar" << endl << "[2] Limpar Estatisticas" << endl;

    mensagem.getEscolha();

    if (mensagem.escolha == 1) {
        imprimirMenu();
    } else if (mensagem.escolha == 2) {
        estatisticas.limparEstatisticas();
        imprimirMenu();
    } else {
        mensagem.opcaoInvalida();
    }
}

// Opcao 5 - Sair do Menu
void Menu::sairMenu() {
    mensagens mensagem;

    mensagem.LinhaS();
    cout << "Esta prestes a sair do jogo" << endl;
    mensagem.LinhaS();

    mensagem.temCerteza();
    mensagem.getEscolha();

    escolhaSair = mensagem.escolha; // Corrigindo a atribuição de 'escolha'

    while (true) {
        if (escolhaSair == 1) {
            cout << "Fim do jogo." << endl;
            system("pause");
            exit(0);
        } else if (escolhaSair == 2) {
            imprimirMenu();
            break; // Saia do loop se a escolha for 2
        } else {
            mensagem.opcaoInvalida();
            mensagem.getEscolha(); // Obtenha uma nova escolha
            escolha = mensagem.escolha; // Atualize 'escolha' com a nova entrada
        }
    }
}

void Menu::tutorial() {
    mensagens mensagem;
    system("cls");
    bool continuar = true;

    while(continuar) {
        system("cls");
        mensagem.LinhaM();
        cout << "Este e um guia para as posicoes do jogo" << endl;
        mensagem.LinhaM();

        // Imprime o tabuleiro com as posições atualizadas
        cout << "               |       |       " << endl;
        cout << "         1  " << posicao[0] << "  | 2  " << posicao[1] << "  | 3  " << posicao[2] << endl;
        cout << "               |       |       " << endl;
        cout << "        -------|-------|-------" << endl;
        cout << "               |       |       " << endl;
        cout << "         4  " << posicao[3] << "  | 5  " << posicao[4] << "  | 6  " << posicao[5] << endl;
        cout << "               |       |       " << endl;
        cout << "        -------|-------|-------" << endl;
        cout << "               |       |       " << endl;
        cout << "         7  " << posicao[6] << "  | 8  " << posicao[7] << "  | 9  " << posicao[8] << endl;
        cout << "               |       |       " << endl;

        mensagem.LinhaM();
        cout << "          PRIME UMA DAS TECLAS" << endl;
        cout << "  [1-9] Para jogar | [0] Voltar ao Menu" << endl;
        mensagem.LinhaM();

        mensagem.getEscolha();

        int escolhaPosicao = mensagem.escolha;

        if (escolhaPosicao == 0) {
            system("cls");
            mensagem.LinhaS();
            cout << "Esta prestes a voltar ao Menu." << endl;
            mensagem.LinhaS();
            mensagem.temCerteza();
            mensagem.getEscolha();
            int confirmacao = mensagem.escolha;

            if (confirmacao == 1) {
                Beep(320, 200);
                imprimirMenu();
                break;  // Sai do loop e termina tutorial
            } else if (confirmacao == 2) {
                continue;  // Continua no loop e reexibe o tutorial
            } else {
                mensagem.opcaoInvalida();
                system("pause");  // Dá uma pausa para o usuário ler a mensagem
                continue;  // Continua no loop e reexibe o tutorial
            }
        }
            if (escolhaPosicao >= 1 && escolhaPosicao <= 9 && posicao[escolhaPosicao - 1] == '-') {
                posicao[escolhaPosicao - 1] = turno ? 'X' : 'O';  // Insere 'X' ou 'O' com base no turno
                turno = !turno;  // Alterna o turno

            } else {
                mensagem.opcaoInvalida();
                system("pause");
            }
        }
    }
