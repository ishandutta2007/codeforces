/*
    author:  Maksim1744
    created: 25.07.2021 18:03:23
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
#include "/mnt/c/C++ libs/print.cpp"
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
    vector<int> c(n * k);
    cin >> c;
    --c;
    vector<vector<int>> where(n);
    for (int i = 0; i < c.size(); ++i) {
        where[c[i]].pb(i);
    }

    vector<pair<int, int>> ans;

    auto solve = [&](vector<vector<int>> inds) {
        show(inds);
        for (int i = 0; i < inds.size(); ++i) {
            reverse(inds[i].begin(), inds[i].end());
        }
        vector<int> cur(inds.size());
        iota(cur.begin(), cur.end(), 0);
        int n = inds.size();
        for (int it = 0; it < n; ++it) {
            int ind = -1;
            for (int i : cur) {
                if (ind == -1 || inds[ind][inds[ind].size() - 2] > inds[i][inds[i].size() - 2]) {
                    ind = i;
                }
            }
            assert(ind != -1);
            assert(inds[ind].size() >= 2);
            ans.eb(inds[ind].back(), inds[ind][inds[ind].size() - 2]);
            int r = ans.back().second;
            cur.erase(find(cur.begin(), cur.end(), ind));

            for (int i : cur) {
                while (!inds[i].empty() && inds[i].back() <= r)
                    inds[i].pop_back();
            }
        }
    };

    for (int i = 0; i < where.size(); i += k - 1) {
        solve(vector(where.begin() + i, (i + k - 1 < where.size() ? where.begin() + i + k - 1 : where.end())));
        show(ans);
    }

    sort(ans.begin(), ans.end(), [&](const auto &a, const auto &b) {
        return c[a.first] < c[b.first];
    });

    for (auto [l, r] : ans) {
        cout << l + 1 << ' ' << r + 1 << '\n';
    }

    return 0;
}