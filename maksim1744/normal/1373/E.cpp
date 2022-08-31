/*
    author:  Maksim1744
    created: 25.06.2020 17:57:29
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

void test_case() {
    int n, k;
    cin >> n >> k;
    // if (9 % (k + 1) == 0) {
    //     if ((n - k * (k + 1) / 2) % (k + 1) != 0) {
    //         cout << -1 << '\n';
    //         return;
    //     }
    // }
    string ans;
    for (int lastd = 0; lastd <= 9; ++lastd) {
        int safe = 0;
        bool got = 0;
        for (int c9 = 0; c9 * 9 <= n && (ans.empty() || c9 < ans.size() + 3); ++c9) {
            int t = max(0, k - 9 + lastd);
            int sm = n + (c9 + 1) * 9 * t - k * (k + 1) / 2;
            if (n == 99 && k == 2 && c9 == 10 && lastd == 9) show(sm, t);
            if (sm >= 0 && sm % (k + 1) == 0) {
                sm /= (k + 1);
                string cur;
                cur.pb('0' + lastd);
                sm -= lastd;
                for (int i = 0; i < c9; ++i) {
                    cur.pb('9');
                    sm -= 9;
                }
                if (sm >= 0) {
                    if (sm >= 9) {
                        cur.pb('8');
                        sm -= 8;
                    }
                    while (sm != 0) {
                        if (sm >= 9) {
                            cur.pb('9');
                            sm -= 9;
                        } else {
                            cur.pb('0' + sm);
                            sm = 0;
                        }
                    }
                    reverse(cur.begin(), cur.end());
                    if (cur.empty()) cur = "0";
                    if (ans.empty()) {
                        ans = cur;
                    } else {
                        if (cur.size() < ans.size() || (cur.size() == ans.size() && cur < ans))
                            ans = cur;
                    }
                    got = true;
                }
            }
        }
    }
    if (ans.empty()) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        test_case();
    }

    return 0;
}