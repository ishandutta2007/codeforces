#include <bits/stdc++.h>
#define par pair<pii, int>
#define x first
#define y second
#define eb emplace_back
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int N = 64 + 10, M = 256 + 10, K = 6000 + 10;
int n, m;
int a[K][M], tot = 0, x[M], used[K];
int e[N][N], id[N][N];
int Gauss() {
    memset(used, 0, sizeof(used));
    memset(x, 0, sizeof(x));
    for(int i = 1; i <= m; i++) {
        int p = -1;
        for(int j = 1; j <= tot; j++) {
            if(!used[j] && a[j][i]) {
                p = j;
                break;
            }
        }
        if(p == -1) continue;
        used[p] = 1;
        vector<int> pos;
        for(int j = 1; j <= m + 1; j++) if(a[p][j]) pos.push_back(j);
        for(int j = 1; j <= tot; j++) {
            if(j == p) continue;
            if(a[j][i]) {
                int coef = a[j][i] * a[p][i] % 3;
                coef = (3 - coef) % 3;
                for(int k : pos) {
                    (a[j][k] += coef * a[p][k]) %= 3;
                }
            }
        }
    }
    for(int i = 1; i <= tot; i++) {
        vector<int> pos;
        for(int j = 1; j <= m; j++) if(a[i][j]) pos.push_back(j);
        if(pos.empty()) {
            if(a[i][m + 1]) return 0;
            else continue;
        }
        x[pos.front()] = a[i][m + 1] * a[i][pos.front()] % 3;
    }
    return 1;
}
void solve() {
    memset(a, 0, sizeof(a));
    memset(e, 0, sizeof(e));
    memset(id, 0, sizeof(id));
    tot = 0;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u][v] = e[v][u] = w;
        id[u][v] = id[v][u] = i;
        if(w > 0) {
            tot++;
            a[tot][i] = 1, a[tot][m + 1] = w % 3;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            for(int k = j + 1; k <= n; k++) {
                if(e[i][j] && e[i][k] && e[j][k]) {
                    tot++;
                    a[tot][id[i][j]] = a[tot][id[j][k]] = a[tot][id[i][k]] = 1;
                }
            }
        }
    }
    // for(int i = 1; i <= tot; i++) {
    //     for(int j = 1; j <= m; j++) {
    //         cout << a[i][j] <<" ";
    //     }
    //     cout << endl;
    // }
    if(!Gauss()) {
        cout << -1 << endl;
        return;
    }
    for(int i = 1; i <= m; i++) {
        if(x[i] == 0) x[i] += 3;
        cout << x[i] <<" ";
    }
    cout << endl;
    return;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; solve());
    return 0;
}