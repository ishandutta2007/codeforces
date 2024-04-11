/*
    author:  Maksim1744
    created: 29.10.2020 16:17:19
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

    int n, q;
    cin >> n >> q;
    vector<int> lvl(n);
    vector<vector<int>> g(n);
    vector<char> e(n);
    e[0] = '.';
    for (int i = 0; i < n - 1; ++i) {
        int p;
        char c;
        cin >> p >> c;
        --p;
        g[p].pb(i + 1);
        e[i + 1] = c;
    }

    vector<pair<int, int>> up(n);
    vector<vector<int>> cnt(n, vector<int>(26, 0));
    vector<vector<vector<int>>> cnts(n, vector<vector<int>>(2, vector<int>(26, 0)));

    int cnt_bad = 0;
    int cnt_al = 0;

    vector<int> bad(n, false);

    function<void(int, int, int)> dfs1 = [&](int v, int upto, int side) {
        up[v] = mp(upto, side);
        lvl[v] = 0;
        if (g[v].size() == 0) return;
        if (g[v].size() == 1) {
            dfs1(g[v][0], upto, side);
            int k = g[v][0];
            lvl[v] = lvl[k] + 1;
            cnt[v] = cnt[k];
            if (e[k] != '?')
                cnt[v][e[k] - 'a']++;
            if (v == 0)
                cnts[v][0] = cnt[v];
            return;
        }
        assert(g[v].size() == 2);
        dfs1(g[v][0], v, 0);
        dfs1(g[v][1], v, 1);
        if (lvl[g[v][0]] != lvl[g[v][1]]) {
            for (int i = 0; i < q; ++i) {
                cout << "Fou\n";
            }
            exit(0);
        }
        lvl[v] = lvl[g[v][0]] + 1;
        cnts[v][0] = cnt[g[v][0]];
        cnts[v][1] = cnt[g[v][1]];
        if (e[g[v][0]] != '?') cnts[v][0][e[g[v][0]] - 'a']++;
        if (e[g[v][1]] != '?') cnts[v][1][e[g[v][1]] - 'a']++;
        for (int i = 0; i < 26; ++i) {
            cnt[v][i] = max(cnts[v][0][i], cnts[v][1][i]);
        }
        ++cnt_al;
        if (sum(cnt[v]) > lvl[v]) {
            ++cnt_bad;
            bad[v] = true;
        }
    };

    dfs1(0, 0, 0);

        shows;
        shows;
        shows;
        printTree(g, e);
        shows;
        printTree(g, cnts);
        shows;
        shows;
        shows;

    while (q--) {
        int v;
        char to;
        cin >> v >> to;
        --v;
        char from = e[v];
        vector<pair<char, int>> changes = {
            {from, -1},
            {to, 1}
        };
        e[v] = to;
        while (v != 0) {
            auto [p, side] = up[v];
            v = p;

            show(v, changes);

            vector<int> was_max(26);
            for (int i = 0; i < 26; ++i) {
                was_max[i] = max(cnts[v][0][i], cnts[v][1][i]);
            }

            for (auto [c, d] : changes) {
                if (c != '?') cnts[v][side][c - 'a'] += d;
            }

            changes.clear();

            for (int i = 0; i < 26; ++i) {
                int x = max(cnts[v][0][i], cnts[v][1][i]);
                if (was_max[i] != x) {
                    changes.eb('a' + i, x - was_max[i]);
                }
            }

            int bd = false;
            int s = 0;
            for (int i = 0; i < 26; ++i) {
                s += max(cnts[v][0][i], cnts[v][1][i]);
            }
            if (s > lvl[v]) bd = true;

            if (bd != bad[v]) {
                bad[v] ^= 1;
                if (bd) ++cnt_bad;
                else --cnt_bad;
            }
        }

        shows;
        shows;
        shows;
        printTree(g, e);
        shows;
        printTree(g, cnts);
        shows;
        shows;
        shows;

        if (cnt_bad == 0) {
            int score = 0;
            int left = lvl[0];
            for (int i = 0; i < 26; ++i) {
                left -= max(cnts[0][0][i], cnts[0][1][i]);
            }
            assert(left >= 0);
            for (int i = 0; i < 26; ++i) {
                score += (i + 1) * (left + max(cnts[0][0][i], cnts[0][1][i]));
            }
            cout << "Shi" << ' ' << score << '\n';
        } else {
            cout << "Fou\n";
        }
    }

    return 0;
}