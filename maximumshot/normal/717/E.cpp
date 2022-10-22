#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const mod = inf + 7;

inline int sum(int a, int b) { return (a + b) % mod; }
inline int mul(int a, int b) { return (1ll * a * b) % mod; }
inline int raz(int a, int b) { return ((a - b) % mod + mod) % mod; }

int binpow(int n, int p) {
    if(p == 0) return 1;
    int q = binpow(n, p / 2);
    q = mul(q, q);
    if(p % 2) q = mul(q, n);
    return q;
}

int const N = 200005;

int n;
int p[N];
vec< int > g[N];
int answer[10 * N];
int sz = 0;

void dfs(int v, int par = -1) {
    answer[sz++] = v;
    p[v] = (p[v] == 1?-1 : 1);
    for(int to : g[v]) {
        if(to == par) continue;
        dfs(to, v);
        answer[sz++] = v;
        p[v] = (p[v] == 1?-1 : 1);
        if(p[to] == -1) {
            answer[sz++] = to;
            answer[sz++] = v;
            p[to] = 1;
            p[v] = (p[v] == 1?-1 : 1);
        }
    }
}

bool solve() {

    scanf("%d", &n);

    int ok = 0;
    for(int i = 1;i <= n;i++) {
        scanf("%d", &p[i]);
        if(p[i] == -1) {
            ok = 1;
        }
    }

    if(!ok) {
        printf("1\n");
        return true;
    }

    for(int u, v, i = 1;i < n;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    p[1] = (p[1] == 1?-1 : 1);

    dfs(1);

    sz = unique(answer, answer + sz) - answer;

    if(p[1] == -1) {
        sz--;
    }

    for(int i = 0;i < sz;i++) printf("%d ", answer[i]);
    printf("\n");

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}