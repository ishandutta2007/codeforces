#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
   ios_base::sync_with_stdio(false);
   int N;
   cin >> N;
   ll X = 0;
   for (int i = 0; i < N; ++i) {
      ll B;
      cin >> B;
      ll A = B + X;
      cout << A << " ";
      X = max(X, A);
   }
}