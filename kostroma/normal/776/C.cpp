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

#define int li

//const int mod = 1000000007;

const int INF = (int)1e16;

vector<int> compress;

int get_id(int val) {
  auto it = lower_bound(all(compress), val);
  if (it == compress.end() || *it != val) {
    return -1;
  }
  return it - compress.begin();
}

void solve(bool read) {
  //read = false;
  int n, k;
  if (read) {
    cin >> n >> k;
  } else {
    n = 100000;
    k = 2;
  }
  vector<int> a(n + 1);
  for (int i = 0; i < n; ++i) {
    if (read) {
      cin >> a[i + 1];
    } else {
      a[i + 1] = rand();
    }
    a[i + 1] += a[i];
  }
  for (int x : a) {
    compress.push_back(x);
  }
  sort(all(compress));
  compress.erase(unique(all(compress)), compress.end());

  int step = 1;
  vector<int> have;
  int ans = 0;
  while (abs(step) < INF) {
    have.assign(compress.size(), 0);
    for (int i = n; i >= 0; --i) {
      int need = a[i] + step;
      int cur_id = get_id(need);
      if (cur_id != -1) {
        ans += have[cur_id];
      }
      ++have[get_id(a[i])];
    }
    if (k == 1) {
      break;
    }
    if (k == -1 && step == -1) {
      break;
    }
    step = step * k;
  }
  cout << ans << "\n";

}