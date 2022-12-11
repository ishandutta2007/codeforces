#include <bits/stdc++.h>
using namespace std;

// This code uses the bossle/cp library
// Available at https://github.com/bossle/cp

// #pragma STDC FENV_ACCESS OFF
// #pragma STDC FP_CONTRACT ON
// #pragma STDC CX_LIMITED_RANGE ON
// #pragma GCC optimize "O3"

namespace cp_base {

auto init = (
  ios::sync_with_stdio(false),
  cin.tie(nullptr)
);

}  // namespace cp_base

       

#define LOG(x) 

typedef long long int lli;

int main() {
  int n, m;
  cin >> n >> m;
  lli bounty, increase, damage;
  cin >> bounty >> increase >> damage;
  vector<lli> maxHealth(n), startHealth(n), regen(n);
  for (int i=0; i<n; ++i)
    cin >> maxHealth[i] >> startHealth[i] >> regen[i];
  vector<vector<pair<lli, lli>>> updates(n);
  for (int i=0; i<m; ++i) {
    lli time, enemy, health;
    cin >> time >> enemy >> health;
    updates[enemy-1].emplace_back(time, health);
  }
  for (int i=0; i<n; ++i)
    updates[i].emplace_back(0, startHealth[i]);
  for (auto& v : updates)
    sort(v.begin(), v.end());
  map<lli, int> diff;
  for (int i=0; i<n; ++i) {
    if (maxHealth[i] <= damage) {
      diff[0]++;
      continue;
    }
    int cur=0;
    for (int j=0; j<updates[i].size(); ++j) {
      int next = (updates[i][j].second <= damage ? 1 : 0);
      diff[updates[i][j].first] += next-cur;
      cur = next;
      if (cur == 1 && regen[i] > 0) {
        int stop = updates[i][j].first + (damage+1-updates[i][j].second + regen[i]-1)/regen[i];
        if (j+1 == updates[i].size() || updates[i][j+1].first > stop) {
          diff[stop]--;
          cur = 0;
        }
      }
    }
  }
  lli best=0, acum=0;
  for (auto p : diff) {
    LOG(p);
    LOG(acum);
    best = max(best, acum*(bounty + (p.first-1)*increase));
    acum += p.second;
  }
  if (acum > 0 && increase > 0)
    best = -1;
  else
    best = max(best, acum*bounty);
  cout << best << endl;
}