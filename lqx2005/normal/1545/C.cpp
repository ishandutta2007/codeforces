#include <bits/stdc++.h>

using namespace std;
const int N = 500 + 10, P = 998244353;
int n;
int vis[N][N], p[N * 2][N], used[N * 2], latin[N * 2];

void del(int row) {
    used[row] = 1;
    for(int i = 1; i <= n; i++) {
        vis[p[row][i]][i]--;
    }
    return;
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n * 2; i++) used[i] = latin[i] = 0;
    for(int i = 1; i <= 2 * n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> p[i][j];
            vis[p[i][j]][j]++;
        }
    }
    int ans = 1;
    for(int i = 1; i <= n; i++) {
        int row = -1;
        for(int j = 1; j <= n * 2; j++) {
            if(used[j]) continue;
            for(int k = 1; k <= n; k++) {
                if(vis[p[j][k]][k] == 1) {
                    row = j;
                    break;
                }
            }
            if(row != -1) break;
        }
        if(row == -1) {
            for(int j = 1; j <= n * 2; j++) {
                if(!used[j]) {
                    row = j;
                    break;
                }
            }
            ans = 1ll * ans * 2 % P;
        }
        latin[row] = 1;
        del(row);
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n * 2; k++) {
                if(p[row][j] == p[k][j] && !used[k]) {
                    del(k);
                }
            }
        }
    }
    cout << ans << endl;
    for(int i = 1; i <= n * 2; i++) if(latin[i]) cout << i <<" ";
    cout << endl;
    return;
}

int main() {
    int T;
    cin >> T;
    for(; T--; ) solve();
    return 0;
}