/*
    author:  Maksim1744
    created: 16.05.2021 11:10:10
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

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

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

void test_case(int test) {
    int n, m;
    cin >> n >> m;
    vector<int> ans(n, -1);
    vector<pair<pair<int, char>, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first.first;
        v[i].second = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first.second;
    }
    sort(v.begin(), v.end());
    vector<deque<pair<int, int>>> cur(2);
    for (auto [xd, i] : v) {
        auto [x, d] = xd;
        if (d == 'R') {
            cur[x % 2].eb(x, i);
        } else {
            if (!cur[x % 2].empty()) {
                auto [xx, ii] = cur[x % 2].back();
                cur[x % 2].pop_back();
                ans[i] = ans[ii] = abs(x - xx) / 2;
            } else {
                cur[x % 2].emplace_front(-x, i);
            }
        }
    }
    for (int i = 0; i < 2; ++i) {
        while (cur[i].size() >= 2) {
            auto [x, j] = cur[i].back();
            cur[i].pop_back();
            auto [xx, jj] = cur[i].back();
            cur[i].pop_back();
            ans[j] = ans[jj] = (m - x) + (x - xx) / 2;
        }
    }
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