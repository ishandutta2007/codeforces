#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <memory.h>
#include <random>
#include <ctime>

using namespace std;

constexpr int N = 200000, M = 60, P = 15, TRIES = 250;

int64_t longlike[N];
int popularity[M];
int like[N];
int n, m, p, ans;
int best_mask;
int cnt[1 << P];
vector<int> useful_cur;
int cur2useful[M];
unordered_map<int, int> useful2curcur;

void solve(int supermask) {
  memset(cnt, 0, sizeof cnt);
  useful2curcur.clear();
  int ones = __builtin_popcount(supermask), cmasks = 1 << ones;
  for (int mask = supermask; ; --mask &= supermask) {
    useful2curcur.emplace(mask, useful2curcur.size());
    if (!mask) {
      break;
    }
  }
  for (int i = 0; i < n; ++i) {
    ++cnt[useful2curcur[like[i] & supermask]];
  }
  for (int bit = 1; bit < cmasks; bit <<= 1) {
    for (int I = 0; I < cmasks; I += bit << 1)
    for (int i = I; i < I + bit; ++i) {
      cnt[i | bit] += cnt[i] ;
    }
  }
  for (int i = 0; i < cmasks; ++i) {
    if (cnt[i] * 2 < n) {
      continue;
    }
    int cans = ones - __builtin_popcount(i);
    if (ans >= cans) {
      continue;
    }
    ans = cans;
    best_mask = 0;
    for (int pref = supermask, pos = 0; pref; pref &= ~-pref, ++pos) {
      best_mask |= ((~i >> pos) & 1) * (pref & -pref);
    }
  }
}

int main()
{
  auto start = clock();
  cin.tie(0), ios::sync_with_stdio(0);
  cin >> n >> m >> p;
  useful2curcur.reserve(1 << -~-~-~p);
  cin.get();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (cin.get() == '1') {
        longlike[i] |= 1ll << j;
        ++popularity[j];
      }
    }
    cin.get();
  }
  for (int i = 0; i < m; ++i) {
    if (popularity[i] * 2 >= n) {
      for (int j = 0; j < n; ++j) {
        like[j] |= ((longlike[j] >> i) & 1) << useful_cur.size();
      }
      useful_cur.push_back(i);
      cur2useful[i] = useful_cur.size();
    }
  }
  vector<int> friends(n);
  iota(friends.begin(), friends.end(), 0);
  shuffle(friends.begin(), friends.end(), mt19937(time(0) + clock() + 1616841));
  auto mid = clock(), io = mid - start;
  for (int t = 0; t < min(TRIES, n); ++t) {
    solve(like[friends[t]]);
//    if ((clock() - mid) / (t + 1) * (t + 2) + io > 2.9 * CLOCKS_PER_SEC) {
//      break;
//    }
  }
  for (int i = 0; i < m; ++i) {
    cout << (cur2useful[i] && ((best_mask >> ~-cur2useful[i]) & 1));
  }
  return 0;
}