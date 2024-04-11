#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

int ask(char c, int t) {
    printf("%c %d\n", c, t);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    return res;
}

void ans(int s) {
    printf("C %d\n", s);
    fflush(stdout);
}

const int N = 1005;

int n;
vec< int > g[N];

int dfs(int v, int par, const unordered_set< int > &ma) {
    if(ma.count(v)) return v;
    for(int to : g[v]) {
        if(to == par) continue;
        int tmp = dfs(to, v, ma);
        if(tmp != -1) return tmp;
    }
    return -1;
}

void solve() {
    scanf("%d", &n);

    for(int v = 1;v <= n;v++) g[v].clear();

    for(int u, v, i = 1;i < n;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int k1, k2;

    scanf("%d", &k1);
    vec< int > a(k1);
    for(int &x : a) scanf("%d", &x);

    scanf("%d", &k2);
    vec< int > b(k2);
    for(int &x : b) scanf("%d", &x);

    unordered_set< int > ma, mb;

    for(int x : a) ma.insert(x);
    for(int x : b) mb.insert(x);

    int s = ask('B', b[0]);

    if(ma.count(s)) {
        ans(s);
        return;
    }

    s = dfs(s, -1, ma);
    int s2 = ask('A', s);
    ans(mb.count(s2) ? s : -1);
}

int main() {

#ifdef debug
//    freopen("input.txt", "r", stdin);
#endif

    int t;

    scanf("%d", &t);

    while(t--) {
        solve();
    }

    return 0;
}