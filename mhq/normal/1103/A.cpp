#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool used[10][10];
bool nused[10][10];
void reduce() {
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            nused[i][j] = used[i][j];
        }
    }
    for (int i = 1; i <= 4; i++) {
        bool ok = true;
        for (int j = 1; j <= 4; j++) {
            if (!used[i][j]) {
                ok = false;
            }
        }
        if (ok) {
            for (int j = 1; j <= 4; j++) {
                nused[i][j] = false;
            }
        }
    }
    for (int i = 1; i <= 4; i++) {
        bool ok = true;
        for (int j = 1; j <= 4; j++) {
            if (!used[j][i]) {
                ok = false;
            }
        }
        if (ok) {
            for (int j = 1; j <= 4; j++) {
                nused[j][i] = false;
            }
        }
    }
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            used[i][j] = nused[i][j];
        }
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            if (!used[1][1]) {
                used[1][1] = true;
                used[2][1] = true;
                cout << 1 << " " << 1 << '\n';
            }
            else if (!used[3][1]) {
                used[3][1] = true;
                used[4][1] = true;
                cout << 3 << " " << 1 << '\n';
            }
        }
        else {
            for (int j = 1; j <= 4; j++) {
                if (!used[j][3]) {
                    used[j][3] = true;
                    used[j][4] = true;
                    cout << j << " " << 3 << '\n';
                    break;
                }
            }
        }
        reduce();
    }
    return 0;
}