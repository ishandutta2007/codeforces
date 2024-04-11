#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const mod1 = inf + 7;
int const mod2 = inf + 9;
int const base = 43;

pii sum(pii a, pii b) {
    return mp(
            (a.first + b.first) % mod1,
            (a.second + b.second) % mod2
    );
}

pii mul(pii a, pii b) {
    return mp(
            (1ll * a.first * b.first) % mod1,
            (1ll * a.second * b.second) % mod2
    );
}

int const N = 300005;

int n;
int c[N];
char s[N];
vec< int > g[N];
pii hs[N];
set< pii > diff[N];

int res_val = -1;
int res_cnt = 0;

void dfs(int v, int par = -1) {
    if(par != -1) hs[v] = hs[par];
    hs[v] = sum({s[v], s[v]}, mul(hs[v], {base, base}));
    diff[v] = {hs[v]};
    for(int to : g[v]) {
        if(to == par) continue;
        dfs(to, v);
        if(diff[v].size() < diff[to].size()) swap(diff[v], diff[to]);
        for(auto x : diff[to]) diff[v].insert(x);
    }
    if((int)diff[v].size() + c[v] > res_val) {
        res_val = (int)diff[v].size() + c[v];
        res_cnt = 1;
    }else if((int)diff[v].size() + c[v] == res_val) {
        res_cnt++;
    }
}

bool solve() {

    scanf("%d", &n);
    for(int i = 1;i <= n;i++) scanf("%d", &c[i]);
    scanf("%s", s + 1);
    for(int i = 1;i <= n;i++) s[i] = s[i] - 'a' + 1;

    for(int u, v, i = 1;i < n;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    printf("%d\n%d\n", res_val, res_cnt);

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}