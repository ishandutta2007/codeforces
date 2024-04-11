/*
    author:  Maksim1744
    created: 21.04.2020 18:44:11
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

const ll inf = 1e18;

void solve() {
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    --a; --b; --c;
    vector<ll> p(m);
    cin >> p;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto get_d = [&](int v) {
        vector<int> d(n, n * 10);
        d[v] = 0;
        queue<int> q;
        q.push(v);
        vector<bool> u(n, false);
        u[v] = true;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto k : g[v]) {
                if (!u[k]) {
                    d[k] = d[v] + 1;
                    u[k] = true;
                    q.push(k);
                }
            }
        }
        return d;
    };
    auto da = get_d(a), db = get_d(b), dc = get_d(c);
    sort(p.begin(), p.end());
    vector<ll> sp = {0};
    for (auto k : p) {
        sp.pb(sp.back() + k);
    }
    auto get_s = [&](int l, int r) {
        if (r < l) return 0ll;
        if (r + 1 >= sp.size()) return inf;
        return sp[r + 1] - sp[l];
    };
    ll ans = sp.back() * 2;
    for (int i = 0; i < n; ++i) {
        int cntb = db[i];
        ans = min(ans, get_s(0, cntb - 1) * 2 + get_s(cntb, cntb + da[i] + dc[i] - 1));
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}