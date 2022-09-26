#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 18;

int n, x;
bool visit[N];
int a[N];

int main() {
   scanf("%d %d", &n, &x);
   int sz = 0;
   a[++sz] = 0;
   visit[0] = true;
   for (int i = 1; i < 1 << n; ++i) {
      if (visit[i ^ x]) continue;
      a[++sz] = i;
      visit[i] = true;
   }
   printf("%d\n", sz - 1);
   for (int i = 1; i < sz; ++i) {
      printf("%d ", a[i] ^ a[i + 1]);
   }
}