#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int N;
   cin >> N;
   unordered_map<int, int> cnt;
   for (int i = 0; i < N; ++i) {
      int x;
      cin >> x;
      ++cnt[x];
   }
   vector<int> pref(N + 1);
   vector<int> suff(N + 1);
   for (auto p : cnt) {
      pref[p.second] += p.second;
      suff[p.second] += 1;
   }
   for (int i = 1; i <= N; ++i) {
      pref[i] += pref[i - 1];
   }
   for (int i = N - 1; i >= 0; --i) {
      suff[i] += suff[i + 1];
   }
   int bestP = 0;
   int bestS = 0;
   for (int curP = 1; curP <= N; ++curP) {
      int curS = pref[curP - 1] + curP * suff[curP];
      int curQ = curS / curP;
      if (curQ < curP) {
         continue;
      }
      curS = curP * curQ;
      if (curS > bestS) {
         bestP = curP;
         bestS = curS;
      }
   }
   int bestQ = bestS / bestP;
   vector<int> valsMore;
   vector<int> valsLess;
   for (auto p : cnt) {
      if (p.second >= bestP) {
         int curCnt = bestP;
         while (curCnt--) {
            valsMore.emplace_back(p.first);
         }
      } else {
         int curCnt = p.second;
         while (curCnt--) {
            valsLess.emplace_back(p.first);
         }
      }
   }
   for (int v : valsLess) {
      valsMore.emplace_back(v);
   }
   vector<vector<int>> ans(bestP, vector<int>(bestQ));
   for (int diag = 0; diag < bestQ; ++diag) {
      for (int z = 0; z < bestP; ++z) {
         ans[z][(diag + z) % bestQ] = valsMore[diag * bestP + z];
      }
   }
   cout << bestS << "\n" << bestP << " " << bestQ << "\n";
   for (auto vv : ans) {
      for (int v : vv) {
         cout << v << " ";
      }
      cout << "\n";
   }
   return 0;
}