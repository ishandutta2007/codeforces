#include <iostream>
#include <string>

using namespace std;

void do_smth(int i) {
    switch (i % 3) {
        case 0:
            cout << "P" << endl;
            break;
        case 1:
            cout << "S" << endl;
            break;
        case 2:
            cout << "R" << endl;
            break;
        default:
            cout << "What?????";
    }
}

bool Player[20] = {false, false, false, false, false,
                   false, false, false, false, false,
                   false, false, false, false, false,
                   false, false, false, false, false};
char Played[20] = {'S', 'S', 'S', 'S', 'S',
                   'S', 'S', 'S', 'S', 'S',
                   'S', 'S', 'S', 'S', 'S',
                   'S', 'S', 'S', 'S', 'S',};

void do_smth_strange(int i) {
    if (Player[i - 1]) {
        cout << Played[i - 1] << endl;
        Played[i] = Played[i - 1];
    } else {
        switch (Played[i - 1]) {
            case 'P':
                cout << 'R' << endl;
                Played[i] = 'R';
                break;
            case 'R':
                cout << 'S' << endl;
                Played[i] = 'S';
                break;
            case 'S':
                cout << 'P' << endl;
                Played[i] = 'P';
                break;
        }
    }
    cout.flush();
    static string verdict;
    getline(cin, verdict);
    if (verdict == "Player") {
        Player[i] = true;
    }
}

int main() {
    cout << 'P' << endl;
    cout.flush();
    string verdict;
    getline(cin, verdict);
    bool curious = false;
    bool very_curious = false;
    bool test_6 = false;
    if (verdict == "player") {
        for (int i = 0; i < 19; ++i) {
            if (!curious) cout << 'P' << endl;
            else {
                if (!test_6) do_smth(i + 1); else do_smth_strange(i);
            }
            cout.flush();
            if (!test_6) {
                getline(cin, verdict);
                if (verdict == "ai") {
                    if (!curious) {
                        curious = true;
                    } else {
                        if (!very_curious) {
                            very_curious = true;
                        } else {
                            test_6 = true;
                        }
                    }
                }
            }
        }
    }
    cout << 'S' << endl;
    cout.flush();
    getline(cin, verdict);
    if (verdict == "player") {
        for (int i = 0; i < 18; ++i) {
            if (!curious) cout << 'S' << endl;
            else {
                if (!test_6) do_smth(i + 2); else do_smth_strange(i);
            }
            cout.flush();
            if (!test_6) {
                getline(cin, verdict);
                if (verdict == "ai") {
                    if (!curious) {
                        curious = true;
                    } else {
                        if (!very_curious) {
                            very_curious = true;
                        } else {
                            test_6 = true;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < 17; ++i) {
        if (!curious) cout << 'R' << endl;
        else {
            if (!test_6) do_smth(i + 3); else do_smth_strange(i);
        }
        cout.flush();
        if (!test_6) {
            getline(cin, verdict);
            if (verdict == "ai") {
                if (!curious) {
                    curious = true;
                } else {
                    if (!very_curious) {
                        very_curious = true;
                    } else {
                        test_6 = true;
                    }
                }
            }
        }
    }
}