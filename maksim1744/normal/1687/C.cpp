/*
    author:  Maksim1744
    created: 03.06.2022 17:53:06
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

void test_case(int test) {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n);
    cin >> a >> b;
    for (int i = 0; i < n; ++i) {
        a[i] -= b[i];
    }
    a.insert(a.begin(), 0);
    for (int i = 1; i <= n; ++i)
        a[i] += a[i - 1];
    ++n;
    vector<pair<int, int>> segs(m);
    cin >> segs;
    for (int i = 0; i < m; ++i) {
        segs[i].first--;
    }
    vector<vector<int>> here(n);
    for (int i = 0; i < segs.size(); ++i) {
        here[segs[i].first].pb(i);
        here[segs[i].second].pb(i);
    }
    show(a);
    show(segs);
    show(here);

    queue<int> q;
    for (int i = 0; i < m; ++i) {
        q.push(i);
    }

    set<int> left;
    for (int i = 0; i < n; ++i) {
        if (a[i] != 0)
            left.insert(i);
    }

    vector<bool> u(m, false);
    while (!q.empty()) {
        int ind = q.front();
        q.pop();
        if (u[ind]) continue;
        auto [l, r] = segs[ind];
        if (a[l] != 0 || a[r] != 0) continue;
        u[ind] = true;
        auto it = left.lower_bound(l);
        while (it != left.end() && *it <= r) {
            for (int i : here[*it])
                q.push(i);
            a[*it] = 0;
            it = left.erase(it);
        }
    }
    show(a);
    show(u);
    cout << (count(a.begin(), a.end(), 0) == a.size() ? "YES" : "NO") << '\n';
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