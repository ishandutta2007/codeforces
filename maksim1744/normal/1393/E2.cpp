/*
    author:  Maksim1744
    created: 07.08.2020 18:33:39
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

const ll mod = 1e9 + 7;

int charcomp(string& s1, string& s2, int i1, int i2) {
    if (i1 == s1.size() && i2 == s2.size()) return 0;
    if (i1 == s1.size()) return -1;
    if (i2 == s2.size()) return 1;
    if (s1[i1] < s2[i2]) return -1;
    return 1;
}

int comp(string& s1, string& s2, int del1, int del2, vector<int>& same, vector<int>& samel, vector<int>& samer) {
    if (del1 > del2) return -comp(s2, s1, del2, del1, same, samer, samel);

    if (del1 == -1) {
        if (del2 == -1) {
            return charcomp(s1, s2, same[0], same[0]);
        }
        if (same[0] < del2) {
            return charcomp(s1, s2, same[0], same[0]);
        }
        int ln = samer[del2];
        return charcomp(s1, s2, del2 + ln + 0, del2 + ln + 1);
    }

    if (same[0] < min(del1, del2)) {
        return charcomp(s1, s2, same[0], same[0]);
    }

    int ln = samel[del1];
    if (ln >= del2 - del1) {
        ln = same[del2 + 1];
        return charcomp(s1, s2, del2 + 1 + ln, del2 + 1 + ln);
    }
    return charcomp(s1, s2, del1 + ln + 1, del1 + ln + 0);
}

int comp_easy(string& s1, string& s2, int del1, int del2) {
    int i1 = 0, i2 = 0;
    if (i1 == del1) ++i1;
    if (i2 == del2) ++i2;
    while (i1 < s1.size() && i2 < s2.size()) {
        if (s1[i1] != s2[i2]) {
            return (s1[i1] < s2[i2] ? -1 : 1);
        }

        ++i1; ++i2;
        if (i1 == del1) ++i1;
        if (i2 == del2) ++i2;
    }

    if (i1 == s1.size() && i2 == s2.size()) return 0;
    if (i1 == s1.size()) return -1;
    if (i2 == s2.size()) return 1;
    assert(false);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<string> v(n);
    cin >> v;
    vector<vector<int>> ord(n);
    for (int i = 0; i < n; ++i) {
        string s = v[i];
        int m = s.size();
        vector<int> tor(m, 1);
        for (int j = m - 2; j >= 0; --j) {
            if (s[j] == s[j + 1]) tor[j] = tor[j + 1] + 1;
            else tor[j] = 1;
        }
        for (int j = 0; j < m; ++j) {
            ord[i].pb(j);
        }
        ord[i].pb(-1);
        function<int(int, int)> cmp = [&](int x, int y) {
            if (x == y) return 0;

            if (x == -1) {
                if (tor[y] >= m - y) return 1;
                char cy = s[y + tor[y]];
                char cx = s[y];
                if (cx < cy) return -1;
                else return 1;
            } else if (y == -1) {
                return -cmp(y, x);
            }

            if (x < y) {
                if (tor[x] >= y - x + 1) return 0;
                char cx = s[x + tor[x]];
                char cy = s[x];
                if (cx < cy) return -1;
                else return 1;
            } else {
                return -cmp(y, x);
            }
        };
        sort(ord[i].begin(), ord[i].end(), [&](int x, int y) {
            return cmp(x, y) < 0;
        });
        // for (int j = 0; j + 1 < ord[i].size(); ++j) {
        //     bool ok = (comp(v[i], v[i], ord[i][j], ord[i][j + 1]) <= 0);
        //     if (!ok) {
        //         // cout << v[i] << endl;
        //         // cout << ord[i] << endl;
        //         // cout << ord[i][j] << ' ' << ord[i][j + 1] << endl;
        //         // cout << cmp(ord[i][j], ord[i][j + 1]) << endl;
        //         // show(tor);
        //         // return 1;
        //         assert(false);
        //     }
        // }
    }

    vector<vector<pair<int, ll>>> res(n);
    for (int i = 0; i < ord[0].size(); ++i) {
        res[0].eb(ord[0][i], 1);
    }
    for (int i = 1; i < n; ++i) {
        int ind = 0;
        ll sm = 0;

        int m = max(v[i].size(), v[i - 1].size()) + 5;
        int mn = min(v[i].size(), v[i - 1].size()) + 2;
        vector<int> same(m, 0), samel(m, 0), samer(m, 0);
        for (int j = mn - 1; j >= 0; --j) {
            if (j >= v[i].size() || j >= v[i - 1].size()) continue;
            if (v[i][j] == v[i - 1][j]) {
                same[j] = same[j + 1] + 1;
            } else {
                same[j] = 0;
            }
        }
        for (int j = mn - 1; j >= 0; --j) {
            if (j >= v[i].size() || j + 1 >= v[i - 1].size()) continue;
            if (v[i][j] == v[i - 1][j + 1]) {
                samel[j] = samel[j + 1] + 1;
            } else {
                samel[j] = 0;
            }
        }
        for (int j = mn - 1; j >= 0; --j) {
            if (j + 1 >= v[i].size() || j >= v[i - 1].size()) continue;
            if (v[i][j + 1] == v[i - 1][j]) {
                samer[j] = samer[j + 1] + 1;
            } else {
                samer[j] = 0;
            }
        }

        for (int j = 0; j < ord[i].size(); ++j) {
            res[i].eb(ord[i][j], 0);
            while (ind < res[i - 1].size()) {
                int ans = comp(v[i - 1], v[i], res[i - 1][ind].first, res[i][j].first, same, samel, samer);
                // if (ans != comp_easy(v[i - 1], v[i], res[i - 1][ind].first, res[i][j].first)) {
                //     cout << v[i - 1] << ' ' << res[i - 1][ind].first << endl;
                //     cout << v[i] << ' ' << res[i][j].first << endl;
                //     show(ans);
                //     show(same);
                //     show(samel);
                //     show(samer);
                //     return 0;
                // }
                if (ans <= 0) {
                    sm += res[i - 1][ind].second;
                    ++ind;
                    continue;
                } else {
                    break;
                }
            }
            res[i].back().second = sm % mod;
        }
    }

    ll ans = 0;
    for (auto [a, b] : res.back()) {
        ans += b;
    }
    cout << ans % mod << '\n';

    return 0;
}