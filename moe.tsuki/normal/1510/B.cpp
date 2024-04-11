#include <bits/stdc++.h>
using namespace std;

class MCMF {
    using Cap = int;
    using Wei = int64_t;
    using PCW = pair<Cap, Wei>;
    static constexpr Cap INF_CAP = 1 << 30;
    static constexpr Wei INF_WEI = 1LL<<60;
    struct E {
        int to, back;
        Cap cap;
        Wei wei;
        E() {}
        E(int a, int b, Cap c, Wei d)
            : to(a), back(b), cap(c), wei(d) {}
    };
    int ori, edd;
    vector<vector<E>> G;
    vector<int> fa, wh;
    vector<bool> inq;
    vector<Wei> dis;
    vector<pair<int, int>> egs;
    PCW SPFA() {
        fill(inq.begin(), inq.end(), false);
        fill(dis.begin(), dis.end(), INF_WEI);
        queue<int> qq;
        qq.push(ori);
        dis[ori] = 0;
        while (not qq.empty()) {
            int u = qq.front();
            qq.pop();
            inq[u] = false;
            for (int i = 0; i < int(G[u].size()); ++i) {
                E e = G[u][i];
                int v = e.to;
                Wei d = e.wei;
                if (e.cap <= 0 or dis[v] <= dis[u] + d)
                    continue;
                dis[v] = dis[u] + d;
                fa[v] = u;
                wh[v] = i;
                if (inq[v]) continue;
                qq.push(v);
                inq[v] = true;
            }
        }
        if (dis[edd] == INF_WEI) return {-1, -1};
        Cap mw = INF_CAP;
        for (int i = edd; i != ori; i = fa[i])
            mw = min(mw, G[fa[i]][wh[i]].cap);
        for (int i = edd; i != ori; i = fa[i]) {
            auto &e = G[fa[i]][wh[i]];
            e.cap -= mw;
            G[e.to][e.back].cap += mw;
        }
        return {mw, dis[edd]};
    }
public:
    void init(int n) {
        G.clear();
        G.resize(n);
        fa.resize(n);
        wh.resize(n);
        inq.resize(n);
        dis.resize(n);
        egs.clear();
    }
    void add_edge(int st, int ed, Cap c, Wei w) {
        //cout << st << "->" << ed << ": " << c << ", " << w << '\n';
        G[st].emplace_back(ed, int(G[ed].size()), c, w);
        G[ed].emplace_back(st, int(G[st].size()) - 1, 0, -w);
        egs.emplace_back(ed, int(G[ed].size()) - 1);
    }
    PCW solve(int a, int b) {
        //cout << "> solve " << a << ", " << b << '\n';
        ori = a; edd = b;
        Cap cc = 0;
        Wei ww = 0;
        while (true) {
            PCW ret = SPFA();
            if (ret.first == -1) break;
            cc += ret.first;
            ww += ret.first * ret.second;
        }
        return {cc, ww};
    }
    Cap get_cap(int eid) const {
        return G[egs[eid].first][egs[eid].second].cap;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int d, n; cin >> d >> n;
    const int d2 = 1 << d;
    vector<bool> has(d2);
    vector<int> idx(d2);
    vector<int> inv(n);
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        int x = 0;
        for (int j = 0; j < d; ++j)
            x = x * 2 + (s[j] - '0');
        has[x] = true;
        idx[x] = i;
        inv[i] = x;
    }

    struct E {
        int fr, to, lb, ub, cost;
    };
    const int O0 = 2 * n, T = 2 * n + 1, O1 = 2 * n + 2;
    static constexpr int INF = 1 << 30;
    vector<E> es;
    for (int S = d2 - 1; S > 0; --S) {
        if (not has[S]) continue;
        es.push_back({O1, idx[S] * 2, 0, 1, 0});
        es.push_back({idx[S] * 2, idx[S] * 2 + 1, 1, 1, 0});
        es.push_back({idx[S] * 2 + 1, T, 0, 1, __builtin_popcount(S) + 1});
        for (int x = (S - 1) & S; x > 0; x = (x - 1) & S) {
            if (not has[x]) continue;
            assert((x & S) == x);
            es.push_back({idx[x] * 2 + 1, idx[S] * 2, 0, 1, 0});
        }
    }
    es.push_back({O0, O1, n, n, 0});
    es.push_back({O1, T, 0, n, 0});

    const int OO = 2 * n + 3, TT = 2 * n + 4;
    vector<int> in(2 * n + 3);
    MCMF mcmf;
    mcmf.init(2 * n + 5);
    for (const auto &e: es) {
        //cout << e.fr << " -> " << e.to << ": " << e.lb << "~" << e.ub << ", " << e.cost << '\n';
        mcmf.add_edge(e.fr, e.to, e.ub - e.lb, e.cost);
        in[e.to] += e.lb;
        in[e.fr] -= e.lb;
    }
    int s = 0;
    for (int i = 0; i < 2 * n + 3; ++i) {
        if (in[i] > 0) {
            s += in[i];
            mcmf.add_edge(OO, i, in[i], 0);
        } else {
            mcmf.add_edge(i, TT, -in[i], 0);
        }
    }
    mcmf.add_edge(T, O0, INF, 0);
    auto [c0, w0] = mcmf.solve(OO, TT);
    assert(c0 == s);
    auto [c1, w1] = mcmf.solve(O0, T);
    cout << w0 + w1 - 1 << '\n';
    vector<vector<int>> g(2 * n + 3);
    for (int i = 0; i < int(es.size()); ++i) {
        const auto &e = es[i];
        int f = mcmf.get_cap(i);
        if (f + e.lb > 0)
            g[e.fr].push_back(e.to);
    }
    vector<int> ans;
    for (int x: g[O1]) {
        int u = x;
        while (u != T) {
            assert(g[u].size() == 1);
            if (u & 1) ans.push_back(u >> 1);
            u = g[u][0];
        }
        ans.push_back(-1);
    }
    while (ans.back() == -1)
        ans.pop_back();
    int la = 0;
    for (size_t i = 0; i < ans.size(); ++i) {
        if (ans[i] == -1) {
            cout << 'R';
            la = 0;
        } else {
            int cb = la ^ inv[ans[i]];
            vector<int> bs;
            for (int j = 0; j < d; ++j)
                if ((cb >> j) & 1) bs.push_back(d - j - 1);
            for (size_t j = 0; j < bs.size(); ++j) {
                cout << (j ? " " : "") << bs[j];
            }
            la = inv[ans[i]];
        }
        cout << " \n"[i + 1 == ans.size()];
    }
    return 0;
}