#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int N = 300300;

int n;
int a[N];
int cur;
int cnt[N];
int nodes = 1;
map<int, int> nxt[N];

int main() {
   ios_base::sync_with_stdio(false);
   int tt;
   cin >> tt;
   while (tt--) {
      cin >> n;
      ll ans = 0;
      cnt[cur]++;
      for (int i = 0; i < n; ++i) {
         cin >> a[i];
         if (!nxt[cur].count(a[i])) {
            nxt[cur][a[i]] = nodes;
            nxt[nodes++][a[i]] = cur;
         }
         cur = nxt[cur][a[i]];
         ans += cnt[cur]++;
      }
      for (int i = 0; i < nodes; ++i) {
         cnt[i] = 0;
         nxt[i].clear();
      }
      cur = 0;
      nodes = 1;
      cout << ans << "\n";
   }
}