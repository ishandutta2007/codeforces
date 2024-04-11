/*
    author:  Maksim1744
    created: 25.05.2022 21:34:37
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


ll get_score(const vector<int>& p, const vector<int>& q) {
    ll ans = 0;
    int n = p.size();
    for (int i = 0; i < n; ++i) {
        ans += abs(q[i] - p[q[(i + 1) % n]]);
    }
    return ans;
}

struct DSU {
    vector<int> rk;
    vector<int> p;
    vector<vector<int>> cyc;
    int n;

    DSU(int n = 1) : n(n) {
        reset(n);
    }

    void reset(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        rk.assign(n, 1);
        cyc.resize(n);
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
        return true;
    }

    bool check(int u, int v) {
        return par(u) == par(v);
    }
};

void test_case(int test) {
    int n;
    cin >> n;
    vector<int> p(n);
    cin >> p;
    --p;

    auto slow = [&]() {
        vector<int> q(n);
        iota(q.begin(), q.end(), 0);
        ll ans = 1e18;
        do {
            ans = min(ans, get_score(p, q));
        } while (next_permutation(q.begin(), q.end()));
        return ans;
    };

    DSU d(n);
    for (int i = 0; i < n; ++i) {
        d.un(i, p[i]);
    }

    {
        vector<bool> u(n, false);
        for (int i = 0; i < n; ++i) {
            if (u[i]) continue;
            int x = i;
            vector<int> c;
            while (!u[x]) {
                c.pb(x);
                u[x] = true;
                x = p[x];
            }
            reverse(c.begin(), c.end());
            d.cyc[d.par(c[0])] = c;
        }
    }
    vector<int> pi(n);
    for (int i = 0; i < n; ++i) {
        pi[p[i]] = i;
    }
    int my_ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        int u = d.par(i);
        int v = d.par(i + 1);
        if (!d.un(i, i + 1)) {
            continue;
        }
        auto cu = d.cyc[u];
        auto cv = d.cyc[v];
        rotate(cu.begin(), find(cu.begin(), cu.end(), i), cu.end());
        rotate(cu.begin(), cu.begin() + 1, cu.end());
        int j = pi[i + 1];
        rotate(cv.begin(), find(cv.begin(), cv.end(), j), cv.end());

        int x = d.par(i);
        d.cyc[x] = cu;
        for (int k : cv)
            d.cyc[x].pb(k);

        my_ans += 2;
    }
    auto q = d.cyc[d.par(0)];
    show(p, q);
    show(my_ans);
    show(get_score(p, q));
    assert(get_score(p, q) == my_ans);

    {
        vector<bool> u(n, false);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (u[i]) continue;
            ++ans;
            int x = i;
            while (!u[x]) {
                u[x] = true;
                x = p[x];
            }
        }
        ans = (ans - 1) * 2;
        show(ans);
        #ifdef HOUSE
        // int s = slow();
        // assert(ans == s);
        #endif
        assert(ans == my_ans);
    }

    ++q;
    cout << q << '\n';

    // cout << slow() << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}