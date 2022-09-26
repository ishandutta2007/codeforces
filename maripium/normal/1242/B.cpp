#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

int N, M;
int ncomp;
set<int> adj[MAXN];
set<int> waiting;

void Dfs(int v) {
   if (waiting.count(v)) {
      waiting.erase(v);
   }
   vector<int> nxts;
   for (int u : waiting) {
      if (adj[v].count(u)) {
         continue;
      }
      nxts.emplace_back(u);
   }
   for (int u : nxts) {
      waiting.erase(u);
   }
   for (int u : nxts) {
      Dfs(u);
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> N >> M;
   for (int i = 1; i <= N; ++i) {
      waiting.emplace(i);
   }
   for (int i = 1; i <= M; ++i) {
      int v, u;
      cin >> v >> u;
      adj[v].emplace(u);
      adj[u].emplace(v);
   }

   while (waiting.size()) {
      ++ncomp;
      Dfs(*waiting.begin());
   }

   cout << ncomp - 1 << "\n";
}