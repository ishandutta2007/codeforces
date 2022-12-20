#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;
int n,nxt[maxn],lst[maxn],a[maxn];
int cnt[maxn], res;
void del(int c) { if (--cnt[c] == 0) res = min(res, c); }

int nc[maxn];
void work() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), cnt[a[i]]++;
  res = 0;
  while (cnt[res]) ++res;
  int l = 1;
  vector <int> ans;
  while (l <= n) {
    ans.push_back(res);
    int tmp = 0, nl = l;
    do {
      nc[a[nl++]]++;
      while (nc[tmp]) ++tmp;
    } while (tmp < res);
    while (l < nl) nc[a[l]]--, del(a[l]), ++l;
  }
  printf("%d\n", (int) ans.size());
  for (int x : ans) printf("%d ", x);
  printf("\n");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) work();
  return 0;
}