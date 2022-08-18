#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
const int MAXN = 100003;
int n, Max, col[MAXN], cnt[MAXN];
int size[MAXN], son[MAXN], big[MAXN];
long long ans[MAXN], v[MAXN];
long long Sum;
vector<int> G[MAXN];
void dfs1(int cur, int fa) {
  size[cur] = 1;
  son[cur] = 0;
  for(int i = 0; i < G[cur].size(); i++) {
    int nx = G[cur][i];
    if(nx != fa) {
      dfs1(nx, cur);
      size[cur] += size[nx];
      if(size[nx] > size[son[cur]]) {
        son[cur] = nx;
      }
    }
  }
}
void dfs2(int cur, int fa, int val) {
  int & times = cnt[col[cur]];
  v[times] -= col[cur];
  times += val;
  v[times] += col[cur];
  if(times > Max) Max = times;
  while(!v[Max]) Max--;
  Sum = v[Max];
  for(int i = 0; i < G[cur].size(); i++) {
    int nx = G[cur][i];
    if(nx != fa && !big[nx]) {
      dfs2(nx, cur, val);
    }
  }
}
void dfs3(int cur, int fa, bool keep) {
  for(int i = 0; i < G[cur].size(); i++) {
    int nx = G[cur][i];
    if(nx != fa && nx != son[cur]) {
      dfs3(nx, cur, 0);
    }
  }
  if(son[cur]) { 
    dfs3(son[cur], cur, 1);
    big[son[cur]] = 1;
  }
  dfs2(cur, fa, 1);
  ans[cur] = Sum;
  big[son[cur]] = 0;
  if(!keep) dfs2(cur, fa, -1);
}
int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &col[i]);
  }
  for(int i = 1; i < n; i++) {
    int x, y; scanf("%d %d", &x, &y);
    G[x].push_back(y);
    G[y].push_back(x);
  }
  dfs1(1, 0);
  dfs3(1, 0, 1);
  for(int i = 1; i <= n; i++) {
    printf("%lld%c", ans[i], i == n ? '\n' : ' ');
  }
  return 0;
}