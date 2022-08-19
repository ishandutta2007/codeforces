/*
    author:  Maksim1744
    created: 12.09.2021 18:16:32
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

void test_case(int test) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    cin >> a;
    sort(a.begin(), a.end());

    vector<pair<int, int>> v;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        int ind = lowb(a, l);
        if (ind < n && a[ind] <= r) continue;
        v.eb(l, r);
    }
    sort(v.begin(), v.end());
    m = v.size();
    if (m == 0) {
        cout << 0 << '\n';
        return;
    }

    vector<ll> cost11(n - 1, 1e18);
    vector<ll> cost12(n - 1, 1e18);
    vector<ll> cost21(n - 1, 1e18);
    vector<ll> cost22(n - 1, 1e18);
    vector<int> minr(m);

    show(v);

    for (int i = 0; i + 1 < n; ++i) {
        int il = lowb(v, mp(a[i], (int)-2e9));
        int ir = lowb(v, mp(a[i + 1], (int)-2e9));
        show(il, ir);
        if (il == ir) {
            cost11[i] = cost12[i] = cost21[i] = cost22[i] = 0;
            continue;
        }

        minr[ir - 1] = v[ir - 1].second;
        for (int i = ir - 2; i >= il; --i)
            minr[i] = min(minr[i + 1], v[i].second);

        auto upd = [&](ll L, ll R) {
            cost11[i] = min(cost11[i], L + R);
            cost12[i] = min(cost12[i], L + R * 2);
            cost21[i] = min(cost21[i], L * 2 + R);
            cost22[i] = min(cost22[i], L * 2 + R * 2);
        };

        upd(0, a[i + 1] - minr[il]);
        upd(v[ir - 1].first - a[i], 0);
        --ir;

        for (int j = il; j < ir; ++j) {
            upd(v[j].first - a[i], a[i + 1] - minr[j + 1]);
        }
    }

    show(a);
    show(cost11);
    show(cost12);
    show(cost21);
    show(cost22);

    ll left = 0, right = 0;
    {
        right = max(0ll, (ll)v.back().first - a.back());
    }
    {
        for (int i = 0; i < m; ++i)
            if (v[i].second < a[0])
                left = max(left, (ll)a[0] - v[i].second);
    }

    show(left, right);

    array<ll, 3> dp;
    dp[1] = left;
    dp[2] = left * 2;
    for (int i = 0; i + 1 < n; ++i) {
        array<ll, 3> next;
        next[1] = min(dp[1] + cost21[i], dp[2] + cost11[i]);
        next[2] = min(dp[1] + cost22[i], dp[2] + cost12[i]);
        swap(dp, next);
    }

    ll ans = min(dp[1] + right * 2, dp[2] + right);

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}