#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N;
   cin >> N;
   vector<int> P(N);
   bool all = true;
   for (int i = 0; i < N; ++i) {
      cin >> P[i];
      --P[i];
      all &= (i == P[i]);
   }
   if (all) {
      cout << N << "\n";
      for (int i = 0; i < N; ++i) {
         cout << string(N, '.') << "\n";
      }
      return 0;
   }
   int row = 0;
   vector<bool> visited(N);
   vector<string> ans(N, string(N, '.'));
   vector<int> last = {0};
   visited[0] = true;
   while (!visited[P[last.back()]]) {
      last.emplace_back(P[last.back()]);
      visited[last.back()] = true;
   }
   for (int i = 0; i < N; ++i) {
      if (P[i] == i) visited[i] = true;
      if (visited[i]) continue;
      int v = i;
      visited[v] = true;
      int start = row;
      while (!visited[P[v]]) {
         if (P[v] > v) {
            ans[row][v] = ans[row][P[v]] = '/';
         } else {
            ans[row][v] = ans[row][P[v]] = '\\';
         }
         v = P[v];
         visited[v] = true;
         row++;
      }
      if (i) {
         ans[row][v] = '\\';
         ans[row][0] = '\\';
         ans[start][0] = '/';
         row++;
      }
   }
   for (int i = 0; i + 1 < int(last.size()); ++i) {
      if (last[i] < last[i + 1]) {
         ans[row][last[i]] = ans[row][last[i + 1]] = '/';
      } else {
         ans[row][last[i]] = ans[row][last[i + 1]] = '\\';
      }
      row++;
   }
   cout << N - 1 << "\n";
   for (auto s : ans) cout << s << "\n";
}