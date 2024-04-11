#include <bits/stdc++.h>

using namespace std;

const int N = 300300;

int n;
int val[N];
int64_t mask[N];

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n;
   int64_t start_sum = 0;
   for (int i = 0; i < n; ++i) {
      cin >> val[i] >> mask[i];
      start_sum += val[i];
   }
   if (start_sum < 0) {
      start_sum *= -1;
      for (int i = 0; i < n; ++i) {
         val[i] *= -1;
      }
   }
   int64_t ans = 0;
   for (int b = 0; b < 62; ++b) {
      int64_t cur = (int64_t) 1 << b;
      int64_t sum = 0;
      for (int i = 0; i < n; ++i) {
         if (mask[i] == cur) {
            sum += val[i];
         }
      }
      if (sum > 0) {
         ans |= cur;
         for (int i = 0; i < n; ++i) {
            if (mask[i] & cur) {
               val[i] *= -1;
            }
         }
      }
      for (int i = 0; i < n; ++i) {
         mask[i] &= (~cur);
      }
   }
   cout << ans << '\n';
}