#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
bool good = false;
void readMove(int& x, int& y) {
    string s;
    cin >> s;
    if (s == "Done") {
        x = 228;
        y = 228;
        good = true;
        return;
    }
    x = 0;
    y = 0;
    if (s.find("Left") != string::npos) {
        y = -1;
    }
    if (s.find("Right") != string::npos) {
        y = 1;
    }
    if (s.find("Down") != string::npos) {
        x = 1;
    }
    if (s.find("Up") != string::npos) {
        x = -1;
    }
}
int Z = 0;
void printQ(int qX, int qY) {
    assert(Z <= 128);
    Z++;
    cout << qX << " " << qY << endl;
}
void solve() {
    Z = 0;
    int qX = 2;
    int qY = 1;
    int x,y;
    good = false;
    printQ(qX, qY);
    readMove(x, y);
    if (good) return;
    qX = 1;
    printQ(qX, qY);
    for (int col = 1; col < 8; col++) {
        assert(qY == col);
        bool was = false;
        if (qX != 1) {
            readMove(x, y);
            if (good) return;
            if (y == 1) {
                was = true;
                qY++;
                printQ(qX, qY);
                continue;
            }
            qX = 1;
            printQ(qX, qY);
        }
        while (true) {
            bool wasL = false;
            assert(qX == 1 || qX == 8);
            bool sgn = false;
            if (qX == 8) sgn = true;
            for (int z = 2; z <= 9; z++) {
               // cout << " HI " << z << " " << qX << " " << qY << endl;;
                readMove(x, y);
                if (good) return;
                if (y == 1) {
                    was = true;
                    qY++;
                    printQ(qX, qY);
                    break;
                }
                if (y == -1) {
                    wasL = true;
                    if (qX != 1) {
                        qX = 1;
                        printQ(qX, qY);
                    }
                    else {
                        qX = 8;
                        printQ(qX, qY);
                    }
                    break;
                }
                if (!sgn) {
                    if (qX == 8) break;
                    qX++;
                    printQ(qX, qY);
                }
                else {
                    if (qX == 1) break;
                    qX--;
                    printQ(qX, qY);
                }
            }
            if (was) break;
            if (wasL) continue;
            qY++;
            printQ(qX, qY);
            break;
        }
    }
}
int main() {
  //  freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
}