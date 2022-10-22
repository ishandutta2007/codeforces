#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef pair< ll, ll > pll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 35;

int n;
vec< int > g[N];
pll crd[N];
pll dr[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

void dfs(int v, ll x, ll y, ll d = 100000, int par = -1, int ty = -1) {
    crd[v] = make_pair(x, y);
    for(int to, j = 0, i = 0;i < (int)g[v].size();i++) {
        to = g[v][i];
        if(to == par) continue;
        if(j == ty) j++;
        dfs(to, x + dr[j].first * d / 2, y + dr[j].second * d / 2, d / 2, v, (j + 2) % 4);
        j++;
    }
}

int find_center() {
    vec< vec< int > > d(n + 1, vec< int >(n + 1, inf));
    for(int i = 1;i <= n;i++) {
        for(int j : g[i]) {
            d[i][j] = d[j][i] = 1;
        }
    }
    for(int k = 1;k <= n;k++) {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    for(int i = 1;i <= n;i++) d[i][i] = 0;
    pii result = { inf, -1 };
    for(int i = 1;i <= n;i++) {
        int mx = 0;
        for(int j = 1;j <= n;j++) {
            mx = max(mx, d[i][j]);
        }
        result = min(result, make_pair(mx, i) );
    }
    return result.second;
}

int main() {

    cin >> n;

    for(int u, v, i = 1;i < n;i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 1;i <= n;i++) {
        if((int)g[i].size() > 4) {
            cout << "NO\n";
            return 0;
        }
    }

    dfs( find_center() , 0, 0);

    cout << "YES\n";

    for(int i = 1;i <= n;i++) {
        cout << crd[i].first << " " << crd[i].second << "\n";
    }

    return 0;
}