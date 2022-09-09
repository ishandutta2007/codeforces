#pragma comment(linker, "/STACK:512000000")
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(__attribute__((unused)) bool);
void precalc();
clock_t start;
#define FILENAME ""

int main() {
#ifdef AIM
    string s = FILENAME;
//    assert(!s.empty());
    freopen("/home/alexandero/ClionProjects/cryptozoology/input.txt", "r", stdin);
#else
//    freopen(FILENAME ".in", "r", stdin);
//    freopen(FILENAME ".out", "w", stdout);
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
//    cin >> t;
    int testNum = 1;
    while (t--) {
        //cout << "Case #" << testNum++ << ": ";
        solve(true);
    }
    cout.flush();
#ifdef AIM1
    while (true) {
      solve(false);
  }
#endif

#ifdef AIM
    cout.flush();
    auto end = clock();

    usleep(10000);
    print_stats(end - start);
    usleep(10000);
#endif

    return 0;
}

void precalc() {
}

template<typename T>
inline T nxt() {
    T cur;
    cin >> cur;
    return cur;
}

#define int li
const int mod = 1000000007;

vector<int> vals;
vector<vector<int>> g;
vector<array<int, 2>> dp_down;

void dfs1(int v, int p) {
    dp_down[v][0] = 1;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs1(to, v);
        dp_down[v][0] += dp_down[to][1];
        dp_down[v][1] += dp_down[to][0];
    }
    //cout << v + 1 << " " << dp_down[v][0] << " " << dp_down[v][1] << "\n";
}

int RES = 0;

void dfs2(int v, int p, array<int, 2> dp_up) {
    //cout << v + 1 << " " << dp_up[0] << " " << dp_up[1] << "\n";
    vector<array<int, 2>> dps;
    int sum_second = 0;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dps.push_back({dp_down[to][1] - dp_down[to][0], dp_down[to][0] + dp_down[to][1]});
    }
    dps.push_back({dp_up[0] - dp_up[1], dp_up[0] + dp_up[1]});
    dps.push_back({1, 1});
    for (auto cur_dp : dps) {
        sum_second += cur_dp[1];
        sum_second %= mod;
    }

    /*cout << "v: " << v + 1 << "\n";
    for (auto cur_dp : dps) {
        cout << cur_dp[0] << " " << cur_dp[1] << "\n";
    }*/

    for (auto cur_dp : dps) {
        //cout << "scored: " << cur_dp[0] * (sum_second - cur_dp[1]) << "\n";
        RES += cur_dp[0] * (sum_second - cur_dp[1]) % mod * vals[v];
        RES %= mod;
    }
    RES += vals[v];

    //cout << "res: " << RES << "\n";

    RES %= mod;
    if (RES < 0) {
        RES += mod;
    }
    swap(dp_up[0], dp_up[1]);
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        for (int i = 0; i < 2; ++i) {
            dp_up[i] = (dp_up[i] + dp_down[to][i]) % mod;
        }
    }
    ++dp_up[1];
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        auto new_up = dp_up;
        for (int i = 0; i < 2; ++i) {
            new_up[i] -= dp_down[to][i];
            if (new_up[i] < 0) {
                new_up[i] += mod;
            }
        }
        dfs2(to, v, new_up);
    }
}

void solve(__attribute__((unused)) bool read) {
    int n;
    cin >> n;
    vals.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> vals[i];
    }
    g.resize(n);
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    array<int, 2> emp;
    emp.fill(0);
    dp_down.assign(n, emp);
    dfs1(0, 0);
    dfs2(0, 0, emp);

    if (RES < 0) {
        RES += mod;
    }
    cout << RES << "\n";

}