/*
    author:  Maksim1744
    created: 22.08.2020 14:46:47
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

    pair<int, int> a, b, c;
    cin >> a >> b >> c;
    int area = a.first * a.second + b.first * b.second + c.first * c.second;
    int n = 0;
    while (n * n < area) ++n;
    if (n * n != area) {
        cout << -1 << endl;
        return 0;
    }
    vector<pair<pair<int, int>, char>> v;
    v.eb(a, 'A');
    v.eb(b, 'B');
    v.eb(c, 'C');
    sort(v.begin(), v.end());
    int u = 0;
    do {
        for (int iii = 0; iii < 2; ++iii) {
            swap(v[0].first.first, v[0].first.second);
            for (int jjj = 0; jjj < 2; ++jjj) {
                swap(v[1].first.first, v[1].first.second);
                for (int kkk = 0; kkk < 2; ++kkk) {
                    swap(v[2].first.first, v[2].first.second);
                    ++u;
                    vector<string> res(n, string(n, '*'));
                    bool ok = true;
                    show(v);
                    for (int x = 0; x < 3; ++x) {
                        show(x, v);
                        int i0 = -1, j0 = -1;
                        for (int i = 0; i < n; ++i) {
                            for (int j = 0; j < n; ++j) {
                                if (res[i][j] == '*') {
                                    i0 = i;
                                    j0 = j;
                                    break;
                                }
                            }
                            if (i0 != -1) break;
                        }
                        show(i0, j0);
                        assert(i0 != -1);
                        for (int i = 0; i < v[x].first.first; ++i) {
                            for (int j = 0; j < v[x].first.second; ++j) {
                                if (i + i0 >= n || j + j0 >= n || res[i + i0][j + j0] != '*') {
                                    ok = false;
                                    break;
                                }
                                res[i + i0][j + j0] = v[x].second;
                            }
                            if (!ok) break;
                        }
                        if (!ok) break;
                        cout << endl;
                    }
                    if (ok) {
                        cout << n << '\n';
                        for (auto s : res) {
                            cout << s << '\n';
                        }
                        return 0;
                    }
                }
            }
        }
    } while (next_permutation(v.begin(), v.end()));
    cout << -1 << '\n';

    return 0;
}