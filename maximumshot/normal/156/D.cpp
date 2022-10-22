#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e5 + 5;

int n, m, mod;

inline int Mul(int a, int b) {
    return (1ll * a * b) % mod;
}

int binpow(int x, int p) {
    if(!p) return 1 % mod;
    int q = binpow(x, p / 2);
    q = Mul(q, q);
    if(p % 2) q = Mul(q, x);
    return q;
}

vec< int > g[N];
bool used[N];
int cur;

void dfs(int v) {
    used[v] = 1;
    cur++;
    for(int to : g[v]) {
        if(!used[to]) {
            dfs(to);
        }
    }
}

int main() {

    scanf("%d %d %d", &n, &m, &mod);

    for(int u, v, i = 0;i < m;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int tmp = 1;
    int cnt = 0;

    for(int i = 1;i <= n;i++) {
        if(used[i]) continue;
        cur = 0;
        dfs(i);
        tmp = Mul(tmp, cur);
        cnt++;
    }

    if(cnt == 1) {
        printf("%d\n", 1 % mod);
        return 0;
    }

    printf("%d\n", Mul(tmp, binpow(n, cnt - 2)));

    return 0;
}