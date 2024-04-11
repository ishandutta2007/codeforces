/*
    author:  Maksim1744
    created: 07.05.2019 16:26:29
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}

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
#define showt(...)       42;
#define printTree(...)   42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

const int nax = 100007;
array<pair<int, int>, nax> dp;
array<int, nax> mem;
array<int, nax> ans;

int main() {
    mem.fill(-1);
    ans.fill(0);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    auto start_time = clock();
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<int>> g1(n);
    vector<bool> used(n, false);
    vector<int> topsort(n); int top_ind = -1;
    function<void(int)> dfs0 = [&](int v) {
        used[v] = true;
        for (auto k : g[v])
            if (!used[k]) {
                g1[v].pb(k);
                dfs0(k);
            }
        topsort[++top_ind] = v;
    };
    dfs0(0);
    show(g1, topsort);
    // reverse(topsort.begin(), topsort.end());
    auto ask = [&](int k) {
        if (k > n)
            return 0;
        if (mem[k] != -1)
            return mem[k];
        for (auto v : topsort) {
            dp[v] = {0, 0};
            int mx1 =  0, mx2 = 0;
            for (auto u : g1[v]) {
                dp[v].first += dp[u].first;
                if (dp[u].second >= mx1) {
                    mx2 = mx1;
                    mx1 = dp[u].second;
                } else if (dp[u].second > mx2) {
                    mx2 = dp[u].second;
                }
            }
            if (mx1 + mx2 + 1 >= k)
                ++dp[v].first;
            else
                dp[v].second = mx1 + 1;
        }
        mem[k] = dp[0].first;
        return dp[0].first;
    };
    int K = min(n, 700);
    for (int i = 1; i <= K; ++i)
        ans[i] = ask(i);
    // for (int i = 1; i <= n + 1; ++i)
    //     cout << "ask(" << i << ") = " << ask(i) << '\n';
    int L = K + 1;
    int f = ask(L);
    while (f > 0) {
        // show(L, f);
        int l = L, r = n + 1;
        // int d = 1;
        // while (ask(r) == f) {
        //     l = r;
        //     r += d;
        //     d *= 2;
        // }
        // r = min(r, n + 1);
        while (r - l > 1) {
            int c = (l + r) / 2;
            int u = ask(c);
            if (u >= f)
                l = c;
            else
                r = c;
        }
        // show(l, r);
        for (int i = L; i <= l; ++i)
            ans[i] = f;
        // int f1 = ask(r);
        // assert(f1 < f);
        // f = f1;
        // assert(r > L);
        L = r;
        f = ask(L);
        if (1.0 * (clock() - start_time) / CLOCKS_PER_SEC > 6.9)
            break;
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << '\n';
    return 0;
}