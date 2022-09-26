#include <bits/stdc++.h>

using namespace std;

const int N = 200200;
const int MAGIC = 450;

int n, m, q;
int x[N], y[N], a[N], pr[N];
int cnt[MAGIC][1 << 14];
int lz[MAGIC];
int cntz;
int pos[N], last[N];

void upd(int p,int val) {
   int l = pos[p], r = last[p % m];
   int lb = l / MAGIC, rb = r / MAGIC;
   cntz -= (pr[r] == lz[rb]);
   if (lb == rb) {
      for (int i = l; i <= r; ++i) {
         --cnt[lb][pr[i]];
         pr[i] ^= val;
         ++cnt[lb][pr[i]];
      }
   } else {
      for (int i = l; i < (lb + 1) * MAGIC; ++i) {
         --cnt[lb][pr[i]];
         pr[i] ^= val;
         ++cnt[lb][pr[i]];
      }
      for (int i = lb + 1; i < rb; ++i) lz[i] ^= val;
      for (int i = rb * MAGIC; i <= r; ++i) {
         --cnt[rb][pr[i]];
         pr[i] ^= val;
         ++cnt[rb][pr[i]];
      }
   }
   cntz += (pr[r] == lz[rb]);
}

void answer() {
   if (cntz == m) {
      int ans = 0;
      for (int i = 0; i < MAGIC; ++i) {
         ans += cnt[i][lz[i]];
      }
      printf("%d\n", n + 1 - ans);
   } else puts("-1");
}

int main() {
   scanf("%d %d %d", &n, &m, &q);
   for (int i = 0; i < n; ++i) scanf("%d", x + i);
   for (int i = 0; i < n; ++i) scanf("%d", y + i);
   for (int i = 0; i < n; ++i) a[i] = x[i] ^ y[i];
   for (int i = n; i > 0; --i) a[i] ^= a[i - 1];
   int sz = 0;
   for (int i = 0; i < m; ++i) {
      for (int j = i; j <= n; j += m) {
         pr[sz] = a[j];
         if (j != i) pr[sz] ^= pr[sz - 1];
         ++sz;
         pos[j] = sz - 1;
      }
      cntz += pr[sz - 1] == 0;
      last[i] = sz - 1;
   }
   for (int i = 0; i <= n; ++i) cnt[i / MAGIC][pr[i]]++;
   answer();
   while (q--) {
      char t; int p, v;
      scanf(" %c %d %d", &t, &p, &v); --p;
      int val;
      if (t == 'a') {
         val = x[p] ^ v;
         x[p] = v;
      } else {
         val = y[p] ^ v;
         y[p] = v;
      }
      upd(p, val);
      upd(p + 1, val);
      answer();
   }
}