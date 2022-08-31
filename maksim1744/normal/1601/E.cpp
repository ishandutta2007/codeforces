/*
    author:  Maksim1744
    created: 02.11.2021 15:04:29
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
#include "/mnt/c/Libs/tools/print.cpp"
#else
#define show(...) void(0)
#define debugf(fun)   fun
#define debugv(var)   var
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

template<typename T, typename F = std::function<T(const T&, const T&)>>
struct SparseTable {
    vector<vector<T>> table;
    vector<int> p2;
    F combine;

    SparseTable(int n, F combine) : combine(combine) {
        while ((1 << table.size()) <= n || table.empty())
            table.emplace_back(n);
    }
    template<typename U>
    SparseTable(const vector<U>& v, F combine) : SparseTable<T>(v.size(), combine) {
        table[0].assign(v.begin(), v.end());
        build();
    }

    void build() {
        p2.resize(table[0].size() + 1);
        for (int i = 2; i < p2.size(); ++i)
            p2[i] = p2[i / 2] + 1;
        for (int i = 1; i < table.size(); ++i) {
            for (int j = 0; j + (1 << i) <= table[i].size(); ++j) {
                table[i][j] = combine(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T ask(int l, int r) {
        int ln = p2[r - l + 1];
        if (r - l + 1 == ln) return table[ln][l];
        return combine(table[ln][l], table[ln][r - (1 << ln) + 1]);
    }
};

struct item {
    ll sm = 0;
    ll mod = 0;

    template<typename T>
    void init(const T &t, int l, int r) {
        sm = t;
        mod = 0;
    }

    void update(const item &first, const item &second, int l, int r) {
        sm = first.sm + second.sm;
    }

    static item merge(const item &first, const item &second, int l, int r) {
        item res;
        res.update(first, second, l, r);  // careful with different lengths
        return res;
    }

    template<typename Modifier>
    void modify(const Modifier &m, int l, int r) {
        // apply here, save for children
        mod += m;
        sm += (ll)m * (r - l + 1);
    }

    void push(item &first, item &second, int l, int r) {
        int m = (l + r) / 2;
        first.modify(mod, l, m);
        second.modify(mod, m + 1, r);
        // reset modifier
        mod = 0;
    }
};

string to_string(const item &i) {
    stringstream ss;
    ss << "[" << "]";
    return ss.str();
}
ostream& operator << (ostream &o, const item &i) {
    return o << to_string(i);
}

struct segtree {
    vector<item> tree;
    int n = 1;

    segtree(int n = 1) : n(n) {
        tree.resize(1 << (__lg(max(1, n - 1)) + 2));
    }

    template<typename T>
    void build(const vector<T> &v, int i, int l, int r) {
        if (l == r) {
            tree[i].init(v[l], l, r);
            return;
        }
        int m = (l + r) >> 1;
        build(v, i * 2 + 1, l, m);
        build(v, i * 2 + 2, m + 1, r);
        tree[i].update(tree[i * 2 + 1], tree[i * 2 + 2], l, r);
    }

    template<typename T>
    void build(const vector<T> &v) {
        n = v.size();
        tree.resize(1 << (__lg(max(1, n - 1)) + 2));
        build(v, 0, 0, n - 1);
    }

    item ask(int l, int r, int i, int vl, int vr) {
        if (vl != vr) {
            tree[i].push(tree[i * 2 + 1], tree[i * 2 + 2], vl, vr);
        }
        if (l == vl && r == vr) {
            return tree[i];
        }
        int m = (vl + vr) >> 1;
        if (r <= m) {
            return ask(l, r, i * 2 + 1, vl, m);
        } else if (m < l) {
            return ask(l, r, i * 2 + 2, m + 1, vr);
        } else {
            return item::merge(ask(l, m, i * 2 + 1, vl, m), ask(m + 1, r, i * 2 + 2, m + 1, vr), l, r);
        }
    }

    item ask(int l, int r) {
        l = max(l, 0); r = min(r, n - 1);
        if (l > r) return item();
        return ask(l, r, 0, 0, n - 1);
    }

    template<typename T>
    void set(int ind, const T &t) {
        static array<pair<int, int>, 30> st;
        int l = 0, r = n - 1, i = 0;
        int ptr = -1;
        while (l != r) {
            if (l != r) {
                tree[i].push(tree[i * 2 + 1], tree[i * 2 + 2], l, r);
            }
            st[++ptr] = {l, r};
            int m = (l + r) >> 1;
            if (ind <= m) {
                i = i * 2 + 1;
                r = m;
            } else {
                i = i * 2 + 2;
                l = m + 1;
            }
        }
        tree[i].init(t, l, r);
        while (i != 0) {
            i = (i - 1) / 2;
            tree[i].update(tree[i * 2 + 1], tree[i * 2 + 2], st[ptr].first, st[ptr].second);
            --ptr;
        }
    }

    template<typename Modifier>
    void modify(int l, int r, const Modifier &modifier, int i, int vl, int vr) {
        if (vl != vr) {
            tree[i].push(tree[i * 2 + 1], tree[i * 2 + 2], vl, vr);
        }
        if (l == vl && r == vr) {
            tree[i].modify(modifier, vl, vr);
            return;
        }
        int m = (vl + vr) >> 1;
        if (r <= m) {
            modify(l, r, modifier, i * 2 + 1, vl, m);
        } else if (m < l) {
            modify(l, r, modifier, i * 2 + 2, m + 1, vr);
        } else {
            modify(l, m, modifier, i * 2 + 1, vl, m);
            modify(m + 1, r, modifier, i * 2 + 2, m + 1, vr);
        }
        tree[i].update(tree[i * 2 + 1], tree[i * 2 + 2], vl, vr);
    }

    template<typename Modifier>
    void modify(int l, int r, const Modifier &modifier) {
        l = max(l, 0); r = min(r, n - 1);
        if (l > r) return;
        modify(l, r, modifier, 0, 0, n - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q, k;
    cin >> n >> q >> k;
    vector<int> a(n);
    cin >> a;
    SparseTable<ll> sp(a, [](ll a, ll b){ return min(a, b); });

    struct que {
        int l, r;
        int i;
    };
    vector<ll> ans(q);
    vector<que> ques(q);
    for (int i = 0; i < q; ++i) {
        cin >> ques[i].l >> ques[i].r;
        ques[i].i = i;
        --ques[i].l;
        --ques[i].r;
    }
    sort(ques.begin(), ques.end(), [&](const auto& a, const auto& b) {
        return a.l > b.l;
    });
    int curl = n;
    vector<vector<pair<int, int>>> st(k);
    vector<segtree> trees(k);
    vector<int> sz(k);
    for (int i = 0; i < n; ++i) {
        sz[i % k]++;
    }
    for (int i = 0; i < k; ++i) {
        st[i].eb(sz[i], -1);
    }
    for (int i = 0; i < k; ++i) {
        trees[i] = segtree(sz[i]);
    }
    for (auto q : ques) {
        shows;
        shows;
        shows;
        while (curl > q.l) {
            --curl;
            int newmin = sp.ask(curl, min(n - 1, curl + k));
            int ik = curl % k;
            int loci = curl / k;
            int last = loci + 1;
            show(curl, newmin);
            show(st[ik]);
            while (st[ik].back().second >= newmin) {
                int next = st[ik][st[ik].size() - 2].first;
                trees[ik].modify(last, next - 1, newmin - st[ik].back().second);
                last = next;
                st[ik].pop_back();
            }
            if (st[ik].back().first != loci + 1)
                st[ik].eb(loci + 1, newmin);
            st[ik].eb(loci, a[curl]);
            trees[ik].set(loci, a[curl]);
            show(st[ik]);
        }
        shows;
        show(curl);
        show(q.l, q.r);
        debug {
            for (int i = 0; i < trees[curl % k].n; ++i) {
                cerr << trees[curl % k].ask(i, i).sm << ' ';
            }
            cerr << endl;
        }
        int len = (q.r - q.l + 1);
        int cnt = (len + k - 1) / k;
        ans[q.i] = trees[q.l % k].ask(q.l / k, q.l / k + cnt - 1).sm;
        show(len, cnt, ans[q.i]);
    }
    for (auto k : ans)
        cout << k << '\n';

    return 0;
}