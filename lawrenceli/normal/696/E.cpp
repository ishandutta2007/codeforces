#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define A first
#define B second

typedef long long ll;

const int maxn = 1<<17;
const int maxlg = 17;
const ll inf = 1e18;

int n, m, q;
vector<int> adj[maxn];
vector<int> V[maxn]; int vp[maxn];

int jump[maxn][maxlg];
int dep[maxn], ent[maxn], exi[maxn], cnt, sub[maxn];

void dfs(int v, int p = -1) {
    jump[v][0] = p == -1 ? v : p;
    dep[v] = p == -1 ? 0 : dep[p] + 1;
    ent[v] = cnt++;
    sub[v] = 1;
    for (int i : adj[v])
        if (i != p) {
            dfs(i, v);
            sub[v] += sub[i];
        }
    exi[v] = cnt++;
}

void initlca() {
    for (int k = 0; k < maxlg - 1; k++)
        for (int i = 1; i <= n; i++)
            jump[i][k + 1] = jump[jump[i][k]][k];
}

int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    for (int k = maxlg - 1; k >= 0; k--)
        if (dep[jump[b][k]] >= dep[a])
            b = jump[b][k];
    if (a == b) return a;
    for (int k = maxlg - 1; k >= 0; k--)
        if (jump[a][k] != jump[b][k])
            a = jump[a][k], b = jump[b][k];
    return jump[a][0];
}

vector<vector<int> > chain;
vector<vector<pair<ll, int> > > T;
vector<vector<ll> > L;
int ind[maxn], cmp[maxn];

void dfs2(int v, int p = -1) {
    if (ind[v] == -1) {
        ind[v] = 0, cmp[v] = chain.size();
        chain.push_back(vector<int>());
        chain.back().push_back(v);
    }

    for (int i : adj[v])
        if (i != p) {
            if (sub[i] > sub[v] / 2) {
                cmp[i] = cmp[v];
                ind[i] = chain[cmp[i]].size();
                chain[cmp[i]].push_back(i);
            }
            dfs2(i, v);
        }
}

ll bit[2 * maxn];

void upd(int i, ll v) {
    for (i++; i < 2 * maxn; i += i & -i) bit[i] += v;
}

ll qry(int i) {
    ll ret = 0;
    for (i++; i > 0; i -= i & -i) ret += bit[i];
    return ret;
}

pair<ll, int> min(pair<ll, int> p1, pair<ll, int> p2) {
    return p1 < p2 ? p1 : p2;
}

void init(int c, int cur, int lt, int rt) {
    if (lt + 1 == rt) {
        int x = chain[c][lt];
        //cout << x << ' ' << V[x].size() << ' ' << V[x][0] << endl;
        if (V[x].size()) T[c][cur] = MP(V[x][0], x);
    } else {
        int mid = (lt + rt) / 2;
        init(c, 2 * cur, lt, mid);
        init(c, 2 * cur + 1, mid, rt);
        T[c][cur] = min(T[c][2 * cur], T[c][2 * cur + 1]);
        //cout << lt << ' ' << rt << ' ' << T[c][cur].A << ' ' << T[c][cur].B << endl;
    }
}

void push(int c, int cur, int lt, int rt) {
    if (!L[c][cur]) return;
    T[c][cur].A += L[c][cur];
    if (lt + 1 != rt) {
        L[c][2 * cur] += L[c][cur];
        L[c][2 * cur + 1] += L[c][cur];
    }
    L[c][cur] = 0;
}

void upd(int c, int cur, int lt, int rt, int ql, int qr, ll v) {
    push(c, cur, lt, rt);
    if (rt <= ql || lt >= qr) return;
    else if (lt >= ql && rt <= qr) {
        L[c][cur] = v;
        push(c, cur, lt, rt);
    } else {
        int mid = (lt + rt) / 2;
        upd(c, 2 * cur, lt, mid, ql, qr, v);
        upd(c, 2 * cur + 1, mid, rt, ql, qr, v);
        T[c][cur] = min(T[c][2 * cur], T[c][2 * cur + 1]);
    }
}

