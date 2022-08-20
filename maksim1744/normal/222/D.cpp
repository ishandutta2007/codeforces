/*
    author:  Maksim1744
    created: 19.08.2020 19:43:56
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

    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    cin >> a >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 1;
    int cnt = 0;
    int j = 0;
    for (int i = n - 1; i >= 0; --i) {
        while (j < n && a[i] + b[j] < x) ++j;
        if (j < n) {
            ++cnt;
            ++j;
        }
    }
    ans = cnt;
    // show(a);
    // show(b);
    // for (int i = 0; i < n; ++i) {
    //     int aa = a[i];
    //     int bb = x - aa;
    //     int j = lowb(b, bb);
    //     if (j == n) continue;
    //     int has = a[i] + b[j];
    //     int other = min(i, j);
    //     if (i < j) {
    //         int l = i, r = j;
    //         while (r - l > 1) {
    //             int c = (l + r) / 2;
    //             int score = a[c + 1] + b[c];
    //             if (score >= has) r = c;
    //             else l = c;
    //         }
    //         // if (i == 0) show(l, r);
    //         other += r - i;
    //     } else if (i > j) {
    //         int l = j, r = i;
    //         while (r - l > 1) {
    //             int c = (l + r) / 2;
    //             int score = a[c] + b[c + 1];
    //             if (score >= has) r = c;
    //             else l = c;
    //         }
    //         other += r - j;
    //     }
    //     if (n - other == 6) {
    //         show(i, j, other);
    //     }
    //     ans = max(ans, n - other);
    // }
    cout << "1 " << ans << endl;

    return 0;
}