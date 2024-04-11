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

int dp[251][251][251];
int nextOcc[100002][26];

int main() {
  int n, q;
  cin >> n >> q;
  string wu;
  cin >> wu;
  for (int i=n; i<n+2; ++i)
    for (int j=0; j<26; ++j)
      nextOcc[i][j] = n;
  for (int i=n-1; i>=0; --i) {
    for (int j=0; j<26; ++j)
      nextOcc[i][j] = nextOcc[i+1][j];
    nextOcc[i][wu[i]-'a'] = i;
  }
  vector<string> rel(3);
  dp[0][0][0] = 0;
  for (int qa=0; qa<q; ++qa) {
    char type;
    int i;
    cin >> type >> i;
    i--;
    LOG(type);
    if (type == '+') {
      char c;
      cin >> c;
      rel[i].push_back(c);
      vector<int> cur(3);
      vector<int> old(3);
      for (cur[0]=(i==0 ? rel[0].size() : 0); cur[0]<=rel[0].size(); ++cur[0])
        for (cur[1]=(i==1 ? rel[1].size() : 0); cur[1]<=rel[1].size(); ++cur[1])
          for (cur[2]=(i==2 ? rel[2].size() : 0); cur[2]<=rel[2].size(); ++cur[2]) {
            dp[cur[0]][cur[1]][cur[2]] = n+1;
            for (int j=0; j<3; ++j) {
              if (cur[j] == 0)
                continue;
              old = cur;
              old[j]--;
              int cand = dp[old[0]][old[1]][old[2]];
              cand = nextOcc[cand][rel[j][old[j]]-'a']+1;
              dp[cur[0]][cur[1]][cur[2]] = min(dp[cur[0]][cur[1]][cur[2]], cand);
            }
          }
      dp[0][0][0] = 0;
    } else {
      rel[i].pop_back();
    }

    cout << (dp[rel[0].size()][rel[1].size()][rel[2].size()] <= n ? "YES" : "NO") << '\n';
  }
}