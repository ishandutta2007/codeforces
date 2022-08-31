/*
    author:  Maksim1744
    created: 16.06.2021 13:43:31
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

const int N = 2e5 + 20;
array<pair<int, int>, N> mem;
array<pair<int, int>, N> mem2;
int imem = 0;
int imem2 = 0;

// const int B = 3;
const int B = 1350;
// const int B = 5;
int iid = 0;
struct Block {
    set<pair<int, int>> tor = {{-1, -1}}, tol = {{(int)1e9, -1}};
    array<int, B> a, left, right, pref;
    int sz = 0;
    int l, r;

    int& operator[] (int i) {
        return a[i];
    }

    void add_segment(int L, int R) {
        ++imem2;
        for (int i = L; i <= R; ++i) {
            right[i] = R + this->l;
            left[i] = L + this->l;
        }
        int maxfreq = 0;
        for (int i = L; i <= R; ++i) {
            int k = a[i];
            if (mem2[k].second != imem2)
                mem2[k] = {0, imem2};
            maxfreq = max(maxfreq, ++mem2[k].first);
        }
        show(maxfreq);
        int cost = R - L + 1 - maxfreq;
        pref[R] = cost + (L == 0 ? 0 : pref[L - 1]);
    }

    void build() {
        r = l + sz - 1;
        ++imem;
        for (int i = 0; i < sz; ++i)
            mem[a[i]] = {i, imem};
        int L = 0, R = -1;
        for (int i = 0; i < sz; ++i) {
            int r = mem[a[i]].first;
            if (R >= i) {
                R = max(R, r);
            } else {
                if (R != -1) {
                    add_segment(L, R);
                }

                L = i;
                R = r;
            }
        }
        add_segment(L, R);
    }

    int get_cost(int l, int r) {
        return pref[r] - (l == 0 ? 0 : pref[l - 1]);
    }
};

namespace segtree {
struct item {
    int mx = 0;

    template<typename T>
    void init(const T &t, int l, int r) {
        mx = t;
    }

    void update(const item &first, const item &second, int l, int r) {
        mx = max(first.mx, second.mx);
    }

    static item merge(const item &first, const item &second, int l, int r) {
        item res;
        res.update(first, second, l, r);  // careful with different lengths
        return res;
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
        tree.resize(1 << (__lg(n - 1) + 2));
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
        tree.resize(1 << (__lg(n - 1) + 2));
        build(v, 0, 0, n - 1);
    }

    item ask(int l, int r, int i, int vl, int vr) {
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
};
}

auto start_time = clock();

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    mem.fill({-1, -1});

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    cin >> a;
    vector<pair<int, int>> que(q);
    cin >> que;
    for (int i = 0; i < q; ++i) {
        que[i].first--;
    }
    que.insert(que.begin(), {0, a[0]});
    ++q;

    vector<Block> blocks(n / B + (n % B != 0));
    for (int i = 0; i < n; ++i) {
        blocks[i / B][i % B] = a[i];
        blocks[i / B].sz++;
        blocks[i / B].l = i / B * B;
    }

    for (auto &b : blocks)
        b.build();

    segtree::segtree tree(n);
    // int icnt = 0;
    // vector<pair<int, int>> cnts(N, {-1, -1});
    auto get_long_cost = [&](int l, int r) {
        return r - l + 1 - tree.ask(l, r).mx;
    };
    vector<int> ans(q, 0);
    auto get_short_cost = [&](int l, int r) {
        if (l > r) return 0;
        int L = l / B;
        int R = r / B;
        if (L == R) {
            return blocks[L].get_cost(l - L * B, r - L * B);
        }
        int ans = 0;
        for (int i = L + 1; i < R; ++i)
            ans += blocks[i].get_cost(0, blocks[i].sz - 1);
        ans += blocks[L].get_cost(l - L * B, blocks[L].sz - 1);
        ans += blocks[R].get_cost(0, r - R * B);
        return ans;
    };

    auto add_long = [&](int l, int r) {
        int L = l / B;
        int R = r / B;
        if (L == R) return;
        blocks[L].tor.emplace(r, ++iid);
        blocks[R].tol.emplace(l, ++iid);
    };
    auto del_long = [&](int l, int r) {
        int L = l / B;
        int R = r / B;
        if (L == R) return;
        {
            auto it = blocks[L].tor.lower_bound(mp(r, -1));
            if (it != blocks[L].tor.end() && it->first == r)
                blocks[L].tor.erase(it);
        }
        {
            auto it = blocks[R].tol.lower_bound(mp(l, -1));
            if (it != blocks[R].tol.end() && it->first == l)
                blocks[R].tol.erase(it);
        }
    };

    vector<set<int>> where(N);
    for (int i = 0; i < n; ++i)
        where[a[i]].insert(i);

    for (int i = 0; i < N; ++i)
        if (!where[i].empty())
            tree.set(*where[i].begin(), where[i].size());

    for (int i = 0; i < N; ++i) {
        if (where[i].size() < 2) continue;
        auto it = where[i].begin();
        auto it1 = next(it);
        while (it1 != where[i].end()) {
            add_long(*it, *it1);
            ++it;
            ++it1;
        }
    }

    for (int i = 0; i < q; ++i) {
        shows;
        auto [pos, new_val] = que[i];

        // auto tt = clock();
        auto it = where[a[pos]].find(pos);
        assert(it != where[a[pos]].end());
        if (it != where[a[pos]].begin())
            del_long(*prev(it), *it);
        if (it != where[a[pos]].end())
            del_long(*it, *next(it));
        if (it != where[a[pos]].begin() && next(it) != where[a[pos]].end())
            add_long(*prev(it), *next(it));

        int old_val = a[pos];
        tree.set(*where[old_val].begin(), 0);
        if (!where[new_val].empty())
            tree.set(*where[new_val].begin(), 0);
        where[a[pos]].erase(pos);
        a[pos] = new_val;
        where[a[pos]].insert(pos);
        if (!where[old_val].empty())
            tree.set(*where[old_val].begin(), where[old_val].size());
        tree.set(*where[new_val].begin(), where[new_val].size());

        it = where[a[pos]].find(pos);

        if (it != where[a[pos]].begin())
            add_long(*prev(it), *it);
        if (it != where[a[pos]].end())
            add_long(*it, *next(it));
        if (it != where[a[pos]].begin() && next(it) != where[a[pos]].end())
            del_long(*prev(it), *next(it));

        // ttm[0] += (double)(clock() - tt) / CLOCKS_PER_SEC;
        // tt = clock();
        blocks[pos / B][pos % B] = new_val;
        blocks[pos / B].build();
        // ttm[1] += (double)(clock() - tt) / CLOCKS_PER_SEC;
        // tt = clock();

        debug {
            for (auto &b : blocks)
                show(b.tol, b.tor);
            for (int k = 0; k <= maxe(a); ++k)
                if (!where[k].empty())
                    show(k, where[k]);
        }

        vector<pair<int, int>> segs;
        for (int i = 0; i + 1 < blocks.size(); ++i) {
            int r = max(blocks[i].r, (--blocks[i].tor.end())->first);
            int l = min(blocks[i + 1].l, blocks[i + 1].tol.begin()->first);
            if (l > r) continue;
            l = min(l, blocks[i].r);
            l = min(l, blocks[l / B].left[l - blocks[l / B].l]);
            r = max(r, blocks[i + 1].l);
            r = max(r, blocks[r / B].right[r - blocks[r / B].l]);
            while (!segs.empty() && segs.back().second >= l) {
                l = min(l, segs.back().first);
                r = max(r, segs.back().second);
                segs.pop_back();
            }
            segs.emplace_back(l, r);
        }
        show(a);
        show(segs);
        show(segs);
        // ttm[2] += (double)(clock() - tt) / CLOCKS_PER_SEC;
        // tt = clock();

        for (auto [l, r] : segs)
            ans[i] += get_long_cost(l, r);
        // ttm[3] += (double)(clock() - tt) / CLOCKS_PER_SEC;
        // tt = clock();

        if (segs.empty()) {
            ans[i] += get_short_cost(0, n - 1);
        } else {
            ans[i] += get_short_cost(0, segs[0].first - 1);
            ans[i] += get_short_cost(segs.back().second + 1, n - 1);
            for (int j = 0; j + 1 < segs.size(); ++j)
                ans[i] += get_short_cost(segs[j].second + 1, segs[j + 1].first - 1);
        }
        // ttm[4] += (double)(clock() - tt) / CLOCKS_PER_SEC;
        // if (i % 10000 == 0) {
            // cerr << i << endl;
            // cerr << ttm[0] << ' ' << ttm[1] << ' ' << ttm[2] << ' ' << ttm[3] <<
            // ' ' << ttm[4] << ' ' << (double)(clock() - start_time) / CLOCKS_PER_SEC << endl;
        // }
        if (i % 10000 == 0 && (double)(clock() - start_time) / CLOCKS_PER_SEC > 4.9) {
            cout << i << endl;
            return 0;
        }
    }

    for (int i = 0; i < q; ++i)
        cout << ans[i] << '\n';

    return 0;
}