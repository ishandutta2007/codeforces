#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
/*#if !defined(YCM) && 0
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx,tune=native")
#include <stdio.h>
#endif*/
//#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
int main() {
#ifdef AIM
    freopen("/home/alexandero/ClionProjects/ACM/input.txt", "r", stdin);
    //freopen("/home/alexandero/ClionProjects/ACM/output.txt", "w", stdout);
    //freopen("out.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;
#ifndef AIM
    cout.sync_with_stdio(0);
    cin.tie(0);
#endif
    precalc();
    cout.precision(10);
    cout << fixed;
    //cin >> t;
    int testNum = 1;
    while (t--) {
        //cout << "Case #" << testNum++ << ": ";
        //cerr << testNum << endl;
        solve(true);
        //cerr << testNum - 1 << endl;
    }
    cout.flush();
#ifdef AIM1
    while (true) {
      solve(false);
  }
#endif

#ifdef AIM
    cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

template<typename T>
T binpow(T q, T w, T mod) {
    if (!w)
        return 1 % mod;
    if (w & 1)
        return q * 1LL * binpow(q, w - 1, mod) % mod;
    return binpow(q * 1LL * q % mod, w / 2, mod);
}

template<typename T>
T gcd(T q, T w) {
    while (w) {
        q %= w;
        swap(q, w);
    }
    return q;
}
template<typename T>
T lcm(T q, T w) {
    return q / gcd(q, w) * w;
}

template <typename T>
void make_unique(vector<T>& a) {
    sort(all(a));
    a.erase(unique(all(a)), a.end());
}

template<typename T>
void relax_min(T& cur, T val) {
    cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
    cur = max(cur, val);
}

void precalc() {}

//#define int li
//const int mod = 1000000007;

vector<vector<int>> g, revg;

void add_edge(int a, int b) {
    g[a].push_back(b);
    revg[b].push_back(a);
    //cout << "addding " << a << " " << b << endl;
}

vector<char> used;
vector<int> order;

void dfs1(int v) {
    if (used[v]) return;
    used[v] = true;
    for (int to : g[v]) {
        dfs1(to);
    }
    order.push_back(v);
}

vector<int> num_comp;

void dfs2(int v, int cnt) {
    if (num_comp[v] != -1) return;
    num_comp[v] = cnt;
    for (int to : revg[v]) {
        dfs2(to, cnt);
    }
}

void solve(bool read) {
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> u(n);
    g.resize(n);
    revg.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> u[i];
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        if ((u[a] + 1) % h == u[b]) {
            add_edge(a, b);
        }
        if ((u[b] + 1) % h == u[a]) {
            add_edge(b, a);
        }
    }
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs1(i);
        }
    }
    reverse(all(order));
    num_comp.assign(n, -1);
    int cnt = 0;
    for (int v : order) {
        if (num_comp[v] == -1) {
            dfs2(v, cnt++);
        }
    }
    vector<int> deg(cnt, 0), sizes(cnt, 0);
    for (int i = 0; i < n; ++i) {
        ++sizes[num_comp[i]];
        for (int to : g[i]) {
            int a = num_comp[i], b = num_comp[to];
            if (a != b) {
                ++deg[a];
            }
        }
    }
    int res = n + 1;
    int best_comp = -1;
    for (int i = 0; i < cnt; ++i) {
        if (deg[i] == 0 && sizes[i] < res) {
            res = sizes[i];
            best_comp = i;
        }
    }
    cout << sizes[best_comp] << "\n";
    for (int i = 0; i < n; ++i) {
        if (num_comp[i] == best_comp) {
            cout << i + 1 << " ";
        }
    }
    cout << "\n";

}