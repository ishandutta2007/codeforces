#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200200;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N;
   cin >> N;
   map<int, vector<int>> cnts;
   for (int i = 0; i < N; ++i) {
      int x;
      cin >> x;
      for (int i = 2; i * i <= x; ++i) {
         if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) {
               x /= i;
               cnt++;
            }
            cnts[i].emplace_back(cnt);
         }
      }
      if (x > 1) cnts[x].emplace_back(1);
   }
   long long ans = 1;
   for (auto p : cnts) {
      int x = p.first;
      vector<int> as = p.second;
      sort(as.rbegin(), as.rend());
      int num = 0;
      if (as.size() < N - 1) num = 0;
      else num = as[N - 2];
      while (num--) ans *= x;
   }
   cout << ans << "\n";
}