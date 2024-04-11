#include<bits/stdc++.h>
using namespace std;
int n, m;

void upd_min(int &a, int b) {
    a = min(a, b);
}
void upd_max(int &a, int b) {
    a = max(a, b);
}

void solve() {
    cin >> n >> m;
    vector < vector <int>> a(n);
    for (auto &i : a) {
        i.resize(m);
        for (auto &j: i) cin >> j;
    }
    vector < vector <int>> min_pref = a, max_pref = a, min_suf = a, max_suf = a;

    for (int i = 0 ; i < n ; ++ i) {
        for (int  j = 1 ; j < m ; ++ j) {
            upd_min(min_pref[i][j], min_pref[i][j - 1]);
            upd_max(max_pref[i][j], max_pref[i][j - 1]);
        }
        for (int j = m - 2 ; j >= 0 ; -- j) {
            upd_min(min_suf[i][j], min_suf[i][j + 1]);
            upd_max(max_suf[i][j], max_suf[i][j + 1]);
        }
    }
    vector <int> ord(n);
    vector <int> min_B(n), max_D(n);

    for (int k = 0 ; k + 1 < m ; ++ k) {
         iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j) {
            return max_pref[i][k] < max_pref[j][k];
        });
        /// now we get order, we should slicing in i dimension...
        /**
        what info we need to determine good split?
        ___________________
                |
            A   |     C
                |
        ________|__________
                |
            B   |     D
                |
        ________|__________
        max(A) < min(B) && max(D) < min(C)
        build maximum suffix on B and D
        */
        for (int j = n - 1 ; j >= 0 ; -- j) {
            int x = ord[j];
            min_B[j] = min_pref[x][k];
            max_D[j] = max_suf[x][k + 1];
            if (j + 1 < n) upd_max(max_D[j], max_D[j + 1]);
            if (j + 1 < n) upd_min(min_B[j], min_B[j + 1]);
        }
        int min_C = 1 << 30;
        for (int i = 0 ; i + 1 < n ; ++ i) {
            int x = ord[i];
            upd_min(min_C, min_suf[x][k + 1]);

            if (max_pref[x][k] < min_B[i + 1] && min_C > max_D[i + 1]) {
                cout << "YES\n";
                string foo(n, 'R');
                for (int j = 0 ; j <= i ; ++ j) foo[ord[j]] = 'B';
                cout << foo << ' ' << k + 1 << '\n';
                return;
            }
        }
    }
    cout << "NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}