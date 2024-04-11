#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, u, v, cnt, r, cur = 1, sub[N], op[N], h[N] = {-1};
int col[N], rt[N], in[N];
int se[N], par[N], ch[N];
int up[N];
long long mx, k;
bool rem[N];
vector<int> adj[N], lea[N];
priority_queue<pair<int, int>> pq;

struct segment_tree {
#define lc i * 2
#define rc i * 2 + 1
#define m (l + r) / 2

    int cnt[4 * N];
    bool inv[4 * N];

    void apply(int l, int r, int i) {
        inv[i] = !inv[i];
        cnt[i] = r - l + 1 - cnt[i];
    }

    void down(int l, int r, int i) {
        if (inv[i]) {
            apply(l, m, lc);
            apply(m + 1, r, rc);
            inv[i] = false;
        }
    }

    void update(int l, int r, int i, int L, int R) {
        if (l > R || r < L || L > R) {
            return;
        }
        if (L <= l && r <= R) {
            apply(l, r, i);
            return;
        }
        down(l, r, i);
        update(l, m, lc, L, R);
        update(m + 1, r, rc, L, R);
        cnt[i] = cnt[lc] + cnt[rc];
    }

#undef lc
#undef rc
#undef m
} seg;

int DFS(int u, int p = 0) {
    h[u] = h[p] + 1; op[u] = p; sub[u] = 1;
    for (int v : adj[u]) {
        if (v != p && !rem[v]) {
            sub[u] += DFS(v, u);
        }
    }
    return sub[u];
}

int centroid(int u) {
    for (int v : adj[u]) {
        if (sub[v] < sub[u] && sub[v] > n / 2) {
            return centroid(v);
        }
    }
    return u;
}

void HLD(int u, int p = 0) {
    in[u] = ++cnt; col[u] = cur;
    if (rt[cur] == 0) {
        rt[cur] = u;
    }
    int mc = 0;
    for (int v : adj[u]) {
        if (v != p && sub[v] > sub[mc]) {
            mc = v;
        }
    }
    if (mc > 0) {
        HLD(mc, u);
    }
    for (int v : adj[u]) {
        if (v != p && v != mc) {
            ++cur;
            HLD(v, u);
        }
    }
}

int DFS_2(int u, int p, int rt) {
    int sz = 1;
    ch[u] = 0; se[u] = rt; par[u] = p;
    for (int v : adj[u]) {
        if (v != p) {
            sz += DFS_2(v, u, rt);
            ch[u]++;
        }
    }
    if (ch[u] == 0) {
        lea[rt].push_back(u);
    }
    return sz;
}

void remove(int u) {
    rem[u] = true;
    if (--ch[u = par[u]] == 0) {
        lea[se[u]].push_back(u);
    }
}

void update(int u, int v) {
    while (col[u] != col[v]) {
        if (h[rt[col[u]]] < h[rt[col[v]]]) {
            swap(u, v);
        }
        seg.update(1, n, 1, in[rt[col[u]]], in[u]);
        u = op[rt[col[u]]];
    }
    if (h[u] > h[v]) {
        swap(u, v);
    }
    seg.update(1, n, 1, in[u] + 1, in[v]);
}

vector<int> match(int u, int p = 0) {
    vector<int> ans = {u}, tmp;
    sort(adj[u].begin(), adj[u].end(), [](const int u, const int v) {
        return up[u] > up[v];
    });
    for (int v : adj[u]) {
        if (v != p && !rem[v]) {
            tmp = match(v, u);
            while (ans.size() + tmp.size() - 2 >= up[u] && !ans.empty() && !tmp.empty()) {
                cout << ans.back() << " " << tmp.back() << '\n';
                ans.pop_back();
                tmp.pop_back();
            }
            while (!tmp.empty()) {
                ans.push_back(tmp.back());
                tmp.pop_back();
            }
        }
    }
    assert(ans.size() == up[u]);
    return ans;
}

void end_game(int lst) {
    DFS(r);
    vector<pair<int, int>> ve;
    for (int i = 1; i <= n; i++) {
        if (!rem[i]) {
            up[i] = sub[i] % 2;
            k -= up[i];
            if (sub[i] > 1 && sub[i] < lst - 1) {
                ve.push_back({sub[i] % 2, i});
            }
        }
    }
    sort(ve.begin(), ve.end());
    for (int i = 0; i < k / 2; i++) {
        up[ve[i].second] += 2;
    }
    match(r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    r = centroid(1);
    DFS(r);
    HLD(r);
    for (int i = 1; i <= n; i++) {
        if (sub[i] & 1) {
            seg.update(1, n, 1, in[i], in[i]);
        }
        mx += min(sub[i], n - sub[i]);
    }
    if (k < seg.cnt[1] || k > mx || k % 2 != mx % 2) {
        return cout << "NO\n", 0;
    }
    cout << "YES\n";
    for (int v : adj[r]) {
        pq.push({DFS_2(v, r, v), v});
    }
    for (int it = 1; it <= n / 2; it++) {
        auto [sf, vf] = pq.top(); pq.pop();
        int lf = lea[vf].back(); lea[vf].pop_back();
        if (it < n / 2) {
            auto [ss, vs] = pq.top(); pq.pop();
            int ls = lea[vs].back(); lea[vs].pop_back();
            update(lf, ls);
            if (k - h[lf] - h[ls] >= seg.cnt[1]) {
                k -= h[lf] + h[ls];
                remove(ls);
                pq.push({ss - 1, vs});
                cout << lf << " " << ls << '\n';
            } else {
                update(lf, ls);
                end_game(n - (it - 1) * 2);
                return 0;
            }
        } else {
            cout << lf << " " << r << '\n';
        }
        remove(lf);
        pq.push({sf - 1, vf});
    }
}