/*
    author:  Maksim1744
    created: 13.03.2021 14:01:59
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));
    cin >> a >> b;
    if (a == b) {
        cout << 0 << '\n';
        return 0;
    }
    vector<pair<vector<int>, int>> bb(n);
    for (int i = 0; i < n; ++i) {
        bb[i] = {b[i], i};
    }
    sort(bb.begin(), bb.end());
    vector<pair<vector<int>, int>> aa(n);
    for (int i = 0; i < n; ++i) {
        aa[i] = {a[i], i};
    }
    sort(aa.begin(), aa.end());

    for (int i = 0; i < n; ++i) {
        if (aa[i].first != bb[i].first) {
            cout << -1 << '\n';
            return 0;
        }
        a[aa[i].second].pb(aa[i].second);
        b[bb[i].second].pb(aa[i].second);
    }
    // show(a);
    // show(b);
    ++m;

    set<int> bad;
    set<pair<int, int>> s;
    vector<int> val(m, 0);
    vector<vector<int>> blocked(n - 1);
    vector<int> blockcnt(m, 0);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            val[j] += (b[i][j] < b[i + 1][j]);
            if (b[i][j] > b[i + 1][j]) {
                blocked[i].pb(j);
                blockcnt[j]++;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        s.emplace(-val[i], i);
    }
    for (int i = 0; i < n - 1; ++i) {
        bad.insert(i);
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int k : blocked[i])
            s.erase({-val[k], k});
    }
    vector<int> ans;
    while (!bad.empty()) {
        if (s.empty()) {
            cout << -1 << '\n';
            return 0;
        }
        shows;
        auto [vv, j] = *s.begin();
        s.erase(s.begin());
        show(a);
        show(b);
        show(bad);
        show(vv, j);
        show(val);
        // if (-vv < bad.size()) {
        //     cout << -1 << '\n';
        //     return 0;
        // }
        if (j != m - 1)
            ans.pb(j);
        for (int i = 0; i < n - 1; ++i) {
            if (!bad.count(i)) continue;
            if (b[i][j] == b[i + 1][j]) continue;
            if (b[i][j] > b[i + 1][j]) {
                cout << -1 << '\n';
                return 0;
            }
            assert(b[i][j] < b[i + 1][j]);
            for (int k = 0; k < m; ++k) {
                if (b[i][k] < b[i + 1][k]) {
                    if (s.count({-val[k], k})) {
                        s.erase({-val[k], k});
                        val[k]--;
                        s.insert({-val[k], k});
                    } else {
                        val[k]--;
                    }
                }
            }
            bad.erase(i);
            for (int k : blocked[i]) {
                --blockcnt[k];
                if (blockcnt[k] == 0)
                    s.emplace(-val[k], k);
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    ++ans;
    cout << ans << '\n';

    return 0;
}