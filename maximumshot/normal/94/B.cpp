#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 5;

int g[N][N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m;

    cin >> m;

    for (int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        u--, v--;
        g[u][v] = g[v][u] = 1;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                vector<int> vs = {i, j, k};
                int c1 = 0;
                int c2 = 0;
                for (int x : vs) {
                    for (int y : vs) {
                        if (x < y) {
                           c1 += g[x][y];
                           c2 += !g[x][y];
                        }
                    }
                }
                if (c1 == 3 || c2 == 3) {
                    cout << "WIN\n";
                    return 0;
                }
            }
        }
    }

    cout << "FAIL\n";

    return 0;
}