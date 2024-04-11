#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

void add(int &x, int y) {
   x += y;
   if (x >= MOD) x -= MOD;
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   string S; cin >> S;
   int tail = 0;
   while (S.size() && S.back() == '0') {
      tail++;
      S.pop_back();
   }
   if (S.empty()) {
      cout << tail << "\n";
      return 0;
   }
   reverse(S.begin(), S.end());
   int head = 0;
   while (S.size() && S.back() == '0') {
      head++;
      S.pop_back();
   }
   reverse(S.begin(), S.end());
   int N = S.size();
   S = '~' + S;
   vector<int> nxt0(N + 1);
   vector<int> nxt1(N + 1);
   {
      int last = N + 1;
      for (int i = N; i >= 0; --i) {
         nxt1[i] = last;
         if (S[i] == '1') last = i;
      }
   }
   {
      vector<int> go(N + 1);
      for (int i = 0; i <= N; ++i) {
         if (S[i] != '0') go[i] = 0;
         else go[i] = go[i - 1] + 1;
      }
      vector<int> last(N + 2, N + 1);
      for (int i = N; i >= 0; --i) {
         nxt0[i] = last[go[i] + 1];
         last[go[i]] = i;
      }
   }
   vector<int> dp(N + 1);
   dp[1] = 1;
   for (int i = 1; i <= N; ++i) {
      if (nxt0[i] != N + 1) add(dp[nxt0[i]], dp[i]);
      if (nxt1[i] != N + 1) add(dp[nxt1[i]], dp[i]);
   }
   int ans = 0;
   for (int i = 1; i <= N; ++i) if (S[i] == '1') add(ans, dp[i]);
   ans = ll(ans) * (head + 1) % MOD;
   ans = ll(ans) * (tail + 1) % MOD;
   cout << ans << "\n";
   return 0;
}