/*
    author:  Maksim1744
    created: 07.09.2020 15:10:03
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

bool in_word(char c) {
    if ('a' <= c && c <= 'z') return true;
    if ('A' <= c && c <= 'Z') return true;
    if ('0' <= c && c <= '9') return true;
    return false;
}

void test_case(int test) {
    int n;
    cin >> n;
    vector<string> names(n);
    cin >> names;
    vector<pair<int, string>> msg;
    int m;
    cin >> m;
    string s;
    getline(cin, s);
    vector<vector<int>> cant(m);
    for (int i = 0; i < m; ++i) {
        getline(cin, s);
        int ind = 0;
        while (s[ind] != ':') ++ind;
        string name = s.substr(0, ind);
        int iname;
        if (name == "?") {
            iname = -1;
        } else {
            iname = 0;
            while (names[iname] != name) ++iname;
        }
        msg.eb(iname, s.substr(ind + 1, s.size()));
        string t = msg.back().second;
        int iind = -1;
        for (auto name : names) {
            ++iind;
            bool ok = true;
            for (int i = 0; i + name.size() <= t.size(); ++i) {
                bool same = true;
                if (i != 0 && in_word(t[i - 1])) continue;
                if (i + name.size() < t.size() && in_word(t[i + name.size()])) continue;
                for (int j = 0; j < name.size(); ++j) {
                    if (name[j] != t[i + j]) {
                        same = false;
                        break;
                    }
                }
                if (same) {
                    ok = false;
                    break;
                }
            }
            if (!ok)
                cant[i].pb(iind);
        }
    }
    vector<vector<int>> can(m, vector<int>(n, 0));
    if (msg[0].first == -1) {
        for (int i = 0; i < n; ++i) {
            can[0][i] = 1;
        }
    } else {
        can[0][msg[0].first] = 1;
    }
    for (auto u : cant[0]) {
        can[0][u] = false;
    }
    set<int> base;
    for (int i = 0; i < n; ++i) {
        base.insert(i);
    }
    vector<vector<int>> from(m, vector<int>(n, -1));
    for (int i = 0; i + 1 < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (can[i][j]) {
                set<int> pos = base;
                if (msg[i + 1].first != -1) {
                    pos.clear();
                    pos.insert(msg[i + 1].first);
                }
                for (auto u : cant[i + 1]) {
                    pos.erase(u);
                }
                pos.erase(j);
                for (auto j1 : pos) {
                    can[i + 1][j1] = true;
                    from[i + 1][j1] = j;
                }
            }
        }
    }
    int x = m - 1, y = -1;
    for (int i = 0; i < n; ++i) {
        if (can[x][i]) {
            y = i;
            break;
        }
    }
    // printMatrix(can);
    if (y == -1) {
        cout << "Impossible\n";
        return;
    }
    vector<string> res;
    while (y != -1) {
        res.pb(names[y]);
        y = from[x][y];
        --x;
    }
    reverse(res.begin(), res.end());
    // show(res);
    for (int i = 0; i < m; ++i) {
        cout << res[i] << ":" << msg[i].second << '\n';
    }
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