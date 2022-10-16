#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;
typedef pair<LL, int> PII;

const int N = 1e5 + 5, P = 1e9 + 7;

int n;

LL x[N];

vector<int> g[N];

vector<PII> a[N];

LL gcd(LL a, LL b) {
    return b ? gcd(b, a % b) : a;
}

void inline add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}

void inline Add(int x, PII t) {
    for (int i = 0; i < a[x].size(); i++) {
        if (a[x][i].fi == t.fi) {
            add(a[x][i].se, t.se);
            return;
        }
    }
    a[x].pb(t);
}

int ans;

void dfs(int u, int fa) {
    for (int i = 0; i < a[fa].size(); i++)
        Add(u, mp(gcd(x[u], a[fa][i].fi), a[fa][i].se));
    Add(u, mp(x[u], 1));
    for (int i = 0; i < a[u].size(); i++) {
        add(ans, a[u][i].fi % P * a[u][i].se % P);
       // cout << u << " " << a[u][i].fi << " is " << a[u][i].se << endl;
    }
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs(v, u);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", x + i);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d%d", &u, &v);
        g[u].pb(v), g[v].pb(u);
    }
    dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}