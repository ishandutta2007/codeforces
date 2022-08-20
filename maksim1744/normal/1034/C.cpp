/*
    author:  Maksim1744
    created: 03.05.2019 17:01:21
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}

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
#define showt(...)       42;
#define printTree(...)   42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

const ll mod = 1e9 + 7;

vector<vector<int>> g;
vector<ll> a;
vector<ll> sm;

void dfs(int v) {
    sm[v] = a[v];
    for (auto k : g[v]) {
        dfs(k);
        sm[v] += sm[k];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    g.resize(n);
    a.resize(n);
    cin >> a;
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        g[p].pb(i);
    }
    sm.assign(n, 0);
    dfs(0);
    ll s = accumulate(a.begin(), a.end(), 0ll);
    for (int i = 0; i < n; ++i) {
        sm[i] = s / __gcd(s, sm[i]);
    }
    vector<ll> cnt(n + 1, 0);
    for (auto k : sm) {
        if (k <= n)
            ++cnt[k];
    }
    for (int i = n; i >= 1; --i)
        for (int j = i * 2; j <= n; j += i)
            cnt[j] += cnt[i];
    vector<ll> ans(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        if (cnt[i] >= i)
            ans[i] = 1;
    show(cnt, ans);
    for (int i = n; i >= 1; --i)
        if (ans[i])
            for (int j = i * 2; j <= n; j += i)
                ans[i] = (ans[i] + ans[j]) % mod;
    cout << ans[1] << '\n';
    return 0;
}