#include <bits/stdc++.h>

using namespace std;

const int N = 200200;

int n, q;
int a[N];
int last[N];
int suf[N];

int main() {
   ios_base::sync_with_stdio(false);
   int n;
   cin >> n;
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
   }
   cin >> q;
   for (int i = 1; i <= q; ++i) {
      int op;
      cin >> op;
      if (op == 1) {
         int p, x;
         cin >> p >> x;
         last[p] = i;
         a[p] = x;
      } else {
         int x;
         cin >> x;
         suf[i] = x;
      }
   }
   for (int i = q; i > 0; --i) {
      suf[i] = max(suf[i], suf[i + 1]);
   }
   for (int i = 1; i <= n; ++i) {
      cout << max(a[i], suf[last[i] + 1]) << " ";
   }
}