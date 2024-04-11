/*
    author:  Maksim1744
    created: 20.07.2019 20:06:52
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
// #include "C:/C++ libs/print.cpp"
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#endif

const ll mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    cin >> a;
    --a;
    vector<int> lt(n, -1), rt(n, m);
    for (int i = 0; i < m; ++i) {
        if (lt[a[i]] == -1)
            lt[a[i]] = i;
        rt[a[i]] = i;
    }
    vector<int> st;
    for (int i = 0; i < m; ++i) {
        if (!st.empty() && a[i] < st.back()) {
            cout << 0 << '\n';
            return 0;
        }
        if (lt[a[i]] == i) {
            st.push_back(a[i]);
        }
        if (!st.empty() && a[i] == st.back() && rt[a[i]] == i) {
            st.pop_back();
        }
    }
    vector<int> a1;
    for (int i = 0; i < m; ++i) {
        if (i == 0 || a[i] != a[i - 1]) {
            a1.pb(a[i]);
        }
    }
    a = a1;
    m = a.size();
    int N = m;
    lt.assign(m, -1);
    for (int i = 0; i < m; ++i) {
        if (lt[a[i]] == -1)
            lt[a[i]] = i;
        rt[a[i]] = i;
    }
    // a.insert(a.begin(), -1);
    // a.pb(-1);
    // ++lt;
    // ++rt;
    vector<vector<int>> mn(N, vector<int>(N, 1e5));
    for (int i = 0; i < N; ++i) {
        mn[i][i] = a[i];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            mn[i][j] = min(mn[i][j - 1], a[j]);
        }
    }
    vector<vector<ll>> dp(N, vector<ll>(N, 0));
    vector<vector<ll>> dps(N, vector<ll>(N, 0));
    map<pair<int, int>, bool> mem;
    auto is_ok = [&](int l, int r) {
        auto pr = mp(l, r);
        if (mem.find(pr) != mem.end())
            return mem[pr];
        int k = mn[l][r];
        bool ans = true;
        // for (int c = k; c < n; ++c) {
        //     if (!(l <= lt[c] && rt[c] <= r)) {
        //         ans = false;
        //         break;
        //     }
        // }
        for (int i = l; i <= r; ++i) {
            if (a[i] < k) {
                ans = false;
                break;
            } else {
                int c = a[i];
                if (!(l <= lt[c] && rt[c] <= r)) {
                    ans = false;
                    break;
                }
            }
        }
        mem[pr] = ans;
        // cout << pr << " : " << ans << endl;
        return ans;
    };
    for (int i = 0; i < m - 1; ++i) {
        dp[i + 1][i] = 1;
        dps[i + 1][i] = 1;
    }
    for (int ln = 0; ln < N; ++ln) {
        for (int l = 0; l + ln < N; ++l) {
            int r = l + ln;
            if (!is_ok(l, r)) {
                dp[l][r] = 0;
                continue;
            }
            int c = mn[l][r];
            int i1 = lt[c], i2 = rt[c];
            if (i1 == 0 && i2 + 1 == m)
                dp[l][r] = 1 % mod;
            else if (i1 == 0)
                dp[l][r] = dps[i2 + 1][r] % mod;
            else if (i2 + 1 == m)
                dp[l][r] = dps[l][i1 - 1] % mod;
            else
                dp[l][r] = dps[l][i1 - 1] * dps[i2 + 1][r] % mod;
            int lst = i1;
            for (int i = i1 + 1; i <= i2; ++i) {
                if (a[i] == c) {
                    dp[l][r] = dp[l][r] * dp[lst + 1][i - 1] % mod;
                    lst = i;
                }
            }
        }
        for (int l = 0; l + ln < N; ++l) {
            int r = l + ln;
            dps[l][r] = 0;
            for (int i = l - 1; i <= r; ++i) {
                if (i == -1)
                    dps[l][r] += dp[i + 1][r];
                else if (i + 1 == m)
                    dps[l][r] += dp[l][i];
                else
                    dps[l][r] += dp[l][i] * dp[i + 1][r] % mod;
                dps[l][r] %= mod;
            }
            // if (!is_ok(l, r)) {
            //     dp[l][r] = 0;
            //     continue;
            // }
        }
    }
    // for (int i = 0; i < m; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    // for (int i = 0; i < m; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cout << dps[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < N; ++j) {
    //         for (int k = 0; k < n; ++k) {
    //             if (lt[k] <= i && j <= rt[k])
    //                 continue;
    //             if (j < lt[k])
    //                 continue;
    //             if (rt[k] < i)
    //                 continue;
    //             if (i <= lt[k] && rt[k] <= j)
    //                 continue;
    //             bad[i][j] = true;
    //             break;
    //         }
    //     }
    // }
    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < N; ++j) {
    //         cout << bad[i][j];
    //     }
    //     cout << '\n';
    // }
    cout << dp[0][m - 1] << '\n';
    return 0;
}