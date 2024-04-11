/*
    author:  Maksim1744
    created: 11.06.2020 17:43:30
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

void test_case() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vals(n, vector<int>(m));
    cin >> vals;
    // printMatrix(vals);
    vector<vector<int>> num(n, vector<int>(m, -1));
    num[0][0] = 0;
    set<pair<int, int>> cur;
    cur.emplace(0, 0);
    int cnt = 1;
    while (!cur.empty()) {
        set<pair<int, int>> next;
        for (auto [a, b] : cur) {
            if (a + 1 < n) next.emplace(a + 1, b);
            if (b + 1 < m) next.emplace(a, b + 1);
        }
        for (auto [a, b] : next) {
            num[a][b] = cnt;
        }
        ++cnt;
        swap(next, cur);
    }
    --cnt;
    --cnt;
    // show(cnt);
    // printMatrix(num);
    vector<set<int>> g(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // lines[i * m + j].pb(vals[i][j]);
            for (int x = i; x < n; ++x) {
                for (int y = j; y < m; ++y) {
                    if (num[i][j] + num[x][y] == cnt && (i != x || y != j)) {
                        g[i * m + j].insert(x * m + y);
                        g[x * m + y].insert(i * m + j);
                    }
                }
            }
            // int x = min(num[i][j], cnt - num[i][j]);
            // lines[x].pb(vals[i][j]);
        }
    }
    vector<int> col(g.size(), -1);
    int color = 0;
    function<void(int)> dfs = [&](int v) {
        col[v] = color;
        for (auto k : g[v]) {
            if (col[k] == -1)
                dfs(k);
        }
    };
    for (int i = 0; i < g.size(); ++i) {
        if (col[i] == -1) {
            dfs(i);
            ++color;
        }
    }
    vector<vector<int>> lines(color);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            lines[col[i * m + j]].pb(vals[i][j]);
        }
    }

    // show(lines);
    int ans = 0;
    for (auto v : lines) {
        map<int, int> mm;
        for (auto k : v) {
            mm[k]++;
        }
        int mx = 0;
        for (auto [a, b] : mm) {
            mx = max(mx, b);
        }
        ans += v.size() - mx;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        test_case();
    }

    return 0;
}