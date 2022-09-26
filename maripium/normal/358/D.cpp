#include <bits/stdc++.h>
using namespace std;

int n;
int a[3005], b[3005], c[3005], f[3005][2];

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n;
   for (int i = 0; i < n; ++i) cin >> a[i];
   for (int i = 0; i < n; ++i) cin >> b[i];
   for (int i = 0; i < n; ++i) cin >> c[i];
   f[0][0] = a[0];
   f[0][1] = b[0];
   for (int i = 1; i < n; ++i) {
      f[i][0] = max(f[i - 1][0] + b[i], f[i - 1][1] + a[i]);
      f[i][1] = max(f[i - 1][0] + c[i], f[i - 1][1] + b[i]);
   }
   cout << f[n - 1][0] << '\n';
}