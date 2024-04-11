#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N, K; cin >> N >> K;
   auto AskOr = [&](int i, int j) {
      cout << "or " << i + 1 << ' ' << j + 1 << '\n';
      cout << endl;
      int64_t ans; cin >> ans;
      return ans;
   };
   auto AskAnd = [&](int i, int j) { 
      cout << "and " << i + 1 << ' ' << j + 1 << '\n';
      cout << endl;
      int64_t ans; cin >> ans;
      return ans;
   };
   auto AskSum = [&](int i, int j) {
      return AskOr(i, j) + AskAnd(i, j);
   };
   auto Answer = [&](int v) {
      cout << "finish " << v << '\n';
      cout << flush;
   };
   int64_t S01 = AskSum(0, 1);
   int64_t S02 = AskSum(0, 2);
   int64_t S12 = AskSum(1, 2);
   vector<int64_t> A(N);
   A[0] = (S01 + S02 - S12) / 2;
   A[1] = (S01 + S12 - S02) / 2;
   A[2] = (S02 + S12 - S01) / 2;
   for (int i = 3; i < N; ++i) {
      A[i] = AskSum(0, i) - A[0];
   }
   sort(A.begin(), A.end());
   Answer(A[K - 1]);
   return 0;
}