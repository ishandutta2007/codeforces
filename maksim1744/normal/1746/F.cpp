/*
    author:  Maksim1744
    created: 15.10.2022 18:45:02
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
#define OSTREAM(...)    ;
#define OSTREAM0(...)   ;
#endif

#ifdef HOUSE
mt19937_64 rng(34829);
#else
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#endif
ll rnd (ll l, ll r) { return (ll)(rng() % (r - l + 1)) + l; }
ll rnd (ll r)       { return rng() % r; }
ll rnd ()           { return rng(); }
ld rndf()           { return (ld)rng() / (ld)ULLONG_MAX; }
ld rndf(ld l, ld r) { return rndf() * (r - l) + l; }

struct Que {
    int tp;
    int i, x;
    int l, r, k;

    void read() {
        // tp = 2;
        // l = rnd(0, 3e5-1);
        // r = rnd(0, 3e5-1);
        // if (l > r) swap(l, r);
        // k = 1;
        // return;
        cin >> tp;
        assert(tp == 1 || tp == 2);
        if (tp == 1) {
            cin >> i >> x;
            --i;
        } else {
            cin >> l >> r >> k;
            --l; --r;
        }
    }
};

template<typename T>
struct fenwick {
    vector<T> tree;
    int n;
    int K;

    fenwick(int n = 0) : n(n) {
        tree.assign(n, 0);
        K = 0;
        while ((1 << K) <= n)
            ++K;
    }

    void add(int i, T k) {
        for (; i < n; i = (i | (i + 1)))
            tree[i] += k;
    }

    T ask(int r) {
        T res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res += tree[r];
        return res;
    }

    T ask(int l, int r) {
        if (l > r) return 0;
        return ask(r) - ask(l - 1);
    }

    // find first i such that sum[0..i] >= x
    int lower_bound(T x) {
        int cur = 0;
        T cur_sum = 0;
        for (int k = K - 1; k >= 0; --k) {
            int ind = cur | ((1 << k) - 1);
            if (ind >= n) continue;
            if (cur_sum + tree[ind] >= x) continue;
            cur_sum += tree[ind];
            cur |= (1 << k);
        }
        return cur;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q;
    // n = 3e5;
    // q = 3e5;
    cin >> n >> q;
    vector<int> a(n);
    // for (int i = 0; i < n; ++i) {
    //     a[i] = rnd(1, 1e9);
    // }
    cin >> a;
    vector<Que> que(q);
    for (auto& q : que) {
        q.read();
    }

    vector<int> vals = a;
    for (auto q : que)
        if (q.tp == 1)
            vals.pb(q.x);

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int i = 0; i < n; ++i) {
        a[i] = lowb(vals, a[i]);
    }
    for (auto& q : que)
        if (q.tp == 1)
            q.x = lowb(vals, q.x);

    vector<vector<int>> where(vals.size());
    vector<int> p(vals.size());
    iota(p.begin(), p.end(), 0);

    const int B = 33;
    for (int i = 0; i < B; ++i) {
        shuffle(p.begin(), p.end(), rng);
        int sz = (p.size() + rnd(2)) / 2;
        for (int j = 0; j < sz; ++j)
            where[p[j]].pb(i);
    }

    array<fenwick<int>, B> trees;
    for (auto& t : trees)
        t = fenwick<int>(n);

    for (int i = 0; i < n; ++i) {
        for (int j : where[a[i]])
            trees[j].add(i, 1);
    }

    for (auto q : que) {
        if (q.tp == 1) {
            int i = q.i;
            int x = q.x;
            for (int j : where[a[i]])
                trees[j].add(i, -1);
            a[i] = x;
            for (int j : where[a[i]])
                trees[j].add(i, 1);
        } else {
            bool ok = true;
            for (auto& t : trees) {
                if (t.ask(q.l, q.r) % q.k != 0) {
                    ok = false;
                    break;
                }
            }
            cout << (ok ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}