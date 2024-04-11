/*
    author:  Maksim1744
    created: 17.08.2020 23:08:48
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

    int n, c;
    cin >> n >> c;
    vector<vector<int>> words(n);
    for (int i = 0; i < n; ++i) {
        int s;
        cin >> s;
        words[i].resize(s);
        cin >> words[i];
        --words[i];
    }
    if (c == 1) {
        for (int i = 0; i < n - 1; ++i) {
            if (words[i].size() > words[i + 1].size()) {
                cout << - 1 << '\n';
                return 0;
            }
        }
        cout << 0 << '\n';
        return 0;
    }
    vector<int> ad(c, 0);
    vector<int> dl(c, 0);
    int total = 0;
    for (int i = 0; i + 1 < n; ++i) {
        int ind = 0;
        while (ind < words[i].size() && ind < words[i + 1].size() && words[i][ind] == words[i + 1][ind]) {
            ++ind;
        }
        // show(words[i]);
        // show(words[i + 1]);
        // show(ind);
        if (ind == words[i].size()) continue;
        if (ind == words[i + 1].size()) {
            cout << -1 << '\n';
            return 0;
        }
        int a = words[i][ind];
        int b = words[i + 1][ind];
        int l = 0, r = c - 1;
        if (a < b) {
            l = -a;
            // l += c;
            r = c - 1 - b;
            show(a, b, l, r);
            ad[0]++;
            dl[r]--;
            if (l != 0) {
                ad[c + l]++;
                dl[c - 1]--;
            }
        } else {
            l = c - a;
            r = c - 1 - b;
            show(a, b, l, r);
            ad[l]++;
            dl[r]--;
        }
        ++total;
    }
    int cur = 0;
    for (int i = 0; i < c; ++i) {
        cur += ad[i];
        if (cur == total) {
            cout << i << '\n';
            return 0;
        }
        cur += dl[i];
    }
    cout << -1 << '\n';

    return 0;
}