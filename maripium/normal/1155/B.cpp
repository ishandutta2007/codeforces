#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

char s[N];

int main() {
  int n;
  scanf("%d %s", &n, s + 1);
  int num = (n - 11) / 2;
  int cnt = 0;
  for (int i = 1; i <= num + num + 1; ++i) {
    cnt += s[i] == '8';
  }
  puts(cnt >= num + 1 ? "YES" : "NO");
}