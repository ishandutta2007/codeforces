/*
    author:  Maksim1744
    created: 22.08.2020 20:52:30
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

    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    vector<int> b;
    cin >> a;

    for (int spl = 0; spl <= n; ++spl) {
        int c4 = n, c2 = n * 2;
        c4 -= spl;
        c2 += spl;
        int c1 = spl;
        vector<int> b;
        vector<int> left(4, 0);
        for (auto k : a) {
            int x = k / 4;
            k -= x * 4;
            c4 -= x;
            if (k != 0) {
                left[k]++;
                b.pb(k);
            }
        }
        if (spl == 1) show(c1, c2, c4, left);
        while (c4 < 0) {
            c2 -= 2;
            c4++;
        }
        while (c2 < 0) {
            c2++;
            c1 -= 2;
        }
        if (c1 < 0 || c2 < 0 || c4 < 0) {
            continue;
        }
        int u = min(c4, left[3]);
        left[3] -= u;
        c4 -= u;
        if (c4 == 0) {
            while (left[3] != 0) {
                if (c2 != 0) {
                    --c2;
                    --c1;
                } else {
                    c1 -= 3;
                }
                --left[3];
            }
            while (c2 < 0) {
                c2++;
                c1 -= 2;
            }
            while (c1 < 0) {
                c1++;
                c2--;
            }
            if (c1 < 0 || c2 < 0) continue;
            while (left[2] != 0) {
                if (c2 != 0) {
                    --c2;
                } else {
                    c1 -= 2;
                }
                --left[2];
            }
            if (c1 < 0 || c2 < 0) continue;
            while (left[1] != 0) {
                if (c2 != 0) {
                    --c2;
                } else {
                    --c1;
                }
                --left[1];
            }
            if (c1 < 0 || c2 < 0) continue;
        } else {
            while (left[2] != 0) {
                if (c4 != 0) {
                    --c4;
                } else if (c2 != 0) {
                    --c2;
                } else {
                    c1 -= 2;
                }
                --left[2];
            }
            if (c1 < 0 || c2 < 0 || c4 < 0) continue;
            while (left[1] != 0) {
                if (c4 != 0) {
                    --c4;
                } else if (c2 != 0) {
                    --c2;
                } else {
                    --c1;
                }
                --left[1];
            }
            if (c1 < 0 || c2 < 0 || c4 < 0) continue;
        }
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";

    // int c4 = n, c2 = n * 2;
    // for (auto cnt : a) {
    //     int x = cnt / 4 * 4;
    //     c4 -= x / 4;
    //     cnt -= x;
    //     if (cnt == 0) continue;
    //     if (cnt == 3) {
    //         c4--;
    //         // continue;
    //         // b.pb(1);
    //         // b.pb(2);
    //         continue;
    //     }
    //     b.pb(cnt);
    // }

    // while (c4 < 0) {
    //     c4++;
    //     c2 -= 2;
    // }
    // if (c2 < 0) {
    //     cout << "NO\n";
    //     return 0;
    // }


    // int left1 = 0, left2 = 0;
    // for (auto u : b) {
    //     if (u == 1) ++left1;
    //     else if (u == 2) ++left2;
    //     else assert(false);
    // }
    // show(left1, left2, c2);
    // int mn = min({left1, left2, c4});
    // c4 -= mn;
    // left1 -= mn;
    // left2 -= mn;
    // show(left1, left2, c4, c2);
    // if (left1 == 0) {
    //     int left_cnt = c4 + c2;
    //     if (left2 > left_cnt) {
    //         cout << "NO\n";
    //     } else {
    //         cout << "YES\n";
    //     }
    //     return 0;
    // } else if (left2 == 0) {
    //     int left_cnt = c4 * 2 + c2;
    //     if (left1 > left_cnt) {
    //         cout << "NO\n";
    //     } else {
    //         cout << "YES\n";
    //     }
    //     return 0;
    // } else {
    //     assert(c4 == 0);
    //     int left_cnt = c2;
    //     if (left1 + left2 > left_cnt) {
    //         cout << "NO\n";
    //     } else {
    //         cout << "YES\n";
    //     }
    //     return 0;
    // }

    return 0;
}