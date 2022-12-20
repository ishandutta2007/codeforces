#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
bool f2[30][30],f3[30][30][30];
char s[maxn][4];
int n;

void work() {
  scanf("%d", &n);
  for (int c1 = 0; c1 < 26; ++c1)
    for (int c2 = 0; c2 < 26; ++c2)
      for (int c3 = 0; c3 < 26; ++c3)
        f2[c1][c2] = f3[c1][c2][c3] = 0;
  bool flag = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s[i] + 1);
    int len = strlen(s[i] + 1);
    if (len == 1) flag = 1;
    else if (len == 2) {
      int x = s[i][1] - 'a', y = s[i][2] - 'a';
      if (x == y || f2[y][x]) flag = 1;
      for (int c = 0; c < 26; ++c)
        if (f3[y][x][c]) flag = 1;
      f2[x][y] = 1;
    }
    else {
      int x = s[i][1] - 'a', y = s[i][2] - 'a', z = s[i][3] - 'a';
      if (x == z || f3[z][y][x]) flag = 1;
      if (f2[z][y]) flag = 1;
      f3[x][y][z] = 1;
    }
  }
  printf(flag ? "YES\n" : "NO\n");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) work();
  return 0;
}