#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; ++i)
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;

const int MAXN = 1<<19;

int n, q;
vector<int> adj[MAXN];
int par[MAXN], ent[MAXN], exi[MAXN], cnt;
int tree[4*MAXN], lazy[4*MAXN];

void dfs(int cur, int p=-1) {
    par[cur] = p;
    ent[cur] = cnt++;
    rep(i, adj[cur].size()) {
        int nxt = adj[cur][i];
        if (nxt == p) continue;
        dfs(nxt, cur);
    }
    exi[cur] = cnt++;
}

void down(int cur, int lt, int rt) {
    if (lazy[cur]) {
        tree[cur] = 1;
        if (lt + 1 != rt)
            lazy[2*cur] = lazy[2*cur+1] = 1;
        lazy[cur] = 0;
    }
}

void fill(int cur, int lt, int rt, int ql, int qr) {
    down(cur, lt, rt);
    if (rt <= ql || lt >= qr) return;
    if (lt >= ql && rt <= qr) {
        lazy[cur] = 1;
        down(cur, lt, rt);
    } else {
        int mid = (lt + rt) / 2;
        fill(2*cur, lt, mid, ql, qr);
        fill(2*cur+1, mid, rt, ql, qr);
        tree[cur] = tree[2*cur] && tree[2*cur+1];
    }
}

void empty(int cur, int lt, int rt, int p) {
    down(cur, lt, rt);
    tree[cur] = 0;
    if (lt + 1 != rt) {
        int mid = (lt + rt) / 2;
        if (p < mid) empty(2*cur, lt, mid, p);
        else empty(2*cur+1, mid, rt, p);
    }
}

bool query(int cur, int lt, int rt, int ql, int qr) {
    down(cur, lt, rt);
    if (rt <= ql || lt >= qr) return 1;
    if (lt >= ql && rt <= qr) return tree[cur];
    else {
        int mid = (lt + rt) / 2;
        return query(2*cur, lt, mid, ql, qr) &&
               query(2*cur+1, mid, rt, ql, qr);
    }
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0);

    cin >> q;
    rep(i, q) {
        int c, v;
        cin >> c >> v;
        v--;
        if (c == 1) {
            if (!query(1, 0, 2*n, ent[v], exi[v]+1)) {
                fill(1, 0, 2*n, ent[v], exi[v]+1);
                if (v) empty(1, 0, 2*n, ent[par[v]]);
            }
        } else if (c == 2) empty(1, 0, 2*n, ent[v]);
        else cout << query(1, 0, 2*n, ent[v], exi[v]+1) << '\n';
    }
    return 0;
}