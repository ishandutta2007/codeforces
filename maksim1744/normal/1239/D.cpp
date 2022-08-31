/*
    author:  Maksim1744
    created: 20.10.2019 13:24:45
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
const int N = 10;
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
const int N = 1000020;
#endif

vector<vector<int>> g;
vector<vector<int>> gi;

array<int, N> topsort;
int topsort_i = 0;

array<bool, N> u;

void dfs1(int v) {
    u[v] = true;
    for (auto k : g[v])
        if (!u[k])
            dfs1(k);
    topsort[topsort_i++] = v;
}

void dfs2(int v) {
    u[v] = true;
    for (auto k : gi[v])
        if (!u[k])
            dfs2(k);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        g.clear();
        g.resize(n);
        gi.clear();
        gi.resize(n);
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            --a; --b;
            if (a != b) {
                g[a].pb(b);
                gi[b].pb(a);
            }
        }
        for (int i = 0; i < n; ++i)
            u[i] = false;
        topsort_i = 0;
        for (int i = 0; i < n; ++i) {
            if (!u[i])
                dfs1(i);
        }
        for (int i = 0; i < n; ++i)
            u[i] = false;
        dfs2(topsort[topsort_i - 1]);
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            if (!u[i]) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            vector<int> jury;
            vector<int> cats;
            for (int i = 0; i < n; ++i) {
                if (!u[i])
                    jury.pb(i + 1);
                else
                    cats.pb(i + 1);
            }
            cout << jury.size() << ' ' << cats.size() << '\n';
            cout << jury << '\n';
            cout << cats << '\n';
        }
        // showl;
    }
    return 0;
}