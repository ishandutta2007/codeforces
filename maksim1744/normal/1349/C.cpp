/*
    author:  Maksim1744
    created: 12.05.2020 16:00:07
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

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<bool>> col(n, vector<bool>(m));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            col[i][j] = (s[j] == '1');
        }
    }
    vector<vector<bool>> isconst = col;
    vector<vector<int>> cstep(n, vector<int>(m, 0));
    auto ccol = col;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            bool has_sim = false;
            if (i != 0 && col[i - 1][j] == col[i][j]) has_sim = true;
            if (i != n - 1 && col[i + 1][j] == col[i][j]) has_sim = true;
            if (j != 0 && col[i][j - 1] == col[i][j]) has_sim = true;
            if (j != m - 1 && col[i][j + 1] == col[i][j]) has_sim = true;
            isconst[i][j] = has_sim;
            if (has_sim) ++cnt;
        }
    }
    if (cnt == 0) {
        for (int i = 0; i < q; ++i) {
            ll a, b, c;
            cin >> a >> b >> c;
            --a; --b;
            bool ans = col[a][b];
            // if (c % 2 == 1) ans = !ans;
            cout << (int)ans << '\n';
        }
        return 0;
    }
    vector<pair<int, int>> vconst;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (isconst[i][j]) vconst.eb(i, j);
        }
    }
    int step = 0;
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!vconst.empty()) {
        vector<pair<int, int>> next;
        ++step;
        for (auto [a, b] : vconst) {
            for (auto [da, db] : dirs) {
                if (a + da >= 0 && a + da < n && b + db >= 0 && b + db < m) {
                    if (!isconst[a + da][b + db]) {
                        int cab = col[a][b];
                        if ((step - cstep[a][b]) % 2 == 1)
                            cab = !cab;
                        if (col[a + da][b + db] == cab) {
                            isconst[a + da][b + db] = true;
                            cstep[a + da][b + db] = step;
                            next.eb(a + da, b + db);
                            ccol[a + da][b + db] = cab;
                        } else {
                            next.eb(a, b);
                        }
                    }
                }
            }
        }
        swap(next, vconst);
    }
    // printMatrix(cstep);
    // shows;
    // printMatrix(ccol);
    // shows;
    for (int iii = 0; iii < q; ++iii) {
        int i, j;
        ll p;
        cin >> i >> j >> p;
        --i; --j;
        if (p < cstep[i][j]) {
            cout << (int)col[i][j] << '\n';
        } else {
            ll d = p - cstep[i][j];
            int ans = ccol[i][j];
            if (d % 2 == 1) ans = 1 - ans;
            cout << ans << '\n';
        }
    }

    return 0;
}