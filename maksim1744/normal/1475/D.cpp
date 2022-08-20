/*
    author:  Maksim1744
    created: 25.01.2021 18:06:49
*/

#include "bits/stdc++.h"

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

void test_case(int test) {
    ll n, m;
    cin >> n >> m;
    vector<ll> a1, a2;
    {
        vector<int> a(n);
        cin >> a;
        vector<int> b(n);
        cin >> b;
        for (int i = 0; i < n; ++i) {
            if (b[i] == 1) a1.pb(a[i]);
            else a2.pb(a[i]);
        }
    }
    sort(a1.begin(), a1.end());
    reverse(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    reverse(a2.begin(), a2.end());
    a1.insert(a1.begin(), 0);
    a2.insert(a2.begin(), 0);
    for (int i = 1; i < a1.size(); ++i)
        a1[i] += a1[i - 1];
    for (int i = 1; i < a2.size(); ++i)
        a2[i] += a2[i - 1];

    // show(a1);
    // show(a2);

    ll ans = 1e18;
    for (int c1 = 0; c1 < a1.size(); ++c1) {
        ll have = a1[c1];
        ll need = m - have;
        if (a2.back() < need) continue;
        int c2 = lowb(a2, need);
        ans = min(ans, (ll)c2 * 2 + c1);
    }

    if (ans == 1e18) ans = -1;
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