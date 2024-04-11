/*
    author:  Maksim1744
    created: 19.11.2019 17:37:08
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

string al = "0123456789";

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    for (int i = 0; i < 26; ++i) {
        al.pb('a' + i);
        al.pb('A' + i);
    }
    int T;
    cin >> T;
    while (T--) {
        int r, c, k;
        cin >> r >> c >> k;
        vector<string> f(r);
        cin >> f;
        vector<pair<int, int>> snake;
        int x = 0, y = 0;
        for (int i = 0; i < r * c; ++i) {
            snake.emplace_back(x, y);
            if (x % 2 == 0)
                y++;
            else
                y--;
            if (y == -1) {
                y = 0;
                ++x;
            } else if (y == c) {
                y = c - 1;
                ++x;
            }
        }
        int sm = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (f[i][j] == 'R')
                    sm++;
            }
        }
        int rem = sm % k;
        int n1 = k - rem;
        int n2 = rem;
        int ind = 0;
        int cnt = 0;
        for (int i = 0; i < r * c; ++i) {
            if (f[snake[i].first][snake[i].second] == 'R')
                ++cnt;
            f[snake[i].first][snake[i].second] = al[ind];
            if ((ind < n1 && cnt == sm / k || ind >= n1 && cnt == sm / k + 1) && ind < k - 1) {
                assert(cnt > 0);
                ++ind;
                cnt = 0;
            }
        }
        for (int i = 0; i < r; ++i) {
            cout << f[i] << '\n';
        }
    }
    return 0;
}