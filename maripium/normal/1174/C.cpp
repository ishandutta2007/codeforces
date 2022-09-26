#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

int a[N];

int main() {
   int n;
   scanf("%d", &n);
   int cur = 0;
   for (int i = 2; i <= n; ++i) if (!a[i]) {
      ++cur;
      for (int j = i; j <= n; j += i) a[j] = cur;
   }
   for (int i = 2; i <= n; ++i) {
      printf("%d ", a[i]);
   }
}