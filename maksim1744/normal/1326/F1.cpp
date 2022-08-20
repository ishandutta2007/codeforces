/*
    author:  Maksim1744
    created: 19.03.2020 18:44:49
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

    int n;
    cin >> n;
    vector<vector<int>> mt(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            if (s[j] == '1')
                mt[i][j] = 1;
        }
    }
    vector<ll> ans(1 << (n - 1), 0);
    int n1 = n / 2;
    int n2 = n - n1;
    vector<vector<ll>> dp1(n1, vector<ll>(1 << (n1 - 1), 0));
    vector<vector<ll>> dp2(n2, vector<ll>(1 << (n2 - 1), 0));
    for (int mask = 0; mask < (1 << n); ++mask) {
        if (__builtin_popcount(mask) != n1)
            continue;
        for (int i = 0; i < n1; ++i)
            dp1[i].assign(dp1[i].size(), 0);
        for (int i = 0; i < n2; ++i)
            dp2[i].assign(dp2[i].size(), 0);
        vector<int> p1, p2;
        vector<int> num(n);
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                num[i] = p1.size();
                p1.pb(i);
            } else {
                num[i] = p2.size();
                p2.pb(i);
            }
        }
        do {
            int k = 0;
            for (int i = 0; i + 1 < p1.size(); ++i) {
                k = k * 2 + mt[p1[i]][p1[i + 1]];
            }
            dp1[num[p1.back()]][k]++;
        } while (next_permutation(p1.begin(), p1.end()));
        do {
            int k = 0;
            for (int i = 0; i + 1 < p2.size(); ++i) {
                k = k * 2 + mt[p2[i]][p2[i + 1]];
            }
            dp2[num[p2[0]]][k]++;
        } while (next_permutation(p2.begin(), p2.end()));
        for (int i = 0; i < dp1.size(); ++i) {
            for (int j = 0; j < dp2.size(); ++j) {
                int c = mt[p1[i]][p2[j]] << (n2 - 1);
                for (int i1 = 0; i1 < dp1[i].size(); ++i1) {
                    for (int j1 = 0; j1 < dp2[j].size(); ++j1) {
                        ans[(i1 << n2) + c + j1] += dp1[i][i1] * dp2[j][j1];
                    }
                }
            }
        }
    }
    cout << ans << '\n';

    return 0;
}