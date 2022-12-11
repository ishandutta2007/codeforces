#include <bits/stdc++.h>
using namespace std;

// This code uses the bossle/cp library
// Available at https://github.com/bossle/cp

typedef long long int lli;

// #pragma STDC FENV_ACCESS OFF
// #pragma STDC FP_CONTRACT ON
// #pragma STDC CX_LIMITED_RANGE ON
#pragma GCC optimize "O3"

namespace cp_base {

auto init = (
  ios::sync_with_stdio(false),
  cin.tie(nullptr)
);

}  // namespace cp_base

       

#define LOG(x) 

const int INF = 1e9+1;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> friends(1<<9, 0);
  for (int i=0; i<n; ++i) {
    int cur=0;
    int size;
    cin >> size;
    for (int j=0; j<size; ++j) {
      int k;
      cin >> k;
      cur |= 1<<(k-1);
    }
    friends[cur]++;
  }
  LOG(friends);
  vector<int> friendsAcum(friends);
  for (int b=1; b<(1<<9); b<<=1)
    for (int i=0; i<(1<<9); ++i)
      if ((i&b) == 0)
        friendsAcum[i|b] += friendsAcum[i];
  LOG(friendsAcum);
  map<int, vector<pair<int, int>>> cost;
  for (int i=0; i<m; ++i) {
    int cur=0;
    int c;
    cin >> c;
    int size;
    cin >> size;
    for (int j=0; j<size; ++j) {
      int k;
      cin >> k;
      cur |= 1<<(k-1);
    }
    cost[cur].emplace_back(c, i);
  }
  for (auto& p : cost) {
    sort(p.second.begin(), p.second.end());
    if (p.second.size() > 2)
      p.second.resize(2);
  }
  LOG(cost);
  int ans=0, ansCost=2*INF, ans0=1, ans1=2;
  for (auto p1 : cost)
    for (auto pz1 : p1.second)
      for (auto p2 : cost)
        for (auto pz2 : p2.second)
          if (pz1 != pz2) {
            int cand = friendsAcum[p1.first|p2.first];
            int candCost = pz1.first + pz2.first;
            LOG(make_tuple(pz1, pz2, cand, candCost, p1.first, p2.first));
            if (cand > ans || cand == ans && candCost < ansCost) {
              ans = cand;
              ansCost = candCost;
              ans0 = pz1.second+1;
              ans1 = pz2.second+1;
            }
          }
  LOG(ans);
  cout << ans0 << ' ' << ans1 << endl;
}