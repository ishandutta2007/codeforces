/*
    author:  Maksim1744
    created: 29.08.2021 19:17:38
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "/mnt/c/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

struct Node {
    array<Node*, 2> to = {nullptr, nullptr};
    int ind = -1;
    int lvl;
    ll val;

    Node(int lvl, ll val = 0) : lvl(lvl), val(val) {};
};

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
// auto gcd = std::y_combinator([](auto gcd, int a, int b) -> int {
//     return b == 0 ? a : gcd(b, a % b);
// });

struct DSU {
    vector<int> rk;
    vector<int> p;
    vector<int> right;
    int n;

    DSU(int n = 1) : n(n) {
        reset(n);
    }

    void reset(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        right = p;
        rk.assign(n, 1);
    }

    int par(int v) {
        return v == p[v] ? v : p[v] = par(p[v]);
    }

    bool un(int u, int v) {
        u = par(u);
        v = par(v);
        if (u == v) return false;
        if (rk[u] > rk[v]) swap(u, v);
        p[u] = v;
        rk[v] += rk[u];
        right[v] = max(right[u], right[v]);
        return true;
    }

    bool check(int u, int v) {
        return par(u) == par(v);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int B, m;
    cin >> B >> m;

    Node* root = new Node(0);
    auto push = [&](ll val) {
        if (val == (1ll << B)) return;
        auto node = root;
        for (int b = B - 1; b >= 0; --b) {
            int x = (val >> b) & 1;
            if (!node->to[x]) {
                node->to[0] = new Node(node->lvl + 1, node->val);
                node->to[1] = new Node(node->lvl + 1, node->val | (1ll << (B - node->lvl - 1)));
            }
            node = node->to[x];
        }
    };

    vector<pair<string, pair<ll, ll>>> v(m);
    cin >> v;
    vector<pair<ll, ll>> al;
    push(0);
    al.eb(-1, -1);
    for (int i = 0; i < m; ++i) {
        if (v[i].first == "block") {
            auto [l, r] = v[i].second;
            al.eb(l, r);
            push(l);
            push(r + 1);
        }
    }
    sort(al.begin(), al.end());
    al.eb((1ll << B), (1ll << B));
    show(al);

    vector<Node*> nodes;
    y_combinator([&](auto dfs, Node* node) -> void {
        if (!node) return;
        if (node->to[0]) {
            dfs(node->to[0]);
            dfs(node->to[1]);
        } else {
            node->ind = nodes.size();
            nodes.eb(node);
        }
    })(root);

    sort(nodes.begin(), nodes.end(), [&](const Node* a, const Node* b) {
        return a->val < b->val;
    });

    vector<vector<int>> g(nodes.size());

    auto conn = [&](Node* a, Node* b) {
        if (a->ind == -1 || b->ind == -1) return;
        g[a->ind].pb(b->ind);
        g[b->ind].pb(a->ind);
    };

    for (auto node : nodes) {
        auto nd = root;
        for (int b = B - 1, k = node->lvl; k > 0; --b, --k) {
            conn(nd, node);
            int x = (node->val >> b) & 1;
            nd = nd->to[x];
            assert(nd);
        }
        for (int b = B - node->lvl; b < B; ++b) {
            ll v2 = node->val ^ (1ll << b);
            auto nd = root;
            for (int b = B - 1, k = node->lvl; k >= 0; --b, --k) {
                conn(nd, node);
                int x = (v2 >> b) & 1;
                nd = nd->to[x];
                if (!nd) break;
            }
        }
    }

    DSU d(g.size());
    vector<int> u(g.size(), false);

    DSU d2(g.size());

    auto unblock = [&](ll l, ll r) {
        if (l > r) return;
        show(l, r);
        // #warning faster
        // for (auto node : nodes) {
        //     if (l <= node->val && node->val <= r && node->ind != -1) {
        //         u[node->ind] = true;
        //         for (int k : g[node->ind]) {
        //             if (u[k] && u[node->ind])
        //                 d.un(k, node->ind);
        //         }
        //     }
        // }
        int ind = -1;
        {
            int L = -1, R = nodes.size();
            while (R - L > 1) {
                int C = (L + R) / 2;
                if (nodes[C]->val < l)
                    L = C;
                else
                    R = C;
            }
            ind = R;
        }
        assert(ind < nodes.size() && nodes[ind]->val == l);
        while (true) {
            ind = d2.right[d2.par(ind)];
            if (!u[ind]) {
                u[ind] = true;
                for (int k : g[nodes[ind]->ind]) {
                    if (u[k])
                        d.un(k, nodes[ind]->ind);
                }
            }
            ind = d2.right[d2.par(ind)];
            if (ind + 1 < nodes.size() && nodes[ind + 1]->val <= r) {
                d2.un(ind, ind + 1);
                ++ind;
            } else {
                break;
            }
        }
    };
    for (int i = 0; i + 1 < al.size(); ++i) {
        unblock(al[i].second + 1, al[i + 1].first - 1);
    }

    show(g);
    show(v);
    for (int i = 0; i < g.size(); ++i) {
        show(nodes[i]->ind, nodes[i]->val, nodes[i]->lvl);
    }

    vector<int> ans;

    for (int i = m - 1; i >= 0; --i) {
        if (v[i].first == "block") {
            auto [l, r] = v[i].second;
            unblock(l, r);
        } else {
            debug {
                for (int i = 0; i < d.n; ++i) {
                    int par = d.par(i);
                    cerr << par << ' ';
                }
                cerr << endl;
            }
            show(u);
            auto [x, y] = v[i].second;
            auto get_node = [&](ll val) {
                auto node = root;
                for (int b = B - 1; b >= 0; --b) {
                    int x = (val >> b) & 1;
                    if (!node->to[x]) {
                        return node;
                    }
                    node = node->to[x];
                }
                return node;
            };

            auto n1 = get_node(x);
            auto n2 = get_node(y);
            assert(n1->ind != -1);
            assert(n2->ind != -1);
            show(n1->ind, n2->ind);
            int res = d.check(n1->ind, n2->ind);
            show(x, y, res);
            ans.pb(res);
        }
    }

    reverse(ans.begin(), ans.end());
    for (int k : ans)
        cout << k << '\n';

    return 0;
}