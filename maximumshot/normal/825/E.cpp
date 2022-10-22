#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e5 + 5;

int n, m;
vec< int > g[N];
int d[N];
int res[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);

    for(int u, v, iter = 0;iter < m;iter++) {
        scanf("%d %d", &u, &v);
        g[v].push_back(u);
        d[u]++;
    }

    set< pii > q;

    for(int i = 1;i <= n;i++) {
        q.insert(make_pair(d[i], -i));
    }

    int cur = n;

    while(!q.empty()) {
        int v = -q.begin()->second;
        q.erase(q.begin());
        res[v] = cur--;
        for(int to : g[v]) {
            if(q.count(make_pair(d[to], -to))) {
                q.erase(make_pair(d[to], -to));
                d[to]--;
                q.insert(make_pair(d[to], -to));
            }
        }
    }

    for(int i = 1;i <= n;i++) {
        printf("%d ", res[i]);
    }

    printf("\n");

    return 0;
}