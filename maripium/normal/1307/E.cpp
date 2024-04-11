#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int add(int x, int y) { return ((x += y) >= MOD) ? x - MOD : x; }
int mult(int x, int y) { return (long long) x * y % MOD; }

int main() {
   ios_base::sync_with_stdio(false);
   int N, M;
   cin >> N >> M;
   vector<int> S(N);
   vector<vector<int>> locs(N);
   for (int i = 0; i < N; ++i) {
      cin >> S[i]; --S[i];
      locs[S[i]].emplace_back(i);
   }
   vector<int> F(M), H(M);
   for (int i = 0; i < M; ++i) {
      cin >> F[i] >> H[i];
      --F[i];
   }
   vector<int> L(M, -1);
   vector<int> R(M, -1);
   for (int i = 0; i < M; ++i) {
      if (H[i] > int(locs[F[i]].size())) {
         continue;
      }
      L[i] = locs[F[i]][H[i] - 1];
      R[i] = locs[F[i]][int(locs[F[i]].size()) - H[i]];
   }
   int totAns = 0;
   int totWays = 1;
   for (int pv = -1; pv < N; ++pv) {
      vector<int> cntL(N);
      vector<int> cntR(N);
      vector<int> cntB(N);
      int curAns = 0;
      int curWays = 1;
      if (pv >= 0) {
         int id = -1;
         for (int i = 0; i < M; ++i) {
            if (L[i] == pv) {
               id = F[i];
            }
         }
         if (id == -1) continue;
         int cnts = 0;
         for (int i = 0; i < M; ++i) {
            if (L[i] == -1) continue;
            if (F[i] == id && R[i] > pv && L[i] != pv) {
               cnts++;
            }
         }
         curAns++;
         if (cnts) {
            curAns++;
            curWays = mult(curWays, cnts);
         }
      }
      for (int i = 0; i < M; ++i) {
         if (L[i] == -1) continue;
         if (L[i] <= pv) cntL[F[i]]++;
         if (R[i] > pv) cntR[F[i]]++;
         if (L[i] <= pv && R[i] > pv) cntB[F[i]]++;
      }
      for (int i = 0; i < N; ++i) {
         if (pv >= 0 && S[pv] == i) continue;
         int lmf = cntL[i] * cntR[i] - cntB[i];
         if (lmf) {
            curAns += 2;
            curWays = mult(curWays, lmf);
         } else if (cntL[i] + cntR[i]) {
            curAns++;
            curWays = mult(curWays, cntL[i] + cntR[i]);
         }
      }
      if (totAns < curAns) {
         totAns = curAns;
         totWays = 0;
      }
      if (totAns == curAns) {
         totWays = add(totWays, curWays);
      }
   }
   if (totAns == 0) totWays = 1;
   cout << totAns << " " << totWays << "\n";
}