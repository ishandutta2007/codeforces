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

const int N = 200500;
vector<int> cs[2][N];
int pt[N][2];
bool used[2][N];

void dfs(int t, int x) {
  used[t][x] = true;
  for (int i : cs[t][x]) {
    int nt = t ^ 1;
    int nx = pt[i][nt];
    if (!used[nt][nx]) dfs(nt, nx);
  }
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

  int n[2], q;
  scanf("%d%d%d", &n[0], &n[1], &q);
  for (int i = 0; i < q; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    cs[0][x].push_back(i);
    cs[1][y].push_back(i);
    pt[i][0] = x;
    pt[i][1] = y;
  }
  int ans = 0;
  for (int t = 0; t < 2; t++)
    for (int i = 0; i < n[t]; i++)
      if (!used[t][i]) {
        used[t][i] = true;
        dfs(t, i);
        ans++;
      }

  printf("%d\n", ans - 1);

  return 0;
}