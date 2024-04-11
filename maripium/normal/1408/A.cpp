#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int T; cin >> T;
   while (T--) {
      int N; cin >> N;
      vector<int> A(N), B(N), C(N);
      for (int &a : A) cin >> a;
      for (int &b : B) cin >> b;
      for (int &c : C) cin >> c;
      vector<int> P(N);
      int prv = -1;
      for (int i = 0; i < N-1; ++i) {
         for (int v : {A[i], B[i], C[i]}) {
            if (v != prv) {
               prv = v;
               P[i] = v;
               break;
            }
         }
      }
      for (int v : {A[N-1], B[N-1], C[N-1]}) {
         if (v != prv && v != P.front()) {
            P.back() = v;
         }
      }
      for (int p : P) cout << p << ' '; cout << '\n';
   }
}