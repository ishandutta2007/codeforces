#include <bits/stdc++.h>

using namespace std;

const int maxn = 200100;

int n;
int a[maxn];

int main() {
  int t; scanf("%d", &t);
  for (int ii = 0; ii < t; ii++) {
    scanf("%d", &n);
    int good = -1;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      if (i && abs(a[i]-a[i-1]) > 1)
        good = i+1;
    }

    if (good == -1) printf("NO\n");
    else printf("YES\n%d %d\n", good-1, good);
  }
}