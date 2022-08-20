/*
    author:  Maksim1744
    created: 10.03.2021 15:29:58
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
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...)     42
#define mclock        42
#define shows         42
#define debug if (false)
#endif

void test_case(int test) {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    cin >> v;
    int ind = -1;
    for (int i = 0; i < n; ++i) {
        if (count(v[i].begin(), v[i].end(), 'X') != 0) {
            ind = i;
            break;
        }
    }
    if (n == 1) {
        v[0].assign(v[0].size(), 'X');
        cout << v[0] << '\n';
        return;
    }
    if (ind == -1) {
        for (auto s : v) {
            cout << s << '\n';
        }
        return;
    }
    for (int i = 1; i < n; i += 3) {
        for (int j = 0; j < m; ++j) {
            v[i][j] = 'X';
        }
    }
    for (int i = 2; i + 2 < n; i += 3) {
        bool ook = false;
        for (int j = 0; j < m; ++j) {
            bool ok = true;
            if (j != 0) {
                if (v[i][j - 1] == 'X' || v[i + 1][j - 1] == 'X') {
                    ok = false;
                }
            }
            if (j + 1 != m) {
                if (v[i][j + 1] == 'X' || v[i + 1][j + 1] == 'X') {
                    ok = false;
                }
            }
            if (!ok) continue;
            ook = true;
            v[i][j] = v[i + 1][j] = 'X';
            break;
        }
        assert(ook);
    }
    show(v);
    if (n % 3 == 1) {
        set<int> cur;
        for (int j = 0; j < m; ++j) {
            if (v[n - 2][j] == 'X')
                cur.insert(j);
        }
        if (cur.empty()) {
            v[n - 2][0] = 'X';
            cur.insert(0);
        }
        int i = n - 1;
        cur.insert(-1e9);
        cur.insert(1e9);
        show(cur);
        show(v.back());
        for (int j = 0; j < m; ++j) {
            if (v[i][j] == 'X') {
                auto itr = cur.lower_bound(j);
                auto itl = prev(itr);
                if (j - *itl <= *itr - j) {
                    int x = j - 1;
                    while (x >= *itl && v[i][x] != 'X') {
                        show(x);
                        v[i][x] = 'X';
                        --x;
                    }
                } else {
                    int x = j + 1;
                    while (x <= *itr && v[i][x] != 'X') {
                        show(x);
                        v[i][x] = 'X';
                        ++x;
                    }
                }
            }
        }
    }
    show(v);
    for (auto s : v) {
        cout << s << '\n';
    }
    // auto un_seg = [&](int i) {
    //     int l = -1;
    //     int r = -1;
    //     for (int j = 0; j < m; ++j) {
    //         if (v[i][j] == 'X') {
    //             if (l == -1) l = j;
    //             r = j;
    //         }
    //     }
    //     assert(l != -1);
    //     for (int j = l; j <= r; ++j)
    //         v[i][j] = 'X';
    // };
    // un_seg(ind);
    // set<int> cur;
    // for (int j = 0; j < m; ++j) {
    //     if (v[ind][j] == 'X')
    //         cur.insert(j);
    // }
    // for (int i = ind + 1; i < n; ++i) {
        // if (count(v[i].begin(), v[i].end(), 'X') == 0) {
        //     while (cur.size() > 1)
        //         cur.erase(cur.begin());
        //     v[i][*cur.begin()] = 'X';
        //     continue;
        // }
        // cur.clear();
        // for (int j = 0; j < m; ++j) {
        //     if (v[i][j] == 'X')
        //         cur.insert(j);
        // }
    // }
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