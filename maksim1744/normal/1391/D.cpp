/*
    author:  Maksim1744
    created: 09.08.2020 17:46:20
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

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    cin >> v;
    if (n < m) {
        vector<string> v2(m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                v2[j].pb(v[i][j]);
            }
        }
        swap(v, v2);
        swap(n, m);
    }
    if (n >= 4 && m >= 4) {
        cout << -1 << '\n';
        return 0;
    }
    if (n == 1 || m == 1) {
        cout << 0 << '\n';
        return 0;
    }

    auto get_ans = [&](vector<int> &v) {
        vector<vector<int>> ans;
        vector<int> vv = v;
        for (int i = 0; i < 2; ++i) {
            vector<int> cur;
            if (i == 1) cur.pb(-1);

            for (int i = 0; i < v.size(); ++i) {
                if (v[i] == 1) {
                    v[i] = 0;
                    cur.pb(i);
                    if (i + 1 < v.size())
                        v[i + 1] = 1 - v[i + 1];
                }
            }

            ans.pb(cur);
            v = vv;
            v[i] = 1 - v[i];
        }
        return ans;
    };

    if (m == 2) {
        vector<int> e(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                e[i] += (v[i][j] == '1');
            }
            e[i] %= 2;
        }
        int best = n;
        for (int i = 0; i < 2; ++i) {
            int cur = 0;
            for (int j = 0; j < n; ++j) {
                if ((e[j] % 2) != (j + i) % 2) {
                    cur++;
                }
            }
            best = min(cur, best);
        }
        cout << best << '\n';
    } else {
        vector<vector<int>> bad(2, vector<int>(n - 1));
        for (int i = 0; i < n - 1; ++i) {
            bad[0][i] += (v[i][0] == '1');
            bad[0][i] += (v[i][1] == '1');
            bad[0][i] += (v[i + 1][0] == '1');
            bad[0][i] += (v[i + 1][1] == '1');

            bad[1][i] += (v[i][1] == '1');
            bad[1][i] += (v[i][2] == '1');
            bad[1][i] += (v[i + 1][1] == '1');
            bad[1][i] += (v[i + 1][2] == '1');

            bad[0][i] = (bad[0][i] % 2 == 0);
            bad[1][i] = (bad[1][i] % 2 == 0);
        }

        

        int ans = n * 25;
        auto v1 = get_ans(bad[0]);
        auto v2 = get_ans(bad[1]);
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                vector<int> v;
                for (auto u : v1[i]) {
                    v.pb(u);
                }
                for (auto u : v2[j]) {
                    v.pb(u);
                }
                sort(v.begin(), v.end());
                v.erase(unique(v.begin(), v.end()), v.end());
                ans = min(ans, (int)v.size());
            }
        }
        cout << ans << '\n';
        // auto bbad = bad;
        // reverse(bbad.begin(), bbad.end());
        // int ans = n * 2;
        // for (int i = 0; i < 2; ++i) {
            

        //     bad = bbad;
        // }
    }

    return 0;
}