#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

typedef long long int int64;

int main() {
#ifdef LOCAL
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

  int n;
  scanf("%d", &n);
  int x = 1;
  while (x * x < n) x++;

  int cur = x;
  int mt = 0;
  for (int i = 0; i < n; i++) {
    printf("%d ", cur);
    cur--;

    if (cur == mt) {
      mt = cur + x;
      cur += 2 * x;
      cur = min(cur, n);
    }
  }
  printf("\n");

  return 0;
}