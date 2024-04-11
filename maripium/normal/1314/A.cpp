#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
   ios_base::sync_with_stdio(false);
   int N;
   cin >> N;
   vector<int> A(N), T(N);
   for (int i = 0; i < N; ++i) cin >> A[i];
   for (int i = 0; i < N; ++i) cin >> T[i];
   vector<pair<int, int>> vals;
   for (int i = 0; i < N; ++i) {
      vals.emplace_back(A[i], T[i]);
   }
   sort(vals.begin(), vals.end());
   int l = 0;
   ll ans = 0;
   while (l < N) {
      int curA = vals[l].first;
      int r = l;
      while (r + 1 < N && curA >= vals[r + 1].first) {
         curA++;
         r++;
      }
      priority_queue<ll> q;
      ll qSum = 0;
      int curL = curA - r + l;
      int ptr = l;
      for (int i = curL; i <= curA; ++i) {
         while (ptr <= r && vals[ptr].first <= i) {
            qSum += vals[ptr].second;
            q.emplace(vals[ptr++].second);
         }
         qSum -= q.top(); q.pop();
         ans += qSum;
      }
      l = r + 1;
   }
   cout << ans << "\n";
   return 0;
}