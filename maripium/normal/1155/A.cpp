#include <bits/stdc++.h>

using namespace std;

char s[300005];

int main() {
  int n;
  scanf("%d %s", &n, s + 1);
  int id = 1;
  for (int i = 2; i <= n; ++i) {
    if (s[i] < s[id]) {
      puts("YES");
      printf("%d %d\n", id, i);
      return 0;
    } else {
      id = i;
    }
  }
  puts("NO");
}