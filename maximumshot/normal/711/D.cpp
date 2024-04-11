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

inline int mul(int a, int b) {
    return (1ll * a * b) % mod;
}

inline int sum(int a, int b) {
    return (a + b) % mod;
}

inline int raz(int a, int b) {
    return ((a - b) % mod + mod) % mod;
}

int const N = 200005;

int n;
vec< int > g[N];
vec< int > g2[N];
int pw[N];

int st, fn;
int par[N];
int col[N];

bool dfs(int v) {
    col[v] = 1;
    for(int to : g[v]) {
        if(col[to] == 0) {
            par[to] = v;
            if(dfs(to)) return 1;
        }else if(col[to] == 1) {
            st = to;
            fn = v;
            return 1;
        }
    }
    col[v] = 2;
    return 0;
}

bool used[N];

void go(int v) {
    used[v] = 1;
    for(int to : g2[v]) {
        if(!used[to]) go(to);
    }
}

bool solve() {

    pw[0] = 1;
    for(int i = 1;i < N;i++) {
        pw[i] = mul(pw[i - 1], 2);
    }

    scanf("%d", &n);

    for(int x, i = 1;i <= n;i++) {
        scanf("%d", &x);
        g[i].push_back(x);
        g2[i].push_back(x);
        g2[x].push_back(i);
    }

    int res = 1;
    int tot = n;

    for(int i = 1;i <= n;i++) {
        if(used[i]) continue;
        if(dfs(i)) {
            //cout << st << " " << fn << " cycle\n";
            int x = 1;
            while(fn != st) x++, fn = par[fn];
            res = mul(res, raz(pw[x], 2));
            tot -= x;
            go(st);
        }
    }

    res = mul(res, pw[tot]);

    printf("%d\n", res);

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