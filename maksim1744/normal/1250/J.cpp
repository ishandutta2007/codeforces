/*
    author:  Maksim1744
    created: 06.05.2021 16:01:27
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
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

const int B = 20;

struct Node {
    Node* to[2];
    int sz = 0;
    int mod = 0;
    int def0 = (1 << B) - 1;
    int def1 = (1 << B) - 1;
    Node() {
        to[0] = nullptr;
        to[1] = nullptr;
    }
};

ostream &operator << (ostream &o, const Node &n) {
    return o << "[sz=" << n.sz << ", mod=" << n.mod
            << ", def0=" << n.def0 << ", def1=" << n.def1 << "]";
}

void add_num(Node *node, int x) {
    for (int i = 0; i < B; ++i) {
        node->sz++;
        node->def1 &= x;
        node->def0 &= ((1 << B) - 1) ^ x;
        int b = ((x >> (B - i - 1)) & 1);
        if (!node->to[b]) {
            node->to[b] = new Node();
        }
        node = node->to[b];
    }
    node->sz++;
    node->def1 &= x;
    node->def0 &= ((1 << B) - 1) ^ x;
}

void update(Node *node, int level) {
    if (!node) return;
    node->sz = 0;
    if (node->to[0]) node->sz += node->to[0]->sz;
    if (node->to[1]) node->sz += node->to[1]->sz;
    node->def0 = (1 << B) - 1;
    node->def1 = (1 << B) - 1;
    if (node->to[0]) {
        node->def0 &= node->to[0]->def0;
        node->def1 &= node->to[0]->def1;
    }
    if (node->to[1]) {
        node->def0 &= node->to[1]->def0;
        node->def1 &= node->to[1]->def1;
    }
    if (!node->to[0])
        node->def1 |= (1 << (B - level - 1));
    if (!node->to[1])
        node->def0 |= (1 << (B - level - 1));
}

void modify(Node *node, int x) {
    if (!node) return;
    node->mod ^= x;
    int mask = (x & (node->def0 | node->def1));
    node->def0 ^= mask;
    node->def1 ^= mask;
}

void push(Node *node, int level) {
    if (!node) {
        return;
    }
    if ((node->mod >> (B - level - 1)) & 1) {
        swap(node->to[0], node->to[1]);
    }
    modify(node->to[0], node->mod);
    modify(node->to[1], node->mod);
    node->mod = 0;
}

pair<Node*, Node*> split(Node *node, int m, int l = 0, int r = (1 << B) - 1, int level = 0) {
    push(node, level);
    if (!node) return {nullptr, nullptr};
    if (r <= m) return {node, nullptr};
    if (l >  m) return {nullptr, node};
    int mid = (l + r) / 2;
    auto L = new Node();
    auto R = new Node();
    if (mid < m) {
        auto [a, b] = split(node->to[1], m, mid + 1, r, level + 1);
        if (b) {
            R->to[1] = b;
        } else {
            R = nullptr;
        }
        if (node->to[0] || a) {
            L->to[0] = node->to[0];
            L->to[1] = a;
        } else {
            L = nullptr;
        }
        update(L, level);
        update(R, level);
        return {L, R};
    } else {
        auto [a, b] = split(node->to[0], m, l, mid, level + 1);
        if (node->to[1] || b) {
            R->to[0] = b;
            R->to[1] = node->to[1];
        } else {
            R = nullptr;
        }
        if (a) {
            L->to[0] = a;
        } else {
            L = nullptr;
        }
        update(L, level);
        update(R, level);
        return {L, R};
    }
}

Node* mrg(Node *a, Node *b, int level) {
    if (!a) return b;
    if (!b) return a;
    if (level == B) {
        assert(a->sz == 1 && b->sz == 1);
        return a;
    }
    Node *root = a;
    push(a, level);
    push(b, level);
    a->to[0] = mrg(a->to[0], b->to[0], level + 1);
    a->to[1] = mrg(a->to[1], b->to[1], level + 1);
    update(root, level);
    return root;
}

tuple<Node*, Node*, Node*> cut(Node *root, int l, int r) {
    auto [a, bc] = split(root, l - 1);
    auto [b, c] = split(bc, r);
    return {a, b, c};
}

Node* merge3(Node *a, Node *b, Node *c) {
    return mrg(mrg(a, b, 0), c, 0);
}

void push_or_bit(Node *node, int b, int level) {
    if (!node) return;
    push(node, level);
    if (level == B - b - 1) {
        modify(node->to[0], 1 << b);
        node->to[1] = mrg(node->to[0], node->to[1], level + 1);
        node->to[0] = nullptr;
        update(node, level);
        return;
    }
    if ((node->def1 >> b) & 1) {
        return;
    }
    if ((node->def0 >> b) & 1) {
        modify(node, 1 << b);
        return;
    }
    push_or_bit(node->to[0], b, level + 1);
    push_or_bit(node->to[1], b, level + 1);
    update(node, level);
}

void push_or(Node *root, int x) {
    for (int b = 0; b < B; ++b) {
        if ((x >> b) & 1) {
            push_or_bit(root, b, 0);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    Node *root = new Node();

    auto call_xor = [&](int l, int r, int x) {
        auto [a, b, c] = cut(root, l, r);
        modify(b, x);
        root = merge3(a, b, c);
    };

    auto call_or = [&](int l, int r, int x) {
        auto [a, b, c] = cut(root, l, r);
        push_or(b, x);
        root = merge3(a, b, c);
    };

    auto call_ask = [&](int l, int r) {
        auto [a, b, c] = cut(root, l, r);
        int res = (b ? b->sz : 0);
        return res;
    };

    auto call_and = [&](int l, int r, int x) {
        call_xor(0, (1 << B) - 1, (1 << B) - 1);
        call_or(r ^ ((1 << B) - 1), l ^ ((1 << B) - 1), ((1 << B) - 1) ^ x);
        call_xor(0, (1 << B) - 1, (1 << B) - 1);
    };

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    cin >> a;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();
    for (int k : a) {
        add_num(root, k);
    }


    while (q--) {
        int tp, l, r, x;
        cin >> tp >> l >> r;
        if (tp != 4) cin >> x;
        if (tp == 1) {
            call_and(l, r, x);
        } else if (tp == 2) {
            call_or(l, r, x);
        } else if (tp == 3) {
            call_xor(l, r, x);
        } else if (tp == 4) {
            cout << call_ask(l, r) << '\n';
        } else {
            assert(false);
        }
    }

    return 0;
}