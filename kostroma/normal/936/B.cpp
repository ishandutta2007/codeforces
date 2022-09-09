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
#ifdef AIM
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

void solve(bool read) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        while (k--) {
            int cur;
            cin >> cur;
            --cur;
            g[i].push_back(cur);
        }
    }
    int st;
    cin >> st;
    --st;
    vector<vector<int>> can(n, vector<int>(2, -1));
    queue<pair<int, int>> q;
    q.push({st, 0});
    while (!q.empty()) {
        auto item = q.front();
        q.pop();
        int v = item.first, par = item.second;
        for (int to : g[v]) {
            if (can[to][par ^ 1] == -1) {
                can[to][par ^ 1] = v;
                q.push({to, par ^ 1});
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (g[i].size() == 0 && can[i][1] != -1) {
            cout << "Win\n";
            vector<int> res;
            int cur = i, par = 1;
            while (cur != st || par != 0) {
                res.push_back(cur);
                cur = can[cur][par];
                par ^= 1;
            }
            res.push_back(st);
            reverse(all(res));
            for (int x : res) {
                cout << x + 1 << " ";
            }
            cout << "\n";
            return;
        }
    }

    vector<int> deg(n);
    int reachable = 0;
    for (int i = 0; i < n; ++i) {
        if (can[i][0] == -1 && can[i][1] == -1 && i != st) {
            continue;
        }
        ++reachable;
        for (int to : g[i]) {
            ++deg[to];
        }
    }
    if (deg[st] > 0) {
        cout << "Draw\n";
        return;
    }
    vector<int> order;
    order.push_back(st);
    for (int i = 0; i < order.size(); ++i) {
        int v = order[i];
        for (int to : g[v]) {
            --deg[to];
            if (deg[to] == 0) {
                order.push_back(to);
            }
        }
    }
    if (order.size() == reachable) {
        cout << "Lose\n";
    } else {
        cout << "Draw\n";
    }

}