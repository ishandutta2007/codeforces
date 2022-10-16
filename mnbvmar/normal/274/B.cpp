#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int MaxN = 100005;

LL needMinus[MaxN], needPlus[MaxN];
vector<int> adj[MaxN];
int N;
LL weights[MaxN];
bool visited[MaxN];


void input() {
  cin >> N;
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= N; ++i) {
    cin >> weights[i];
  }
}



void dfs(int v) {
  visited[v] = true;
  needMinus[v] = needPlus[v] = 0;

  for (int s : adj[v]) {
    if (visited[s]) { continue; }
    dfs(s);
    needMinus[v] = max(needMinus[v], needMinus[s]);
    needPlus[v]  = max(needPlus[v],  needPlus[s]);
  }

  LL curChg = needPlus[v] - needMinus[v];
  LL diff   = weights[v] + curChg;

  if (diff > 0) {
    needMinus[v] += diff;
  } else {
    needPlus[v] -= diff;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  input();
  dfs(1);
  cout << needMinus[1] + needPlus[1] << endl;
}