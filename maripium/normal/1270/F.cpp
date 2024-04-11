#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MAXN = 200200;

int N;
int sqUp;
int sqDown;
char S[MAXN];
int pref[MAXN];
int nxt1[MAXN];

int get(int x, int y) {
   assert(x >= 0);
   return (x / y) + 1;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> (S + 1);
   N = strlen(S + 1);
   sqUp = sqrt(N * __lg(N));
   sqDown = (N - 1) / sqUp + 1;
   assert(sqDown * sqUp >= N);
   for (int i = 1; i <= N; ++i) {
      pref[i] = pref[i - 1] + (S[i] == '1');
   }
   nxt1[N + 1] = N + 1;
   for (int i = N; i >= 0; --i) {
      if (S[i] == '1') {
         nxt1[i] = i;
      } else {
         nxt1[i] = nxt1[i + 1];
      }
   }
   ll ans = 0;
   for (int i = 1; i <= N; ++i) {
      int cur = nxt1[i];
      for (int cnt1 = 1; cnt1 <= sqUp; ++cnt1) {
         if (cur == N + 1) {
            break;
         }
         int rm = (i - 1) % cnt1;
         int nxt = nxt1[cur + 1];
         int ncur = max((ll) cur, i - 1 + (ll) cnt1 * (sqDown + 1));
         if (ncur <= nxt - 1) {
            ans += get(nxt - rm - 1, cnt1) - (get(ncur - 1 - rm, cnt1));
         }
         cur = nxt;
      }
   }
   for (int z = 1; z <= sqDown; ++z) {
      vector<ll> vals;
      for (int i = 0; i <= N; ++i) {
         vals.emplace_back(i - (ll) pref[i] * z);
      }
      sort(vals.begin(), vals.end());
      int last = 0;
      for (int i = 0; i <= N; ++i) {
         if (i == 0 || vals[i] != vals[i - 1]) {
            last = i;
         }
         ans += i - last;
      }
   }
   cout << ans << "\n";
   return 0;
}