void updp(int c, int cur, int lt, int rt, int p, ll v) {
    if (lt + 1 == rt) T[c][cur].A += v;
    else {
        int mid = (lt + rt) / 2;
        push(c, 2 * cur, lt, mid);
        push(c, 2 * cur + 1, mid, rt);
        if (p < mid) updp(c, 2 * cur, lt, mid, p, v);
        else updp(c, 2 * cur + 1, mid, rt, p, v);
        T[c][cur] = min(T[c][2 * cur], T[c][2 * cur + 1]);
    }
}

pair<ll, int> qry(int c, int cur, int lt, int rt, int ql, int qr) {
    //cout << lt << ' ' << rt << ' ' << ql << ' ' << qr << ' ' << L[c][cur] << endl;
    push(c, cur, lt, rt);
    if (rt <= ql || lt >= qr) return MP(inf, 0);
    else if (lt >= ql && rt <= qr) return T[c][cur];
    else {
        int mid = (lt + rt) / 2;
        return min(qry(c, 2 * cur, lt, mid, ql, qr), qry(c, 2 * cur + 1, mid, rt, ql, qr));
    }
}

pair<ll, int> qclimb(int a, int b) {
    pair<ll, int> ret = MP(inf, 0);
    while (a) {
        int h = chain[cmp[a]][0];
        int p = h == 1 ? 0 : jump[h][0];
        ll v = p ? qry(ent[p]) : 0;
        if (cmp[a] == cmp[b]) {
            pair<ll, int> res = qry(cmp[a], 1, 0, chain[cmp[a]].size(), ind[b] + 1, ind[a] + 1);
            res = MP(res.A + v, res.B);
            ret = min(ret, res);
            break;
        } else {
            pair<ll, int> res = qry(cmp[a], 1, 0, chain[cmp[a]].size(), 0, ind[a] + 1);
            res = MP(res.A + v, res.B);
            ret = min(ret, res);
        }
        a = p;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> q;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= m; i++) {
        int c; cin >> c;
        V[c].push_back(i);
    }

    for (int i = 1; i <= n; i++) sort(V[i].begin(), V[i].end());

    dfs(1);
    initlca();
    memset(ind, -1, sizeof(ind));
    dfs2(1);

    //for (int i = 1; i <= n; i++) cout << cmp[i] << ' ' << ind[i] << endl;

    T.resize(chain.size(), vector<pair<ll, int> >());
    L.resize(chain.size(), vector<ll>());
    for (int i = 0; i < chain.size(); i++) {
        T[i].resize(4 * chain[i].size(), MP(inf, 0));
        L[i].resize(4 * chain[i].size(), 0);
        init(i, 1, 0, chain[i].size());
    }

    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        if (t == 1) {
            int a, b, k;
            cin >> a >> b >> k;
            int c = lca(a, b);
            vector<int> v;
            while (k--) {
                int p = c == 1 ? 0 : jump[c][0];
                pair<ll, int> x = min(qclimb(a, p), qclimb(b, p));
                if (x.B == 0) break;
                v.push_back(V[x.B][vp[x.B]++]);
                if (vp[x.B] < V[x.B].size()) updp(cmp[x.B], 1, 0, chain[cmp[x.B]].size(), ind[x.B], V[x.B][vp[x.B]] - V[x.B][vp[x.B] - 1]);
                else updp(cmp[x.B], 1, 0, chain[cmp[x.B]].size(), ind[x.B], inf);
            }

            cout << v.size() << ' ';
            for (int j : v) cout << j << ' ';
            cout << '\n';
        } else {
            int v, k;
            cin >> v >> k;
            upd(cmp[v], 1, 0, chain[cmp[v]].size(), ind[v], chain[cmp[v]].size(), k);
            upd(ent[v], k);
            upd(exi[v], -k);
        }
    }
}