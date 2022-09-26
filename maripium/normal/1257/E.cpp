#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200200;

int M;
int N[3];
int A[3][MAXN];
int ft[MAXN];

void updf(int p, int v) {
   for (; p <= M; p += p & -p) {
      ft[p] = max(ft[p], v);
   }
}

int getf(int p) {
   int ans = 0;
   for (; p > 0; p -= p & -p) {
      ans = max(ans, ft[p]);
   }
   return ans;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> N[0] >> N[1] >> N[2];
   for (int z = 0; z < 3; ++z) {
      M += N[z];
      for (int i = 0; i < N[z]; ++i) {
         cin >> A[z][i];
      }
      sort(A[z], A[z] + N[z]);
   }
   for (int z = 0; z < 3; ++z) {
      for (int i = 0; i < N[z]; ++i) {
         int dp = getf(A[z][i] - 1);
         updf(A[z][i], dp + 1);
      }
   }
   cout << M - getf(M) << "\n";
   return 0;
}