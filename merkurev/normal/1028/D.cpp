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

const int MOD = (int)1e9 + 7;
void x2(int& a) {
  a += a;
  if (a >= MOD) a -= MOD;
}
int mul(int a, int b) { return (a * 1LL * b) % MOD; }

set<int> book;

pair<int, int> getBound(int x) {
  auto it = book.lower_bound(x);
  int r = *it;
  it--;
  int l = *it;
  return make_pair(l, r);
}

char str[15];

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

  book.insert(-MOD);
  book.insert(MOD);

  int n;
  scanf("%d", &n);
  pair<int, int> bound = getBound(0);
  int ans = 1;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%s%d", str, &x);
    if (string(str) == "ADD") {
      book.insert(x);
      if (bound.first < x && x < bound.second) cnt++;
    } else {
      cnt = 0;
      if (x < bound.first || x > bound.second) {
        printf("0\n");
        return 0;
      }
      if (x > bound.first && x < bound.second) {
        x2(ans);
      }
      book.erase(x);
      bound = getBound(x);
    }
  }
  ans = mul(ans, cnt + 1);
  printf("%d\n", ans);
  return 0;
}