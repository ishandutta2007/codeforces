#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
   ios_base::sync_with_stdio(false);
   int N;
   cin >> N;
   ll ans = 0;
   priority_queue<int, vector<int>, greater<int>> q;
   for (int i = 0; i < N; ++i) {
      int v;
      cin >> v;
      q.emplace(v);
      q.emplace(v);
      ans += v - q.top();
      q.pop();
   }
   cout << ans << "\n";
   return 0;
}