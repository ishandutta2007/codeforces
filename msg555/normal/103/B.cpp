#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

bool vis[100];
int deg[100];
vector<int> G[100];

int count(int x) {
  if(vis[x]) return 0;
  vis[x] = true;
  int ret = 1;
  for(int i = 0; i < G[x].size(); i++) {
    ret += count(G[x][i]);
  }
  return ret;
}

int main() {
  int N, M;
  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  memset(vis, 0, sizeof(vis));
  if(N != M || N != count(0)) {
    cout << "NO" << endl;
    return 0;
  }

  queue<int> q;
  memset(vis, 0, sizeof(vis));
  for(int i = 0; i < N; i++) {
    deg[i] = G[i].size();
    if(deg[i] == 1) {
      vis[i] = true;
      q.push(i);
    }
  }
  int count = N;
  while(!q.empty()) {
    count--;
    int v = q.front(); q.pop();
    for(int i = 0; i < G[v].size(); i++) {
      if(--deg[G[v][i]] == 1) {
        vis[G[v][i]] = true;
        q.push(G[v][i]);
      }
    }
  }
  if(count >= 3) {
    cout << "FHTAGN!" << endl;
  } else {
    cout << "NO" << endl;
  }
}