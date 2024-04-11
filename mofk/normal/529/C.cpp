#include <bits/stdc++.h>

using namespace std;

int n, m, k, q;
int rooks_x[200005], rooks_y[200005];
int x[200005], y[200005], u[200005], v[200005], ans[200005];

vector <int> updates[100005];
vector <pair <pair <int, int>, pair <int, int> > > queries[100005];
int T[500005];

void upd(int node, int l, int r, int pos, int val) {
    if (l == r) {
        T[node] = val;
        return;
    }
    int m = l + r >> 1;
    if (pos <= m) upd(node * 2, l, m, pos, val);
    else upd(node * 2 + 1, m + 1, r, pos, val);
    T[node] = min(T[node * 2], T[node * 2 + 1]);
}
void upd(int pos, int val) {
    upd(1, 1, 100000, pos, val);
}

int get(int ll, int rr) {
    int ret = 100001;
    queue <pair <pair <int, int>, int> > q;
    q.push(make_pair(make_pair(1, 100000), 1));
    while (!q.empty()) {
        int l = q.front().first.first, r = q.front().first.second, node = q.front().second;
        q.pop();
        if (l > rr || r < ll) continue;
        if (ll <= l && r <= rr) {
            ret = min(ret, T[node]);
            continue;
        }
        int m = l + r >> 1;
        q.push(make_pair(make_pair(l, m), node * 2));
        q.push(make_pair(make_pair(m + 1, r), node * 2 + 1));
    }
    return ret;
}

void make_ans(void) {
    for (int i = 1; i <= 100000; ++i) {
        for (auto A: updates[i]) upd(A, i);
        for (auto Q: queries[i]) {
            if (get(Q.first.first, Q.first.second) >= Q.second.first) ans[Q.second.second] = 1;
        }
    }
}

void solve_row(void) {
    for (int i = 0; i < k; ++i) updates[rooks_x[i]].push_back(rooks_y[i]);
    for (int i = 0; i < q; ++i) queries[u[i]].push_back(make_pair(make_pair(y[i], v[i]), make_pair(x[i], i)));
    make_ans();
}

void solve_column(void) {
    for (int i = 1; i <= 100000; ++i) updates[i].clear(), queries[i].clear();
    memset(T, 0, sizeof T);
    for (int i = 0; i < k; ++i) updates[rooks_y[i]].push_back(rooks_x[i]);
    for (int i = 0; i < q; ++i) queries[v[i]].push_back(make_pair(make_pair(x[i], u[i]), make_pair(y[i], i)));
    make_ans();
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k >> q;
    for (int i = 0; i < k; ++i) cin >> rooks_x[i] >> rooks_y[i];
    for (int i = 0; i < q; ++i) cin >> x[i] >> y[i] >> u[i] >> v[i];
    solve_row();
    solve_column();
    for (int i = 0; i < q; ++i) cout << (ans[i] ? "YES" : "NO") << '\n';
}