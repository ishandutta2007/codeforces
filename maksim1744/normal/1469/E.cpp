/*
    author:  Maksim1744
    created: 28.12.2020 18:07:02
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        s[i] ^= '0' ^ '1';
    }
    string ans;
    int K = k;
    vector<int> prev0(n, -1e7);
    for (int i = 1; i < n; ++i) {
        prev0[i] = prev0[i - 1];
        if (s[i - 1] == '1') {
            prev0[i] = i - 1;
        }
    }
    show(prev0);
    function<void(int, int)> solve = [&](int st, int k) {
        // cerr << st << ' ' << k << ' ' << (1 << (k - 1)) << ' ' << ((n - st) - k + 1) << endl;
        if (k < 25 && (1 << (k - 1)) <= ((n - st) - k + 1)) {
            vector<int> has(1 << k, false);
            int cur = 0;
            for (int i = st; i < st + k; ++i) {
                cur += (((int)(s[i] - '0')) << (k - 1 - (i - st)));
            }
            show(st, k);
            show(s, cur);
            if (prev0[st] < st - (K - k))
                has[cur] = 1;
            for (int i = st + k; i < n; ++i) {
                cur = ((cur * 2) & ((1 << k) - 1)) + (((int)(s[i] - '0')));
                show(i, cur);
                if (prev0[(i - k + 1)] < (i - k + 1) - (K - k))
                    has[cur] = 1;
            }
            show(has);
            for (int i = 0; i < has.size(); ++i) {
                if (!has[i]) {
                    string ss;
                    int x = i;
                    for (int j = 0; j < k; ++j) {
                        ss.pb('0' + x % 2);
                        x /= 2;
                    }
                    reverse(ss.begin(), ss.end());
                    ans += ss;
                    return;
                }
            }
            ans = "NO";
            return;
        }
        ans.pb('0');
        solve(st + 1, k - 1);
    };
    solve(0, k);
    if (ans != "NO")
        cout << "YES\n";
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