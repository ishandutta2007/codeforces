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

int const LOG = 25;

int const N = 100005;

int n;
int a[N];
vec< int > g[N];
ll res = 0;

int cnt[2][LOG][N];

void dfs(int v, int par = -1) {
    for(int to : g[v]) {
        if(to == par) continue;
        dfs(to, v);
        for(int i = 0;i < LOG;i++) {
            int cur = (a[v] >> i) & 1;
            for(int x = 0;x < 2;x++) {
                res += (1ll << i) * ll(1ll * cnt[x][i][v] * cnt[x ^ 1][i][to]);
            }
            for(int x = 0;x < 2;x++) {
                cnt[x][i][v] += cnt[x ^ cur][i][to];
            }
        }
    }
    for(int i = 0;i < LOG;i++) {
        res += (1ll << i) * (cnt[1][i][v]);
        cnt[(a[v] >> i) & 1][i][v]++;
    }
}

int main() {

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        res += a[i];
    }

    for(int u, v, i = 1;i < n;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    cout << res << "\n";

    return 0;
}