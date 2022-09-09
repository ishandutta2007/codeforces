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
//int timer = 1;

int testNumber = 1;

bool todo = true;

int main() {
#ifdef AIM
  freopen("/home/alexandero/CLionProjects/ACM/input.txt", "r", stdin);
  //freopen("/home/alexandero/CLionProjects/ACM/output.txt", "w", stdout);
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
    //cerr << testNum << endl;
    //cout << "Case #" << testNum++ << ": ";
    solve(true);
    ++testNumber;
    //++timer;
  }

  /*while (true) {
      solve(false);
  }*/

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

void precalc() {

}

//#define int li

//const int mod = 1000000007;


void solve(bool read) {
  int n;
  cin >> n;
  vector<vector<int>> a(2);
  for (int i = 0; i < 2; ++i) {
    int k;
    cin >> k;
    a[i].resize(k);
    for (int j = 0; j < k; ++j) {
      cin >> a[i][j];
    }
  }
  vector<int> deg(2 * n);
  for (int pos = 0; pos < n; ++pos) {
    for (int turn = 0; turn < 2; ++turn) {
      int cur_v = 2 * pos + turn;
      deg[cur_v] = (int)a[turn].size();
    }
  }
  vector<int> state(2 * n, -1);
  queue<int> q;
  state[0] = state[1] = 0;
  q.push(0);
  q.push(1);
  while (!q.empty()) {
    int cur_v = q.front();
    q.pop();
    int pos = cur_v / 2;
    int turn = cur_v % 2;
    //cout << pos << " " << turn << " " << state[cur_v] << endl;
    for (int x : a[turn ^ 1]) {
      int nex_pos = (pos - x + n) % n;
      int to = 2 * nex_pos + (turn ^ 1);
      if (state[cur_v] == 0) {
        if (state[to] == -1) {
          state[to] = 1;
          q.push(to);
        }
      } else {
        if (state[to] == -1 && --deg[to] == 0) {
          state[to] = 0;
          q.push(to);
        }
      }
    }
  }

  for (int turn = 0; turn < 2; ++turn) {
    for (int v = 1; v < n; ++v) {
      int res = state[2 * v + turn];
      if (res == -1) {
        cout << "Loop ";
      } else if (res == 1) {
        cout << "Win ";
      } else {
        cout << "Lose ";
      }
    }
    cout << "\n";
  }

}