#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 600000 + 5;
constexpr int mod = 1000000000 + 7;


int curx = 1, cury = 1;

void doit() {
    while (1) {
        int tpy = cury;
        bool ck = 0;
        while (cury < 8) {
            cout << curx << ' ' << cury + 1 << endl;
            cury++;
            string s;
            cin >> s;
            if (s == "Done") {
                return;
            }
            if (s == "Down" or s == "Down-Right" or s == "Down-Left") {
                cout << curx + 1 << ' ' << cury << endl;
                curx++;
                cin >> s;
                if (s == "Done") {
                    return;
                }
                ck = 1;
                break;
            }
        }
        if (ck) continue;
        while (cury > 1) {
            cout << curx << ' ' << cury - 1 << endl;
            cury--;
            string s;
            cin >> s;
            if (s == "Done") {
                return;
            }
            if (s == "Down" or s == "Down-Right" or s == "Down-Left") {
                cout << curx + 1 << ' ' << cury << endl;
                curx++;
                cin >> s;
                if (s == "Done") {
                    return;
                }
                ck = 1;
                break;
            }
        }
        if (ck) continue;
        while (cury < tpy) {
            cout << curx << ' ' << cury + 1 << endl;
            cury++;
            string s;
            cin >> s;
            if (s == "Done") {
                return;
            }
            if (s == "Down" or s == "Down-Right" or s == "Down-Left") {
                cout << curx + 1 << ' ' << cury << endl;
                curx++;
                cin >> s;
                if (s == "Done") {
                    return;
                }
                ck = 1;
                break;
            }
        }
        if (ck) continue;
        string s;
        cout << curx + 1 << ' ' << cury << endl;
        curx++;
        cin >> s;
        if (s == "Done") {
            return;
        }
    }

}
int main() {
    int T;
    cin >> T;
    while (T--) {
        curx = 1, cury = 1;
        cout << "1 1" << endl;
        string s;
        cin >> s;
        if (s == "Done") {
            continue;
        }
        doit();
    }

}