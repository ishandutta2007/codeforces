#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N, Q; cin >> N >> Q;
   vector<int64_t> A(1 << N);
   for (int i = 0; i < (1 << N); ++i) cin >> A[i];
   vector<vector<int64_t>> bucket(N+1);
   for (int z = N; z >= 0; --z) bucket[z].resize(1 << z);
   int flip = 0;
   for (int i = 0; i < (1 << N); ++i) {
      int ci = i;
      for (int z = N; z >= 0; --z) {
         bucket[z][ci] += A[i];
         ci >>= 1;
      }
   }
   while (Q--) {
      int op; cin >> op;
      if (op == 1) {
         int x; int64_t k; cin >> x >> k;
         x = (x-1) ^ flip;
         int cx = x;
         for (int z = N; z >= 0; --z) {
            bucket[z][cx] += k - A[x];
            cx >>= 1;
         }
         A[x] = k;
      } else if (op == 2) {
         int x; cin >> x;
         flip ^= ((1 << x) - 1);
      } else if (op == 3) {
         int x; cin >> x;
         flip ^= (1 << x);
      } else {
         int l, r; cin >> l >> r;
         --l, --r;
         int64_t ans = 0;
         int cl = l, cr = r;
         int cflip = flip;
         for (int z = N; z >= 0; --z) {
            if (cl > cr) break;
            if (cl & 1) {
               ans += bucket[z][cl ^ cflip];
               cl++;
            }
            if (!(cr&1)) {
               ans += bucket[z][cr ^ cflip];
               cr--;
            }
            cl >>= 1;
            cr >>= 1;
            cflip >>= 1;
         }
         cout << ans << '\n';
      }
   }
}