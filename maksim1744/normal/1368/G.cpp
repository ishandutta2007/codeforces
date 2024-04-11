/*
    author:  Maksim1744
    created: 10.05.2021 16:59:33
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
#include "C:/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

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

struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    bool is_mod = false;
    int sm = 0;
};

int last;

Node* build(int l = 0, int r = last - 1) {
    Node* node = new Node();
    if (l == r) return node;
    int m = (l + r) / 2;
    node->left = build(l, m);
    node->right = build(m + 1, r);
    return node;
}

void push(Node *node, int l, int r) {
    if (node->is_mod) {
        node->is_mod = false;
        int m = (l + r) / 2;
        if (node->left) {
            auto was = *node->left;
            node->left = new Node();
            *node->left = was;
            node->left->is_mod = true;
            node->left->sm = m - l + 1;
        }
        if (node->right) {
            auto was = *node->right;
            node->right = new Node();
            *node->right = was;
            node->right->is_mod = true;
            node->right->sm = r - (m + 1) + 1;
        }
    }
}

void update(Node *node) {
    if (!node) return;
    node->sm = 0;
    if (node->left) node->sm += node->left->sm;
    if (node->right) node->sm += node->right->sm;
}

Node* modify(Node *root, int l, int r, int vl = 0, int vr = last - 1) {
    push(root, vl, vr);
    Node* node = new Node();
    node->left = root->left;
    node->right = root->right;
    if (l == vl && r == vr) {
        node->sm = r - l + 1;
        node->is_mod = true;
        return node;
    }
    int m = (vl + vr) / 2;
    if (r <= m) {
        node->left = modify(node->left, l, r, vl, m);
    } else if (m + 1 <= l) {
        node->right = modify(node->right, l, r, m + 1, vr);
    } else {
        node->left = modify(node->left, l, m, vl, m);
        node->right = modify(node->right, m + 1, r, m + 1, vr);
    }
    update(node);
    return node;
}

int ask(Node *node, int l, int r, int vl = 0, int vr = last - 1) {
    push(node, vl, vr);
    if (l == vl && r == vr) {
        return node->sm;
    }
    int m = (vl + vr) / 2;
    if (r <= m) {
        return ask(node->left, l, r, vl, m);
    } else if (m + 1 <= l) {
        return ask(node->right, l, r, m + 1, vr);
    } else {
        return ask(node->left, l, m, vl, m) + ask(node->right, m + 1, r, m + 1, vr);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    cin >> v;

    vector<vector<int>> inds(n, vector<int>(m));
    last = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j] == 'L') {
                inds[i][j] = inds[i][j + 1] = last++;
            }
            if (v[i][j] == 'U') {
                inds[i][j] = inds[i + 1][j] = last++;
            }
        }
    }

    vector<vector<int>> to(n, vector<int>(m, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j] == 'L' && j + 2 < m) to[i][j] = inds[i][j + 2];
            if (v[i][j] == 'R' && j - 2 >= 0) to[i][j] = inds[i][j - 2];
            if (v[i][j] == 'U' && i + 2 < n) to[i][j] = inds[i + 2][j];
            if (v[i][j] == 'D' && i - 2 >= 0) to[i][j] = inds[i - 2][j];
        }
    }

    vector<vector<int>> g(last);

    set<int> frs;
    for (int i = 0; i < last; ++i) {
        frs.insert(i);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ((i + j) % 2 == 0) continue;
            if (to[i][j] == -1) continue;
            g[to[i][j]].pb(inds[i][j]);
            frs.erase(inds[i][j]);
        }
    }

    vector<bool> u(last, false);

    vector<int> ind(last);
    vector<int> L(last);
    vector<int> R(last);
    int tm = 0;

    auto dfs = y_combinator([&](auto dfs, int v) -> void {
        u[v] = true;
        ind[v] = tm++;
        L[v] = R[v] = ind[v];
        for (int k : g[v]) {
            if (!u[k])
                dfs(k);
            L[v] = min(L[v], L[k]);
            R[v] = max(R[v], R[k]);
        }
    });

    for (int i : frs) {
        dfs(i);
    }

    vector<int> to1(last, -1);

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ((i + j) % 2 == 1) continue;
            to1[inds[i][j]] = to[i][j];
        }
    }

    vector<bool> has_ans(last, false);
    auto node0 = build();
    vector<Node*> trees(last, node0);

    auto calc = y_combinator([&](auto calc, int v) -> ll {
        if (!has_ans[v]) {
            if (to1[v] != -1) {
                calc(to1[v]);
                trees[v] = trees[to1[v]];
            }
            trees[v] = modify(trees[v], L[v], R[v]);
        }
        has_ans[v] = true;
        return ask(trees[v], 0, last - 1);
    });

    for (int i = 0; i < last; ++i) {
        ll cur = calc(i);
        ans += cur;
    }

    cout << ans << '\n';

    return 0;
}