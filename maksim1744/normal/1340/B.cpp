/*
    author:  Maksim1744
    created: 23.04.2020 17:54:16
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

    vector<string> snums = {
        "1110111",
        "0010010",
        "1011101",
        "1011011",
        "0111010",
        "1101011",
        "1101111",
        "1010010",
        "1111111",
        "1111011"
    };
    vector<int> nums;
    for (auto s : snums) {
        int num = 0;
        for (auto c : s) {
            num = num * 2 + (c - '0');
        }
        nums.pb(num);
    }

    int n, k;
    cin >> n >> k;
    vector<int> has(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int num = 0;
        for (auto c : s) {
            num = num * 2 + (c - '0');
        }
        has[i] = num;
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
    dp[n][0] = true;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j <= k; ++j) {
            for (auto num : nums) {
                if ((num & has[i]) == has[i]) {
                    int cnt = __builtin_popcount(num ^ has[i]);
                    if (j >= cnt) {
                        dp[i][j] = dp[i][j] || dp[i + 1][j - cnt];
                    }
                }
            }
        }
    }
    if (!dp[0][k]) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans;
    int left = k;
    for (int i = 0; i < n; ++i) {
        for (int x = 9; x >= 0; --x) {
            int num = nums[x];
            if ((num & has[i]) == has[i]) {
                int cnt = __builtin_popcount(num ^ has[i]);
                if (left >= cnt && dp[i + 1][left - cnt]) {
                    left -= cnt;
                    ans.pb(x);
                    break;
                }
            }
        }
    }
    for (auto k : ans) {
        cout << k;
    }
    cout << endl;

    return 0;
}