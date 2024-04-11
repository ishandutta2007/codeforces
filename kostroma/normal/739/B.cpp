#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <bitset>
#include <deque>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>
#include <unordered_map>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve();
void precalc();
clock_t start;
//int timer = 1;

int testNumber = 1;

bool todo = true;

int main() {
#ifdef AIM
  freopen("/home/alexandero/ClionProjects/ACM/input.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#else
  //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
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
    solve();
    ++testNumber;
    //++timer;
  }

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

template <typename T>
using Matrix = vector<vector<T>>;

#define int li

//const int mod = 1000000007;

const int L = 18;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<int>> parent(L, vector<int>(n, -1));
  vector<vector<int>> sum(L, vector<int>(n, 1e18));
  vector<vector<int>> adds(L, vector<int>(n, 0));

  for (int i = 1; i < n; ++i) {
    int p, w;
    cin >> p >> w;
    --p;
    parent[0][i] = p;
    sum[0][i] = w;
  }

  for (int i = 1; i < L; ++i) {
    for (int j = 0; j < n; ++j) {
      if (parent[i - 1][j] != -1) {
        parent[i][j] = parent[i - 1][parent[i - 1][j]];
        if (parent[i][j] == -1) {
          continue;
        }
        sum[i][j] = sum[i - 1][j] + sum[i - 1][parent[i - 1][j]];
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    int cur = i;
    for (int j = L - 1; j >= 0; --j) {
      if (sum[j][cur] <= a[i] && parent[j][cur] != -1) {
        a[i] -= sum[j][cur];
        ++adds[j][cur];
        cur = parent[j][cur];
      }
    }
  }

  for (int i = L - 1; i > 0; --i) {
    for (int j = 0; j < n; ++j) {
      if (parent[i][j] == -1) {
        continue;
      }
      int add = adds[i][j];
      adds[i - 1][j] += add;
      adds[i - 1][parent[i - 1][j]] += add;
    }
  }

  vector<int> res(n);
  for (int i = 0; i < n; ++i) {
    if (parent[0][i] != -1) {
      res[parent[0][i]] += adds[0][i];
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << res[i] << " ";
  }

}