#include <bits/stdc++.h>

using namespace std;

int arr[2010], n;
char ret[2010];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", arr + i);

  int idx = 0;
  int clet = 0;
  while (idx < n) {
    int block = -1;
    for (int i = n; i >= 1; i--) {
      if (arr[i] > 0) {
        block = i;
        break;
      }
    }
    for (int i = block; i >= 1; i--) {
      arr[i] -= (block - i + 1);
    }

    while(block-->0) {
      ret[idx++] = (char)(clet+'a');
    }
    clet = (clet + 1) % 26;
  }
  ret[n] = '\0';

  printf("%s\n", ret);
}