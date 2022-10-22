#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1005;

int n, m, k;
int c[N];
vec< int > g[N];
bool used[N];

int main() {

    scanf("%d %d %d", &n, &m, &k);

    for(int i = 1;i <= k;i++) scanf("%d", &c[i]);

    for(int u, v, iter = 0;iter < m;iter++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int tot = 0, cnt, ed, mx = 0;
    queue< int > q;

    ll res = 0;

    int tot_edge = 0;

    for(int i = 1;i <= k;i++) {
        cnt = 1;
        ed = (int)g[ c[i] ].size();
        q.push( c[i] );
        used[ c[i] ] = 1;
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(int to : g[v]) {
                if(!used[to]) {
                    used[to] = 1;
                    q.push( to );
                    cnt++;
                    ed += (int)g[to].size();
                }
            }
        }
        ed /= 2;
        tot += cnt;
        res += 1ll * cnt * (cnt - 1) / 2 - ed;
        mx = max(mx, cnt);
        tot_edge += ed;
    }

    tot_edge = m - tot_edge;

    tot = n - tot;

    for(int i = 0;i < tot;i++) {
        res += mx;
        mx++;
    }

    cout << res - tot_edge << "\n";

    return 0;
}