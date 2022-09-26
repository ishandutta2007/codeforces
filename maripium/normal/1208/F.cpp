#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 21;

int n;
int a[N];
vector<int> g[N];
bool visit[N];
pair<int, int> opt[N];

void mdf(pair<int, int> &a, int x) {
   if (a.first == 0) {
      a.first = x;
   } else if (a.second == 0) {
      a.second = x;
   }
}

pair<int, int> mrg(pair<int, int> a, pair<int, int> b) {
   pair<int, int> ans;
   ans.first = max(a.first, b.first);
   ans.second = max(a.second, b.second);
   if (a.first != ans.first) {
      ans.second = max(ans.second, a.first);
   }
   if (b.first != ans.first) {
      ans.second = max(ans.second, b.first);
   }
   return ans;
}

bool solve(int cur) {
   vector<int> subs;
   for (int i = 0; i < 1 << 21; ++i) {
      opt[i] = {0, 0};
      if ((cur & i) == i) {
         subs.emplace_back(i);
      }
   }
   for (int i = n; i > 0; --i) {
      int ca = a[i] & cur;
      mdf(opt[ca], i);
   }
   for (int i = 0; i < 21; ++i) {
      if (!((cur >> i) & 1)) continue;
      for (int j : subs) {
         if (j & (1 << i)) {
         } else {
            opt[j] = mrg(opt[j], opt[j | (1 << i)]);
         }
      }
   }
   for (int i = 1; i <= n; ++i) {
      int ca = a[i] & cur;
      if (opt[cur ^ ca].second > i) return true;
   }
   return false;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n;
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
   }
   int ans = 0;
   for (int i = 20; i >= 0; --i) {
      if (solve(ans | (1 << i))) {
         ans |= (1 << i);
      }
   }
   cout << ans << "\n";
}