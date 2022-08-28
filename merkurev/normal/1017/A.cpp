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

const int N = 1005;
int a[N];

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

  int n;
  scanf("%d", &n);
  int ans = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      int x;
      scanf("%d", &x);
      a[i] += x;
    }
    if (a[i] > a[0]) ans++;
  }
  printf("%d\n", ans);

  return 0;
}