#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N; cin >> N;
   int ans = 0, K = 1;
   for (int z = 1; z <= N; ++z) {
      int cur = N - z - (N + z - 1) / z + 1;
      if (cur > ans) {
         ans = cur;
         K = z;
      }
   }
   unordered_set<int> moves;
   for (int i = 0; i < N; ++i) if (i % K) moves.emplace(i);
   while (int(moves.size()) >= K) {
      cout << K;
      for (int i = 0; i < K; ++i) {
         cout << " " << *moves.begin() + 1;
         moves.erase(moves.begin());
      }
      cout << endl;
      int start; cin >> start;
      --start;
      for (int i = 0; i < K; ++i) {
         if (start % K) moves.emplace(start);
         start = (start + 1) % N;
      }
   }
   cout << 0 << endl;
}