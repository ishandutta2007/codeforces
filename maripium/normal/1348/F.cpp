#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N;
   cin >> N;
   vector<int> L(N), R(N);
   vector<vector<int>> adds(N);
   for (int i = 0; i < N; ++i) {
      cin >> L[i] >> R[i];
      --L[i], --R[i];
      adds[L[i]].emplace_back(i);
   }
   multiset<pair<int, int>> ms;
   auto print = [&](vector<int> ord) {
      vector<int> perm(N);
      for (int i = 0; i < N; ++i) perm[ord[i]] = i;
      for (int v : perm) cout << v + 1 << " "; cout << "\n";
   };
   vector<int> ord(N);
   for (int l = 0; l < N; ++l) {
      for (int i : adds[l]) ms.emplace(R[i], i);
      ord[l] = ms.begin()->second;
      ms.erase(ms.begin());
   }
   vector<int> perm(N);
   for (int i = 0; i < N; ++i) perm[ord[i]] = i;
   vector<int> last(N);
   for (int i = 0; i < N; ++i) {
      if (i == 0 || R[ord[i - 1]] == i - 1) {
         last[i] = i;
      } else {
         last[i] = last[i - 1];
      }
   }
   for (int l = 0; l < N; ++l) {
      for (int i : adds[l]) ms.emplace(R[i], i);
      if (ms.size() >= 2) {
         int x = ms.begin()->second;
         int y = next(ms.begin())->second;
         if (last[perm[y]] <= R[x]) {
            vector<int> neword = ord;
            neword[l] = y;
            ms.erase(next(ms.begin()));
            for (++l; l < N; ++l) {
               for (int i : adds[l]) ms.emplace(R[i], i);
               neword[l] = ms.begin()->second;
               ms.erase(ms.begin());
            }
            cout << "NO\n";
            print(ord);
            print(neword);
            return 0;
         }
      }
      ms.erase(ms.begin());
   }
   cout << "YES\n";
   print(ord);
   return 0;
}