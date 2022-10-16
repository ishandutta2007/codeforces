#include <bits/stdc++.h>
#define ff(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
using namespace std;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

const int MAX = 1e5 + 5, mod = 1e9 + 7;

int n, m;
vector <vii> a;
bool vis[MAX];
bool lab[MAX];

int pw(int a, int b) {
    int res = 1, mul = a;
    while (b) {
        if (b & 1) res = 1ll * res * mul % mod;
        mul = 1ll * mul * mul % mod;
        b >>= 1;
    }
    return res;
}

void fail(void) {
    cout << 0 << endl; exit(0);
}

void dfs(int u) {
    vis[u] = 1;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i].fi, w = a[u][i].se;
        bool ass = w ? lab[u] : (lab[u] ^ 1);
        if (vis[v]) {
            if (lab[v] != ass) return fail();
            continue;
        }
        lab[v] = ass;
        dfs(v);
    }
}

void init(void) {
    cin >> n >> m;
    a.assign(n + 1, vii());
    ff(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].pb(mp(v,w));
        a[v].pb(mp(u,w));
    }
}

void process(void) {
    int cnt = 0;
    ff(i, 1, n) if (!vis[i]) { cnt++; dfs(i); }
    cout << pw(2, cnt - 1) << endl;

}

int main(void) {
    init();
    process();
    return 0;
}