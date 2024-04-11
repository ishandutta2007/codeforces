#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 1005;
int x[maxN][maxN], y[maxN][maxN];
char ans[maxN][maxN];
bool used[maxN][maxN];
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0,  0, 1, -1};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    queue < pair < int, int > > q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> x[i][j] >> y[i][j];
            if (x[i][j] == i && y[i][j] == j) {
                used[i][j] = true;
                q.push({i, j});
                ans[i][j] = 'X';
            }
        }
    }
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        int a = it.first;
        int b = it.second;
        for (int k = 0; k < 4; k++) {
            int na = a + dx[k];
            int nb = b + dy[k];
            if (na < 1 || na > n || nb < 1 || nb > n) continue;
            if (used[na][nb]) continue;
            if (x[na][nb] == x[a][b] && y[na][nb] == y[a][b]) {
                used[na][nb] = true;
                if (a == na && b == nb + 1) {
                    ans[na][nb] = 'R';
                }
                if (a == na && b == nb - 1) {
                    ans[na][nb] = 'L';
                }
                if (a == na - 1 && b == nb) {
                    ans[na][nb] = 'U';
                }
                if (a == na + 1 && b == nb) {
                    ans[na][nb] = 'D';
                }
                q.push({na, nb});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i][j] != -1 && !used[i][j]) {
                cout << "INVALID";
                return 0;
            }
        }
    }
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            if (used[a][b]) continue;
            bool ok = false;
            for (int k = 0; k < 4; k++) {
                int na = a + dx[k];
                int nb = b + dy[k];
                if (na < 1 || na > n || nb < 1 || nb > n) continue;
                if (x[na][nb] != -1) continue;
                ok = true;
                used[a][b] = true;
                if (!used[na][nb]) {
                    //add two edges
                    used[na][nb] = true;
                    if (a == na && b == nb + 1) {
                        ans[na][nb] = 'R';
                        ans[a][b] = 'L';
                    }
                    if (a == na && b == nb - 1) {
                        ans[na][nb] = 'L';
                        ans[a][b] = 'R';
                    }
                    if (a == na - 1 && b == nb) {
                        ans[na][nb] = 'U';
                        ans[a][b] = 'D';
                    }
                    if (a == na + 1 && b == nb) {
                        ans[na][nb] = 'D';
                        ans[a][b] = 'U';
                    }
                }
                else {
                    //add one edge
                    if (a == na && b == nb + 1) {
//                        ans[na][nb] = 'R';
                        ans[a][b] = 'L';
                    }
                    if (a == na && b == nb - 1) {
//                        ans[na][nb] = 'L';
                        ans[a][b] = 'R';
                    }
                    if (a == na - 1 && b == nb) {
//                        ans[na][nb] = 'U';
                        ans[a][b] = 'D';
                    }
                    if (a == na + 1 && b == nb) {
//                        ans[na][nb] = 'D';
                        ans[a][b] = 'U';
                    }
                }
                break;
            }
            if (!ok) {
                cout << "INVALID";
                return 0;
            }
        }
    }
    cout << "VALID\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
    return 0;
}