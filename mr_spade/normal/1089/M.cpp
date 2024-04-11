#include <bits/stdc++.h>
using namespace std;

const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

const int N = 200;

int dfn[N], low[N], in[N], st[N], top, tim, n, tot, bel[N], mp[N][N][N], id[N];
vector<int> have[N], g[N], G[N];

void Tarjan(int x) {
  dfn[x] = low[x] = ++tim;
  in[x] = 1;
  st[++top] = x;
  for(int v : g[x]) {
    if(!dfn[v]) {
      Tarjan(v);
      low[x] = min(low[x], low[v]);
    } else if(in[v]) {
      low[x] = min(low[x], dfn[v]);
    }
  }
  if(low[x] == dfn[x]) {
    ++tot;
    //cerr << x << " " << top << endl;
    while(1) {
      have[tot].push_back(st[top]);
      in[st[top]] = 0;
      bel[st[top]] = tot;
      if(st[top--] == x) {
	break;
      }
    }
    //cerr << top << endl;
  }
}

int main(void) {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      int x;
      scanf("%d", &x);
      if(x) {
	g[i].push_back(j);
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    if(dfn[i]) {
      continue;
    }
    Tarjan(i);
  }
  //cerr << tot << endl;
  //return 0;
  memset(in, 0, sizeof in);
  for(int i = 1; i <= n; i++) {
    for(int j : g[i]) {
      if(bel[i] == bel[j]) {
	continue;
      }
      G[bel[i]].push_back(bel[j]);
      in[bel[j]]++;
    }
  }
  
  queue<int> q;
  for(int i = 1; i <= tot; i++) {
    if(!in[i]) {
      q.push(i);
    }
  }
  
  vector<int> T;

  const int R = 100;
  
  while(!q.empty()) {
    int x = q.front(); q.pop();
    T.push_back(x);
    for(int v : G[x]) {
      if(!--in[v]) {
	q.push(v);
      }
    }
  }

  for(int i = 0; i < T.size(); i++) {
    id[T[i]] = i;
  }

  int x = 1, y = 1;
  for(int h = 0; h < tot; h++) {
    int u = T[h];
    for(int i = 0; i < R; i++) {
      for(int j = 0; j < R; j++) {
	mp[h << 1 | 1][i][j] = -1;
      }
    }
    for(int i = 0; i < have[u].size(); i++) {
      mp[h << 1][R - 1][i] = have[u][i];
    }
  }
  for(int h = 0; h < tot; h++) {
    int u = T[h];
    for(int v : G[u]) {
      //cerr << u << " " << v << " :: " << h << " " << id[v] << endl;
      for(int i = h; i < id[v]; i++) {
	
	mp[i << 1 | 1][x][y] = 0;
	if(i != h) {
	  for(int j = 0; j < 8; j++) {
	    int nx = x + dx[j], ny = y + dy[j];
	    mp[i << 1][nx][ny] = -1;
	  }
	}
      }
      x += 3;
      if(x >= R) {
	x = 1, y += 3;
      }
    }
  }
  //return 0;
  printf("%d %d %d\n", R, R, tot * 2);
  for(int h = 0; h < tot * 2; h++, puts("")) {
    for(int i = 0; i < R; i++, puts("")) {
      for(int j = 0; j < R; j++) {
	int x = mp[h][i][j];
	if(x < 1) {
	  putchar(x ? '#' : '.');
	} else {
	  putchar(x + '0');
	}
      }
    }
  }
  return 0;
}