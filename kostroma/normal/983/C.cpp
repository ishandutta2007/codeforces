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
  freopen("/home/alexandero/CLionProjects/ACM/input.txt", "r", stdin);
  //freopen("/home/alexandero/CLionProjects/ACM/output.txt", "w", stdout);
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
  cout.precision(20);
  cout << fixed;
  //cin >> t;
  precalc();
  while (t--) {
    solve(true);
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
void make_unique(vector<T>& vec) {
  sort(all(vec));
  vec.erase(unique(all(vec)), vec.end());
}

template<typename T>
void relax_min(T& cur, T val) {
  cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
  cur = max(cur, val);
}

void precalc() {

}

//#define int li
//const li mod = 1000000007;

//using ull = unsigned long long;

struct State {
  int current_floor;
  vector<int> need_floors;
  int HASH = 0;
  void calc_hash() {
    HASH = 0;
    for (int x : need_floors) {
      HASH = HASH * 31 + (x + 1);
    }
  }
  bool operator < (const State& ot) const {
    if (current_floor != ot.current_floor) {
      return current_floor < ot.current_floor;
    }
    return HASH < ot.HASH;
    return need_floors < ot.need_floors;
  }
};

void solve(bool read) {
  int n;
  //read = false;
  if (read) {
    cin >> n;
  } else {
    n = 2000;
  }
  vector<map<State, int>> mapa(n + 1);
  State start_state = {0, {}};
  start_state.calc_hash();
  mapa[0][start_state] = 0;
  queue<pair<int, State>> q;
  q.push({0, start_state});
  vector<pair<int, int>> want(n);
  for (int i = 0; i < n; ++i) {
    if (read) {
      cin >> want[i].first >> want[i].second;
      --want[i].first;
      --want[i].second;
    } else {
      do {
        want[i].first = rand() % 10;
        want[i].second = rand() % 10;
      } while (want[i].first == want[i].second);
    }
  }
  int res = (int)1e9;
  while (!q.empty()) {
    int pref = q.front().first;
    auto cur_state = q.front().second;
    int cur_d = mapa[pref][cur_state];
    q.pop();
    int floor = cur_state.current_floor;
    for (int shift = -1; shift <= 1; shift += 2) {
      int new_floor = floor + shift;
      if (new_floor < 0 || new_floor > 9) {
        continue;
      }
      State new_state = {new_floor, cur_state.need_floors};
      new_state.calc_hash();
      if (!mapa[pref].count(new_state)) {
        mapa[pref][new_state] = cur_d + 1;
        q.push({pref, new_state});
      }
    }

    vector<int> new_need_floors;
    for (int x : cur_state.need_floors) {
      if (x != floor) {
        new_need_floors.push_back(x);
      } else {
        ++cur_d;
      }
    }
    while (pref < n && new_need_floors.size() < 4 && want[pref].first == floor) {
      new_need_floors.push_back(want[pref].second);
      ++cur_d;
      ++pref;
    }
    if (pref == n && new_need_floors.empty()) {
      res = min(res, cur_d);
    }
    sort(all(new_need_floors));
    for (int shift = -1; shift <= 1; shift += 2) {
      int new_floor = floor + shift;
      if (new_floor < 0 || new_floor > 9) {
        continue;
      }
      State new_state = {new_floor, new_need_floors};
      new_state.calc_hash();
      if (!mapa[pref].count(new_state)) {
        mapa[pref][new_state] = cur_d + 1;
        q.push({pref, new_state});
      }
    }
  }

  cout << res << "\n";

}