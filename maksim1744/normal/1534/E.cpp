/*
    author:  Maksim1744
    created: 13.06.2021 19:00:19
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> cur(n, 1);
    int sm = n;
    int ind = 0;

    auto check = [&]() {
        if (sm % k != 0) return;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = {cur[i], i};
        }
        vector<vector<int>> ans;
        while (true) {
            sort(v.rbegin(), v.rend());
            while (!v.empty() && v.back().first == 0) v.pop_back();
            if (v.empty()) {
                // show(ans);
                int x = 0;
                for (auto v : ans) {
                    ++v;
                    cout << "? " << v << endl;
                    int u;
                    cin >> u;
                    x ^= u;
                }
                cout << "! " << x << endl;
                exit(0);
            }
            if (v.size() < k) return;
            ans.eb();
            for (int i = 0; i < k; ++i) {
                v[i].first--;
                ans.back().pb(v[i].second);
            }
        }
    };

    while (cur[0] < n + 5) {
        check();
        cur[ind] += 2;
        sm += 2;
        ind = (ind + 1) % n;
    }

    cout << -1 << endl;

    return 0;
}