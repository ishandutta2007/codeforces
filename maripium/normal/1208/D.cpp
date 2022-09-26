#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 1 << 18;

ll ft[N];

void add(int p, int v) {
   for (; p < N; p += p & -p) {
      ft[p] += v;
   }
}

int find(ll sum) {
   int cpos = 0;
   ll csum = 0;
   for (int i = 17; i >= 0; --i) {
      if (csum + ft[cpos | (1 << i)] <= sum) {
         cpos |= (1 << i);
         csum += ft[cpos];
      }
   }
   return cpos + 1;
}

ll a[N];
int p[N];

int main() {
   ios_base::sync_with_stdio(false);
   int n;
   cin >> n;
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      add(i, i);
   }
   for (int i = n; i > 0; --i) {
      p[i] = find(a[i]);
      add(p[i], -p[i]);
   }
   for (int i = 1; i <= n; ++i) {
      cout << p[i] << " ";
   }
}