#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
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
  cout.sync_with_stdio(0);
  cin.tie(0);
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

void precalc() {}

template<typename T>
void relax_min(T& cur, T val) {
  cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
  cur = max(cur, val);
}

#define int li
const int mod = 1000000007;

int k, m;
vector<vector<int>> g;
int max_num;

vector<vector<vector<int>>> dp;

void add(int& cur, int val) {
    cur += val;
    cur %= mod;
}

enum Type {
    ANY = 0,
    NEI = 1,
    CHOSEN = 2
};

void dfs(int v, int p) {
    dp[v].assign(max_num + 1, vector<int>(3, 0));
    vector<vector<int>> cur_dp(max_num + 1, vector<int>(3, 0));
    cur_dp[0][ANY] = 1;
    cur_dp[1][CHOSEN] = 1;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v);
        vector<vector<int>> new_dp(max_num + 1, vector<int>(3, 0));
        for (int have = 0; have <= max_num; ++have) {
            for (int new_have = 0; new_have + have <= max_num; ++new_have) {
                add(new_dp[have + new_have][CHOSEN], cur_dp[have][CHOSEN] * dp[to][new_have][NEI]);
                add(new_dp[have + new_have][NEI], cur_dp[have][NEI] * (dp[to][new_have][CHOSEN] + dp[to][new_have][ANY]) % mod +
                    cur_dp[have][ANY] * dp[to][new_have][CHOSEN] % mod);
                add(new_dp[have + new_have][ANY], cur_dp[have][ANY] * dp[to][new_have][ANY]);
            }
        }
        cur_dp.swap(new_dp);
    }

    for (int have = 0; have <= max_num; ++have) {
        dp[v][have][CHOSEN] = cur_dp[have][CHOSEN];
        dp[v][have][ANY] = cur_dp[have][ANY] * (m - 1) % mod + cur_dp[have][NEI] * (k - 1) % mod;
        dp[v][have][ANY] %= mod;
        dp[v][have][NEI] = (cur_dp[have][ANY] + cur_dp[have][NEI]) * (k - 1) % mod;
    }

    /*cout << v + 1 << endl;
    for (int i = 0; i <= max_num; ++i) {
        cout << dp[v][i][0] << " " << dp[v][i][1] << " " << dp[v][i][2] << endl;
    }*/
}

void solve(bool read) {
    int n;
    cin >> n >> m;
    g.resize(n);
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin >> k >> max_num;
    dp.resize(n);
    dfs(0, 0);
    int ans = 0;
    for (int have = 0; have <= max_num; ++have) {
        ans += dp[0][have][ANY] + dp[0][have][CHOSEN];
        ans %= mod;
    }

    cout << ans << endl;

}