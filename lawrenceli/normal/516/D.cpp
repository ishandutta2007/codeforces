#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100100;
const ll INF = 1e15;

int n, q;
vector<pii> adj[MAXN];
ll ql[MAXN];

ll sma[MAXN], ma[MAXN];

void dfs(int cur, int p=-1) {
    for (pii nxt : adj[cur]) {
        int v = nxt.fi;
        if (v == p) continue;
        dfs(v, cur);
        sma[cur] = max(sma[cur], sma[v]+nxt.se);
    }
}

void dfs2(int cur, int p=-1, ll oma = 0) {
    ma[cur] = max(sma[cur], oma);
    pll p1 = pll(oma, -1), p2 = pll(-INF, -1);

    for (pii nxt : adj[cur]) {
        int v = nxt.fi;
        if (v == p) continue;
        pll p3 = pll(sma[v]+nxt.se, v);
        if (p3 > p1) p2 = p1, p1 = p3;
        else if (p3 > p2) p2 = p3;
    }

    for (pii nxt : adj[cur]) {
        int v = nxt.fi;
        if (v == p) continue;
        ll x = oma;
        if (v == p1.se) x = max(x, p2.fi);
        else x = max(x, p1.fi);
        dfs2(v, cur, x+nxt.se);
    }
}

int subt[MAXN], ans;
vector<pll> stk;

int dfs3(int qi, int cur, int p=-1) {
    stk.push_back(pll(ma[cur], cur));
    subt[cur] = 0;
    int num = 1;
    int v = lower_bound(stk.begin(), stk.end(), pll(ma[cur]-ql[qi], -1))->se;
    subt[v]++;

    for (pii nxt : adj[cur]) {
        if (nxt.fi == p) continue;
        num += dfs3(qi, nxt.fi, cur);
    }
    ans = max(ans, num);
    stk.pop_back();
    return num - subt[cur];
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(pii(b, c));
        adj[b].push_back(pii(a, c));
    }

    cin >> q;
    for (int i=0; i<q; i++) cin >> ql[i];

    dfs(1);
    dfs2(1);

    //for (int i=1; i<=n; i++) cout << ma[i] << endl;

    pll mi = pll(INF, -1);
    for (int i=1; i<=n; i++) mi = min(mi, pll(ma[i], i));

    for (int i=0; i<q; i++) {
        ans = 0;
        dfs3(i, mi.se);
        cout << ans << '\n';
    }
}