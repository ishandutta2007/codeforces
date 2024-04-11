/*
    author:  Maksim1744
    created: 17.11.2020 19:09:33
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

ll mod = 0;

long long mpow(long long a, long long p, long long mod = mod) {
    long long res = 1;
    while (p) {
        if (p & 1) res = res * a % mod;
        p >>= 1;
        a = a * a % mod;
    }
    return res;
}

ll inv(ll k, ll mod = mod) {
    return mpow(k, mod - 2, mod);
}

const int N = 505;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int m, n;
    cin >> m >> n >> mod;
    vector<vector<ll>> C(N, vector<ll>(N));
    for (int i = 0; i < N; ++i) {
        C[0][i] = 0;
        C[i][0] = 1;
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
    }

    vector<ll> dp_eq_sm(n + 1, 0);
    vector<ll> dp_eq_cnt(n + 1, 0);
    dp_eq_cnt[0] = 1;
    dp_eq_sm[0] = 0;
    for (int k = 1; k < dp_eq_sm.size(); ++k) {
        for (int l = 0; l < k; ++l) {
            int r = k - l - 1;
            ll cur_cnt = dp_eq_cnt[l] * dp_eq_cnt[r] % mod * C[k - 1][l] % mod;
            dp_eq_sm[k] += (dp_eq_cnt[l] * dp_eq_sm[r] % mod + dp_eq_cnt[r] * dp_eq_sm[l] % mod) * C[k - 1][l] % mod * (k + 1) % mod;
            dp_eq_sm[k] += cur_cnt * (l * (l + 1) / 2 + r * (r + 1) / 2);
            cur_cnt = cur_cnt * (k + 1) % mod;

            dp_eq_sm[k] %= mod;
            dp_eq_cnt[k] = (dp_eq_cnt[k] + cur_cnt) % mod;
        }
    }

    show(dp_eq_cnt);
    show(dp_eq_sm);

    vector<vector<ll>> dp_cnt(m + 1, vector<ll>(n + 1, 0));
    vector<vector<ll>> dp_sm(m + 1, vector<ll>(n + 1, 0));
    for (int comp = 0; comp <= m; ++comp)
        dp_cnt[comp][0] = 1;

    for (int pep = 0; pep <= n; ++pep) {
        for (int comp = 0; comp <= m; ++comp) {
            if (pep > comp) continue;
            if (pep == comp) {
                dp_cnt[comp][pep] = dp_eq_cnt[comp];
                dp_sm[comp][pep] = dp_eq_sm[comp];
                continue;
            }
            if (pep == 0) continue;
            for (int first_empty = 0; first_empty < comp; ++first_empty) {
                if (first_empty > pep) break;
                ll cur_cnt = dp_cnt[first_empty][first_empty] * dp_cnt[comp - first_empty - 1][pep - first_empty] % mod;
                cur_cnt = cur_cnt * C[pep][first_empty] % mod;

                dp_sm[comp][pep] += ( dp_sm[first_empty][first_empty] * dp_cnt[comp - first_empty - 1][pep - first_empty] +
                                     dp_cnt[first_empty][first_empty] *  dp_sm[comp - first_empty - 1][pep - first_empty]) % mod
                             * C[pep][first_empty] % mod;
                dp_sm[comp][pep] %= mod;

                dp_cnt[comp][pep] = (dp_cnt[comp][pep] + cur_cnt) % mod;
            }
        }
    }

    // printMatrix(dp_cnt);
    // shows;
    // printMatrix(dp_sm);
    // shows;

    cout << dp_sm[m][n] << '\n';

    return 0;
}