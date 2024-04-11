#include<bits/stdc++.h>
#define lo p * 2
#define ro p * 2 + 1
#define sit set<int>::iterator
using namespace std;
const int N = 2e5 + 10;
int n;
int pos[N], op[N], ans[N];
set<int> k;
vector<int> q;
int mx[N << 2];
void inse(int p, int l, int r, int x, int v)
{
  if(l == r) return mx[p] = max(mx[p], v), void();
  int mid = (l + r) / 2;
  if(x <= mid) inse(lo, l, mid, x, v);
  else inse(ro, mid + 1, r, x, v);
  mx[p] = max(mx[lo], mx[ro]);
  return;
}

int query(int p, int l, int r, int L, int R)
{
  if(L <= l && r <= R) return mx[p];
  int mid = (l + r) / 2;
  int res = 0;
  if(L <= mid) res = max(res, query(lo, l, mid, L, R));
  if(R > mid) res = max(res, query(ro, mid + 1, r, L, R));
  return res;
}
int main()
{
  scanf("%d", &n);
  int now = 0, flag = 0;
  char opt[10];
  for(int i = 1; i <= n * 2; i++)
  {
    scanf("%s", opt);
    if(opt[0] == '+') now++, op[i] = 1;
    else now--, op[i] = -1, scanf("%d", &pos[i]), q.push_back(i);
    if(now < 0) flag = 1;
  }
  if(flag) return printf("NO\n"), 0;
  for(int i = 1; i <= n * 2; i++) if(op[i] == 1) k.insert(i);
  for(int i = 0; i < n; i++)
  {
    int pre = query(1, 1, n, pos[q[i]], n);
    sit it = k.lower_bound(pre + 1);
    if(it == k.end() || (*it) > q[i]) return printf("NO\n"), 0;
    ans[*it] = pos[q[i]];
    k.erase(it);
    inse(1, 1, n, pos[q[i]], q[i]);
  }
  printf("YES\n");
  for(int i = 1; i <= 2 * n; i++) if(op[i] == 1) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}