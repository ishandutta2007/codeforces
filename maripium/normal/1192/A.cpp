#include <bits/stdc++.h>

using namespace std;

const int N = 150150;
const int M = 9 * N;
const int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int n, m;
pair<int, int> a[N];
pair<int, int> ps[M];
int id[N], revId[M];
int p[M];
bool visit[N];
int g[M][8];
bool goOut[M], inQ[N];
priority_queue<int> q;

int getp(int v) {
   if (p[v] != v) {
      p[v] = getp(p[v]);
   }
   return p[v];
}

void mrg(int v, int u) {
   v = getp(v);
   u = getp(u);
   p[v] = u;
}

void dfs(int v) {
   if (revId[v] == -1) return;
   if (visit[revId[v]]) return;
   visit[revId[v]] = true;
   for (int u : g[v]) {
      dfs(u);
   }
}

void dfsGo(int v) {
   if (v == -1) return;
   if (goOut[v]) return;
   goOut[v] = true;
   if (revId[v] != -1) {
      if (!inQ[revId[v]]) {
         inQ[revId[v]] = true;
         q.push(revId[v]);
      }
      return;
   }
   for (int d = 1; d < 8; d += 2){
      dfsGo(g[v][d]);
   }
}

bool isImp(int v) {
   v = id[v];
   int deg = 0;
   for (int d = 0; d < 8; ++d) {
      deg += (revId[g[v][d]] != -1);
   }
   for (int x = 1; x < 8; x += 2) {
      for (int y = x + 2; y < 8; y += 2) {
         if (getp(g[v][x]) != getp(g[v][y])) continue;
         int mdeg = 0;
         for (int z = x + 1; z < y; ++z) {
            mdeg += (revId[g[v][z]] != -1);
         }
         if (0 < mdeg && mdeg < deg) {
            return true;
         }
      }
   }
   return false;
}

int main() {
   ios_base::sync_with_stdio(false);
   int t;
   cin >> n >> t;
   for (int i = 0; i < n; ++i) {
      cin >> a[i].first >> a[i].second;
      ps[m++] = a[i];
      for (int d = 0; d < 8; ++d) {
         ps[m++] = {a[i].first + dx[d], a[i].second + dy[d]};
      }
   }
   sort(ps, ps + m);
   m = unique(ps, ps + m) - ps;
   fill(revId, revId + m, -1);
   for (int i = 0; i < n; ++i) {
      id[i] = lower_bound(ps, ps + m, a[i]) - ps;
      revId[id[i]] = i;
   }
   for (int i = 0; i < m; ++i) {
      for (int d = 0; d < 8; ++d) {
         pair<int, int> np = {ps[i].first + dx[d], ps[i].second + dy[d]};
         int j = lower_bound(ps, ps + m, np) - ps;
         if (j < m && ps[j] == np) {
            g[i][d] = j;
         } else {
            g[i][d] = -1;
         }
      }
   }
   dfs(id[0]);
   for (int i = 0; i < n; ++i) {
      if (!visit[i]) {
         cout << "NO\n";
         return 0;
      }
   }
   iota(p, p + m, 0);
   for (int i = 0; i < m; ++i) if (revId[i] == -1) {
      for (int d = 1; d < 8; d += 2) {
         int j = g[i][d];
         if (j == -1) continue;
         if (revId[j] == -1) {
            mrg(i, j);
         }
      }
   }
   dfsGo(0);
   deque<int> ans;
   while (!q.empty()) {
      int v = q.top();
      q.pop();
      inQ[v] = false;
      if (isImp(v)) continue;
      ans.push_front(v);
      v = id[v];
      revId[v] = -1;
      for (int d = 1; d < 8; d += 2) {
         int u = g[v][d];
         if (revId[u] == -1) {
            mrg(v, u);
         }
      }
      goOut[v] = false;
      dfsGo(v);
      for (int u : g[v]) {
         if (revId[u] != -1 && goOut[u] && !inQ[revId[u]]) {
            inQ[revId[u]] = true;
            q.push(revId[u]);
         }
      }
   }
   cout << "YES\n";
   for (int v : ans) {
      cout << v + 1 << "\n";
   }
}