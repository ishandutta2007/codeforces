#include <bits/stdc++.h>

using namespace std;

#define A first
#define B second

typedef pair<int, int> pii;

const int maxn = 1<<17;
const int inf = 1e9 + 5;

int t1, t2;
int n, m;
pii P[maxn];

int vsort[2 * maxn], vsze;

vector<int> adj[maxn];

int col[maxn];
vector<int> V[maxn][2]; int vcnt;

void dfs(int v, int c) {
    if (col[v] != -1) {
        if (col[v] != c) {
            cout << "IMPOSSIBLE\n";
            exit(0);
        }
        return;
    }

    col[v] = c;
    V[vcnt][col[v]].push_back(v);
    
    for (int i : adj[v])
        dfs(i, !c);
}

pii T[4 * maxn], L[4 * maxn];

pii merge(pii p1, pii p2) { return pii(max(p1.A, p2.A), min(p1.B, p2.B)); }

void push(int cur, int lt, int rt) {
    if (L[cur].B == inf) return;
    T[cur] = merge(T[cur], L[cur]);
    if (lt + 1 != rt) {
        L[2 * cur] = merge(L[2 * cur], L[cur]);
        L[2 * cur + 1] = merge(L[2 * cur + 1], L[cur]);
    }
    L[cur] = pii(0, inf);
}

void upd(int cur, int lt, int rt, int ql, int qr, pii p) {
    push(cur, lt, rt);
    if (rt <= ql || lt >= qr) return;
    else if (lt >= ql && rt <= qr) {
        L[cur] = p;
        push(cur, lt, rt);
    } else {
        int mid = (lt + rt) / 2;
        upd(2 * cur, lt, mid, ql, qr, p);
        upd(2 * cur + 1, mid, rt, ql, qr, p);
        T[cur] = merge(T[2 * cur], T[2 * cur + 1]);
    }
}

pii qry(int cur, int lt, int rt, int p) {
    push(cur, lt, rt);
    if (lt + 1 == rt) return T[cur];
    else {
        int mid = (lt + rt) / 2;
        if (p < mid) return qry(2 * cur, lt, mid, p);
        else return qry(2 * cur + 1, mid, rt, p);
    }
}

int ind(int x) { return lower_bound(vsort, vsort + vsze, x) - vsort; }

int ans[maxn];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> t1 >> t2 >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> P[i].A >> P[i].B;
        P[i].B++;
        vsort[vsze++] = P[i].A;
        vsort[vsze++] = P[i].B;
    }

    vsort[vsze++] = 0;
    vsort[vsze++] = inf;

    sort(vsort, vsort + vsze);
    vsze = unique(vsort, vsort + vsze) - vsort;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for (int i = 0; i < 4 * maxn; i++)
        T[i] = L[i] = pii(0, inf);

    memset(col, -1, sizeof(col));
    for (int i = 0; i < n; i++)
        if (col[i] == -1) {
            dfs(i, 0);

            pii p1 = pii(0, inf), p2 = pii(0, inf);
            for (int j : V[vcnt][0])
                p1 = merge(p1, P[j]);
            for (int j : V[vcnt][1])
                p2 = merge(p2, P[j]);

            if (p1.A >= p1.B || p2.A >= p2.B) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }

            if (p1.A > p2.A) swap(p1, p2);
            if (p1.B <= p2.A) {
                upd(1, 0, vsze, 0, ind(p1.A), pii(0, 0));
                upd(1, 0, vsze, ind(p1.A), ind(p1.B), p2);
                upd(1, 0, vsze, ind(p1.B), ind(p2.A), pii(0, 0));
                upd(1, 0, vsze, ind(p2.A), ind(p2.B), p1);
                upd(1, 0, vsze, ind(p2.B), vsze, pii(0, 0));
            } else if (p1.B <= p2.B) {
                upd(1, 0, vsze, 0, ind(p1.A), pii(0, 0));
                upd(1, 0, vsze, ind(p1.A), ind(p2.A), p2);
                upd(1, 0, vsze, ind(p2.A), ind(p1.B), pii(p1.A, p2.B));
                upd(1, 0, vsze, ind(p1.B), ind(p2.B), p1);
                upd(1, 0, vsze, ind(p2.B), vsze, pii(0, 0));
            } else {
                upd(1, 0, vsze, 0, ind(p1.A), pii(0, 0));
                upd(1, 0, vsze, ind(p1.A), ind(p2.A), p2);
                upd(1, 0, vsze, ind(p2.A), ind(p2.B), p1);
                upd(1, 0, vsze, ind(p2.B), ind(p1.B), p2);
                upd(1, 0, vsze, ind(p1.B), vsze, pii(0, 0));
            }

            vcnt++;
        }

    for (int i = 0; i < vsze - 1; i++) {
        pii p = qry(1, 0, vsze, i);
        if (p.A >= p.B) continue;
        pii q = pii(t1 - vsort[i + 1] + 1, t2 - vsort[i] + 1);
        pii r = merge(p, q);
        if (r.A >= r.B) continue;

        int a = r.A, b = min(t2 - r.A, vsort[i + 1] - 1);
        assert(vsort[i] <= b && b < vsort[i + 1]);

        for (int j = 0; j < vcnt; j++) {
            bool f = 0;
            for (int k : V[j][0])
                if (!(P[k].A <= a && a < P[k].B)) {
                    f = 1;
                    break;
                }

            for (int k : V[j][!f])
                if (!(P[k].A <= b && b < P[k].B)) {
                    f = !f;
                    break;
                }

            for (int k : V[j][f]) {
                assert(P[k].A <= a && a < P[k].B);
                ans[k] = 1;
            }

            for (int k : V[j][!f]) {
                assert(P[k].A <= b && b < P[k].B);
                ans[k] = 2;
            }
        }

        cout << "POSSIBLE\n";
        cout << a << ' ' << b << '\n';
        for (int j = 0; j < n; j++)
            cout << ans[j];
        cout << '\n';
        return 0;
    }

    cout << "IMPOSSIBLE\n";
}