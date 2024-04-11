#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int N, M;
   cin >> N >> M;
   vector<string> S(N), T(M);
   for (int i = 0; i < N; ++i) cin >> S[i];
   for (int i = 0; i < M; ++i) cin >> T[i];
   int Q;
   cin >> Q;
   while (Q--) {
      int year;
      cin >> year;
      --year;
      cout << S[year % N] << T[year % M] << "\n";
   }
}