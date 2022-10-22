#include<bits/stdc++.h>
#define par pair<int, int>
#define mp make_pair
#define x first
#define y second
using namespace std;
const int N = 3.5e4 + 10, K = 55, inf = 0x3f3f3f3f;
int n, k, cnt = 0;
int dp[N], nxt[N], a[N];
int vis[N];

void ins(int x) {
  if(!vis[a[x]]) cnt++;
  vis[a[x]]++;
}

void del(int x) {
  vis[a[x]]--;
  if(!vis[a[x]]) cnt--;
}

void Solve(int l, int r, int al, int ar) {
  if(l > r) return;
  int mid = (l + r) / 2;
  for(int i = r; i > mid; i--) del(i);
  par be = mp(-inf, 0);
  for(int i = al; i <= min(mid - 1, ar); i++) {
    del(i);
    par v = mp(cnt + dp[i], i);
    if(v.x >= be.x) be = v;
  }
  for(int i = al; i <= min(mid - 1, ar); i++) ins(i);
  for(int i = r; i > mid; i--) ins(i);
  int pos = be.y;
  nxt[mid] = be.x;
  for(int i = r; i >= mid; i--) del(i);
  Solve(l, mid - 1, al, pos);
  for(int i = r; i >= mid; i--) ins(i);
  for(int i = al; i < pos; i++) del(i);
  Solve(mid + 1, r, pos, ar);
  for(int i = al; i < pos; i++) ins(i);
  return;
}

int main() {
  scanf("%d%d", &n, &k);
  for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for(int i = 1; i <= n; i++) ins(i);
  ins(0);
  for(int i = 1; i <= k; i++) {
    Solve(0, n, 0, n);
    for(int j = 0; j <= n; j++) dp[j] = max(nxt[j], dp[j]);
  }
  printf("%d\n", dp[n]);
	return 0;
}