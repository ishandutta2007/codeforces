#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int N;
   cin >> N;
   vector<int> A(N);
   for (int i = 0; i < N; ++i) cin >> A[i];
   vector<int> cnts(30, 0);
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < 30; ++j) {
         cnts[j] += (A[i] >> j & 1);
      }
   }
   int bit = 29;
   while (bit >= 0 && cnts[bit] != 1) {
      bit--;
   }
   if (bit != -1) {
      for (int i = 0; i < N; ++i) {
         if (A[i] >> bit & 1) {
            swap(A[i], A[0]);
         }
      }
   }
   for (int v : A) cout << v << " ";
}