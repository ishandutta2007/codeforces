#include<bits/stdc++.h>
#define i64 long long
using namespace std;
const int N = 5e3 + 10;
const int M = 5e4 + 10;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
struct edge
{
  int to, nxt;
  i64 co, flo;
}e[M << 1];
int head[N], tot = 1;
i64 cans = 0, flow = 0;
int vis[N], idt;
i64 dep[N];
int cnt[26], b[N], m[N][26], ed[N], val[N];
void addedge(int u, int v, int w, int c) {
  e[++tot] = edge{v, head[u], c, w};
  return head[u] = tot, void();
}
void fadd(int u, int v, int w, int c) {
   addedge(u, v, w, c);
   addedge(v, u, 0, -c);
   return;
}
int spfa(int s, int t, int n) {
  for(int i = 1; i <= n; i++) dep[i] = inf, vis[i] = 0;
  deque<int> q;
  q.push_back(t);
  dep[t] = 0;
  vis[t] = 1;
  while(!q.empty()) {
    int u = q.front();
    q.pop_front();
    vis[u] = 0;
    for(int i = head[u]; i; i = e[i].nxt) {
      int v = e[i].to;
      int w = e[i].co;
      if(e[i ^ 1].flo && dep[v] > dep[u] - w) {
        dep[v] = dep[u] - w;
        if(!vis[v]) {
          vis[v] = 1;
          if(!q.empty() && dep[v] <= dep[q.front()]) q.push_front(v);
          else q.push_back(v);
        }
      }
    }
  }
  return dep[s] < inf;
}
i64 dfs(int u, int t, i64 in) {
  vis[u] = 1;
  if(u == t || !in) return in;
  i64 f = 0, flow = 0;
  for(int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    i64 w = e[i].co;
    i64 fl = e[i].flo;
    if(fl && dep[u] - w == dep[v] && !vis[v] && (f = dfs(v, t, min(in, fl)) > 0)) {
      flow += f, e[i].flo -= f, e[i ^ 1].flo += f, in -= f, cans += f * w;
      if(!in) break;
    }
  }
  return flow;
}
void zkwmfmc(int s, int t, int n) {
  cans = 0;
  flow = 0;
  while(spfa(s, t, n)) {
  	
    vis[t] = 1;
    while(vis[t]) {
      for(int i = 1; i <= n; i++) vis[i] = 0;
      flow += dfs(s, t, inf);
    }
  }
  return;
}
char w[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, s = ++idt, t = ++idt;
  cin >> n;
  cin >> (w + 1);
  for(int i = 1; i <= n; i++) cnt[w[i] - 'a']++;
  int sum = 0;
  for(int i = 1; i <= n; i++) cin >> val[i], sum += val[i];
  for(int i = 0; i < 26; i++) b[i] = ++idt, fadd(s, b[i], cnt[i], 0);
  n /= 2;
  for(int i = 1; i <= n; i++) {
	int l = w[i] - 'a', r = w[2 * n + 1 - i] - 'a';
	ed[i] = ++idt;
	fadd(ed[i], t, 2, 0);
  	for(int j = 0; j < 26; j++) {
  	  m[i][j] = ++idt;
  	  fadd(b[j], m[i][j], 1, 0);
  	  if(j == l || j == r) continue;
  	  fadd(m[i][j], ed[i], 1, 0);
	}
	int L = val[i], R = val[2 * n + 1 - i];
	if(l == r) {
		fadd(m[i][l], ed[i], 1, - max(L, R));
	} else {
		fadd(m[i][l], ed[i], 1, - L);
		fadd(m[i][r], ed[i], 1, - R);
	}
  }
  zkwmfmc(s, t, idt);
  cout << - cans << endl;
  return 0;
}