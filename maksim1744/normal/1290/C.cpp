/*
    author:  Maksim1744
    created: 02.02.2020 17:49:40
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

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

template<typename T>             vector<T>& operator--            (vector<T>& v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T>& v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define TAG_LENGTH       25
#define LR_LEFT          left
#define LR_RIGHT         right
#define LR_VALUE         value
#define LR_SECOND_VALUE  mn
#include "C:/C++ libs/print.cpp"
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showm(...)       42;
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#define debug     if (false)
#endif

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int>> v(n);
    vector<vector<int>> a(k);
    for (int i = 0; i < k; ++i) {
        int m;
        cin >> m;
        a[i].resize(m);
        cin >> a[i];
        --a[i];
        for (auto u : a[i]) {
            v[u].pb(i);
        }
    }

    vector<int> p(k), rk(k, 1);
    for (int i = 0; i < k; ++i) {
        p[i] = i;
    }
    function<int(int)> par = [&](int v) {
        return v == p[v] ? v : p[v] = par(p[v]);
    };
    auto un = [&](int u, int v) {
        u = par(u);
        v = par(v);
        if (u == v) return;
        if (rk[u] > rk[v])
            swap(u, v);
        p[u] = v;
        rk[v] += rk[u];
    };
    vector<int> flipped(k, false);
    vector<int> fixed(k, false);
    vector<int> c0(k, 1);
    vector<int> c1(k, 0);
    vector<int> col(k, 0);
    int last = 0;
    vector<vector<int>> g(k);
    vector<int> u(k, -1);
    int tm = 0;
    function<void(int)> dfs = [&](int v) {
        col[v] = 1 - col[v];
        u[v] = tm;
        for (auto k : g[v]) {
            if (u[k] < tm)
                dfs(k);
        }
    };
    show(v);
    for (int i = 0; i <= n; ++i) {
        if (i != 0) {
            cout << last << '\n';
        }
        if (i == n)
            break;
        if (v[i].size() == 0) {
            continue;
        } else if (v[i].size() == 1) {
            int k = v[i][0];
            int p = par(k);
            // show(k, p);
            // show(c0);
            // show(c1);
            if (fixed[p]) {
                continue;
            }
            fixed[p] = true;
            if ((col[k] ^ flipped[p]) == (s[i] == '0'))
                continue;
            flipped[p] = !flipped[p];
            last -= c1[p];
            swap(c0[p], c1[p]);
            last += c1[p];
        } else {
            int a = v[i][0];
            int b = v[i][1];
            int pa = par(a), pb = par(b);
            bool ok = false;
            if (s[i] == '0') {
                if ((col[a] ^ flipped[pa]) != (col[b] ^ flipped[pb]))
                    ok = true;
            } else {
                if ((col[a] ^ flipped[pa]) == (col[b] ^ flipped[pb]))
                    ok = true;
            }
            if (pa == pb) {
                continue;
            }
            show(ok);
            int c;
            if (c0[pa] - c1[pa] < c0[pb] - c1[pb])
                c = a;
            else
                c = b;
            if (!ok && flipped[pa] != flipped[pb]) {
                show("easy");
                if (fixed[par(c)])
                    c = a + b - c;
                int pc = par(c);
                flipped[pc] = !flipped[pc];
                last -= c1[pc];
                swap(c0[pc], c1[pc]);
                last += c1[pc];
            } else if (!ok || flipped[pa] != flipped[pb]) {
                show("hard");
                int d;
                if (rk[pa] < rk[pb])
                    d = a;
                else
                    d = b;
                // if (fixed[par(d)] && !ok)
                //     d = a + b - d;
                dfs(d);
                ++tm;
                int pd = par(d);
                if (ok) {
                    flipped[pd] = !flipped[pd];
                } else {
                    last -= c1[pd];
                    swap(c0[pd], c1[pd]);
                    last += c1[pd];
                    if (fixed[pd]) {
                        flipped[pa] = !flipped[pa];
                        flipped[pb] = !flipped[pb];
                        last -= c1[pa];
                        swap(c0[pa], c1[pa]);
                        last += c1[pa];
                        last -= c1[pb];
                        swap(c0[pb], c1[pb]);
                        last += c1[pb];
                    }
                }
            }
            un(a, b);
            auto pnew = par(a);
            c0[pnew] = c0[pa] + c0[pb];
            c1[pnew] = c1[pa] + c1[pb];
            fixed[pnew] = fixed[pa] || fixed[pb];

            if (!fixed[pnew] && c0[pnew] < c1[pnew]) {
                flipped[pnew] = !flipped[pnew];
                last -= c1[pnew];
                swap(c0[pnew], c1[pnew]);
                last += c1[pnew];
            }

            g[a].pb(b);
            g[b].pb(a);
        }
    }

    return 0;
}