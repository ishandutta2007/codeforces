#include <bits/stdc++.h>

using namespace std;

int n = 10;
int mat[11][11];

char mp[200];

bool good(int i, int j) { return 0 <= i && 0 <= j && i < n && j < n && mat[i][j] == 1; }

bool check_hor(int i, int j) {
    for (int k = 0; k < 5; k++)
        if (!good(i, j + k))
            return false;
    return true;
}

bool check_ver(int i, int j) {
    for (int k = 0; k < 5; k++)
        if (!good(i + k, j))
            return false;
    return true;
}

bool check_diag(int i, int j) {
    for (int k = 0; k < 5; k++)
        if (!good(i + k, j + k))
            return false;
    return true;
}

bool check_diag2(int i, int j) {
    for (int k = 0; k < 5; k++)
        if (!good(i + k, j - k))
            return false;
    return true;
}

bool check() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (check_hor(i, j) || check_ver(i, j) || check_diag(i, j) || check_diag2(i, j))
                return true;
    return false;
}

int main() {
    mp['X'] = 1, mp['O'] = 0, mp['.'] = -1;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++)
            mat[i][j] = mp[s[j]];
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j] == -1) {
                mat[i][j] = 1;
                if (check()) {
                    cout << "YES\n";
                    return 0;
                }
                mat[i][j] = -1;
            }

    cout << "NO\n";
}