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

void precalc() {

}

template<typename T>
void relax_min(T& cur, T val) {
  cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
  cur = max(cur, val);
}

#define int li
//const int mod = 1000000007;

vector<pair<int, int>> get_changes(int n) {
  vector<int> cand;
  for (int d = 1; d * d <= n * 2; ++d) {
    cand.push_back(d);
  }
  for (int x = 1; x * x <= n * 2; ++x) {
    int d = (n - 1) / x + 1;
    cand.push_back(d);
  }
  sort(all(cand));
  cand.erase(unique(all(cand)), cand.end());
  vector<pair<int, int>> res;
  int cur_sum = (n - 1) / cand[0] + 1;
  for (int i = 1; i < cand.size(); ++i) {
    int new_sum = (n - 1) / cand[i] + 1;
    if (new_sum != cur_sum) {
      res.push_back({cand[i], new_sum - cur_sum});
      cur_sum = new_sum;
    }
  }
  return res;
}

const int INF = (int)1e18;

int mult(int a, int b) {
  if (b == 0) {
    return 0;
  }
  if (a > INF / b) {
    return INF;
  }
  return a * b;
}

void solve(bool read) {
  //read = false;
  int n, k;
  if (read) {
    cin >> n >> k;
  } else {
    n = 100;
    k = 100000000000LL;
  }
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    if (read) {
      cin >> a[i];
    } else {
      a[i] = rand() % 1000000001;
    }
  }

  int cur_sum = 0;
  for (int i = 0; i < n; ++i) {
    cur_sum += a[i];
  }
  int all_sum = cur_sum;

  vector<pair<int, int>> events;
  events.push_back({1, 0});
  for (int i = 0; i < n; ++i) {
    int num = a[i];
    auto changes = get_changes(num);
    for (auto item : changes) {
      events.push_back(item);
    }
  }
  sort(all(events));
  int ans = 1;

  for (int i = 0; i < events.size(); ) {
    int min_d = events[i].first;
    int j = i;
    while (j < events.size() && events[j].first == events[i].first) {
      cur_sum += events[j].second;
      ++j;
    }
    i = j;
    int max_d = (k + all_sum) / cur_sum;
    if (i < events.size()) {
      max_d = min(max_d, events[i].first - 1);
    }
    if (max_d >= min_d) {
      ans = max_d;
    }
  }

  cout << ans << endl;

}