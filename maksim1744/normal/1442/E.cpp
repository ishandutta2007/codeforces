/*
    author:  Maksim1744
    created: 01.11.2020 18:43:37
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

void test_case(int test) {
    int n;
    cin >> n;
    vector<int> col(n);
    cin >> col;
    --col;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int longest = 1;
    vector<vector<int>> dp(n, vector<int>(2, 0));
    vector<bool> u(n, false);
    function<void(int)> dfs = [&](int v) {
        u[v] = true;
        vector<int> mx1(2, 0);
        vector<int> mx2(2, 0);
        for (auto k : g[v]) {
            if (!u[k]) {
                dfs(k);
                for (int c = 0; c < 2; ++c) {
                    if (dp[k][c] >= mx1[c]) {
                        mx2[c] = mx1[c];
                        mx1[c] = dp[k][c];
                    } else if (dp[k][c] > mx2[c]) {
                        mx2[c] = dp[k][c];
                    }
                }
            }
        }
        longest = max(longest, mx1[1] + mx1[0]);
        for (int c : {0, 1}) {
            if (col[v] == c || col[v] == -1)
                longest = max(longest, mx1[c] + mx2[c] - 1);
            else
                longest = max(longest, mx1[c] + mx2[c] + 1);
            if (col[v] == c)
                dp[v][c] = max(dp[v][c], mx1[1 - c] + 1);
            if (col[v] == c || col[v] == -1)
                dp[v][c] = max(dp[v][c], mx1[c]);
        }
    };
    dfs(0);
    // printTree(g, dp);
    cout << longest / 2 + 1 << '\n';
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