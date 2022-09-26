#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int T; cin >> T;
   while (T--) {
      int N; double L;
      auto read = [&](double &d) {
         int _d; cin >> _d;
         d = _d;
      };
      cin >> N; read(L);
      vector<double> A(N+2);
      A[0] = 0;
      A[N+1] = L;
      for (int i = 1; i <= N; ++i) read(A[i]);
      double lx = 0;
      double rx = L;
      double ls = 1;
      double rs = 1;
      int lid = 0;
      int rid = N+1;
      double cur = 0;
      while (lid < rid) {
         if (lid + 1 == rid) {
            cout << fixed << setprecision(10) << cur + (rx - lx) / (ls + rs) << '\n';
            break;
         }
         double lt = (A[lid+1] - lx) / ls;
         double rt = (rx - A[rid-1]) / rs;
         double nt = min(lt, rt);
         lx += ls * nt;
         rx -= rs * nt;
         cur += nt;
         if (nt == lt) {
            lid ++;
            ls ++;
         } else {
            rid --;
            rs ++;
         }
      }
   }
}