// source: https://codeforces.com/contest/618/problem/F

#pragma optimize("-Ofast")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
   // ios_base::sync_with_stdio(false);
   int T;
   scanf("%d", &T);
   while (T--) {
      int N;
      scanf("%d", &N);
      vector<int> A(N);
      int id = -1;
      for (int i = 0; i < N; ++i) {
         scanf("%d", &A[i]);
         if (A[i] == 0) {
            id = i;
         }
      }
      if (id != -1) {
         cout << "1\n" << " " << id + 1 << "\n";
         continue;
      }
      vector<pair<int, int>> posVals;
      vector<pair<int, int>> negVals;
      ll posSum = 0;
      ll negSum = 0;
      for (int i = 0; i < N; ++i) {
         if (A[i] > 0) {
            posSum += A[i];
            posVals.emplace_back(A[i], i);
         } else {
            negSum -= A[i];
            negVals.emplace_back(-A[i], i);
         }
      }
      if (posSum > negSum) {
         swap(posVals, negVals);
      }
      for (int zz = 0; zz < 50; ++zz) {
      shuffle(posVals.begin(), posVals.end(), rng);
      shuffle(negVals.begin(), negVals.end(), rng);
      vector<int> la(N + 1, -1);
      vector<int> lb(N + 1, -1);
      la[0] = 0;
      lb[0] = 0;
      posSum = 0;
      negSum = 0;
      int ptr = 0;
      for (int i = 0; i < posVals.size(); ++i) {
         posSum += posVals[i].first;
         while (negSum < posSum) {
            negSum += negVals[ptr++].first;
         }
         int delta = negSum - posSum;
         assert(delta <= N);
         if (la[delta] != -1) {
            cout << i - la[delta] + 1 + ptr - lb[delta] << "\n";
            for (int z = la[delta]; z <= i; ++z) {
               cout << posVals[z].second + 1 << " ";
            }
            for (int z = lb[delta]; z < ptr; ++z) {
               cout << negVals[z].second + 1 << " ";
            }
            cout << "\n";
            goto next_test;
         }
         la[delta] = i + 1;
         lb[delta] = ptr;
      }
      }
      next_test:;
   }
}