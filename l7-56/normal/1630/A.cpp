#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k,to[100010];
void work() {
  scanf("%d%d", &n, &k);
  if (n == 4 && k == 3) return printf("-1\n"), void();
  #define opp(x) ((x) ^ (n - 1))
  if (k < n - 1) {
    printf("%d %d\n", n - 1, k);
    if (k) printf("%d %d\n", 0, opp(k));
    for (int i = 1; i < n / 2; ++i)
      if (i != k && i != opp(k)) printf("%d %d\n", i, opp(i));
  }
  else {
    for (int i = 1; (n >> i) > 1; ++i)
      to[(1 << (i + 1)) - 2] = opp((1 << i) - 2),
      to[opp((1 << i) - 2)] = (1 << (i + 1)) - 2;
    to[1] = 3, to[3] = 1, to[opp(3)] = 0, to[0] = opp(3);
    for (int i = 0; i < n / 2; ++i)
      if (to[i] == -1) printf("%d %d\n", i, opp(i));
    for (int i = 0; i < n; ++i)
      if (to[i] != -1) printf("%d %d\n", i, to[i]), to[to[i]] = -1, to[i] = -1;
  }
}

// int vis[100010],to[100010];
// bool dfs(int nw, int sum) {
//   if (sum > k) return 0;
//   if (nw == n && sum == k) return 1;
//   if (vis[nw]) return dfs(nw +1, sum);
//   for (int i = nw + 1; i < n; ++i) {
//     if (vis[i]) continue;
//     vis[nw] = vis[i] = 1; to[nw] = i;
//     if (dfs(nw + 1, sum + (nw & i))) return 1;
//     vis[nw] = vis[i] = to[nw] = 0;
//   }
//   return 0;
// }
//
// void work2() {
//   scanf("%d%d", &n, &k);
//   if (!dfs(0, 0)) return printf("-1\n"), void();
//   for (int i = 0; i < n; ++i) {
//     if (to[i]) printf("%d %d\n", i, to[i]), to[i] = 0;
//     vis[i] = 0;
//   }
// }

int main() {
  memset(to, -1, sizeof to);
  int t;
  scanf("%d", &t);
  while (t--) work();
  return 0;
}