#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);

   int N; cin >> N;
   vector<vector<int>> A(N);
   for (int i = 0; i < N; ++i) {
      int S; cin >> S;
      A[i].resize(S);
      for (int j = 0; j < S; ++j) {
         cin >> A[i][j];
      }
   }

   int M; cin >> M;
   set<vector<int>> banned;
   for (int i = 0; i < M; ++i) {
      vector<int> B(N);
      for (int &a : B) cin >> a, --a;
      banned.insert(B);
   }
   priority_queue<pair<int, vector<int>>> hp;
   { // biggest
      int sum = 0;
      vector<int> B(N);
      for (int i = 0; i < N; ++i) {
         B[i] = int(A[i].size()) - 1;
         sum += A[i][B[i]];
      } 
      hp.push({sum, B});
   }

   set<vector<int>> visited;
   while (!hp.empty()) {
      auto [sum, B] = hp.top(); hp.pop();
      if (visited.count(B)) continue;
      visited.insert(B);
      if (!banned.count(B)) {
         for (int a : B) cout << a+1 << ' ';
         return 0;
      } 
      for (int i = 0; i < N; ++i) {
         if (B[i]) {
            vector<int> NB = B;
            int nsum = sum;
            NB[i] --;
            nsum -= A[i][B[i]];
            nsum += A[i][NB[i]];
            hp.push({nsum, NB});
         }
      }
   }
   return 0;
}