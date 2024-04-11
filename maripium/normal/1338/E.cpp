#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAXN = 8000;

int N;
bool adj[MAXN][MAXN];
bool can[MAXN][MAXN];
int deg[MAXN];
bool flag[MAXN];
char str[MAXN];
int go[MAXN];

int main() {
   scanf("%d", &N);
   for (int i = 0; i < N; ++i) {
      scanf("%s", str);
      int sz = 0;
      for (int j = 0; j < (N / 4); ++j) {
         int mask = isdigit(str[j]) ? str[j] - '0' : 10 + str[j] - 'A';
         for (int z = 3; z >= 0; --z) {
            adj[i][sz++] = (mask >> z) & 1;
         }
      }
      for (int j = 0; j < N; ++j) deg[i] += adj[i][j];
   }
   int numPairs = N * (N - 1) / 2;
   ll ans = ll(N) * (N - 1) / 2;
   {
      int cur = 0;
      while (cur < N) {
         bool found = false;
         for (int i = 0; i < N; ++i) if (deg[i] == N - cur - 1) {
            found = true;
            break;
         }
         if (found) cur++;
         else break;
      }
      int cantPairs = cur * (cur - 1) / 2 + cur * (N - cur);
      ans += ll(614) * N * cantPairs;
      numPairs -= cantPairs;
   }
   vector<int> verts[2];
   auto add = [&](vector<int> &verts, int v) {
      int ptr = 0;
      while (ptr < verts.size() && adj[verts[ptr]][v]) ptr++;
      if (ptr == int(verts.size()) || adj[v][verts.back()]) {
         verts.insert(verts.begin() + ptr, v);
         return true;
      } else {
         return false;
      }
   };
   for (int i = 0; i < N; ++i) {
      if (!add(verts[0], i)) {
         assert(add(verts[1], i));
      }
   }
   for (int z = 0; z < 2; ++z) {
      fill(flag, flag + N, false);
      for (int i = int(verts[z].size()) - 1; i >= 0; --i) {
         for (int v : verts[z ^ 1]) flag[v] |= adj[verts[z][i]][v], can[verts[z][i]][v] |= flag[v];
      }
   }
   for (int z = 0; z < 2; ++z) {
      fill(flag, flag + N, false);
      for (int i = 0; i < int(verts[z].size()); ++i) {
         for (int v : verts[z ^ 1]) flag[v] |= adj[v][verts[z][i]],  can[v][verts[z][i]] |= flag[v];
      }
   }
   fill(go, go + N, N);
   for (int v = 0; v < N; ++v) {
      int z = 0;
      for (int u : verts[0]) z |= (v == u);
      int ptr = int(verts[z].size());
      while (ptr > 0 && adj[verts[z][ptr - 1]][v]) ptr--;
      for (int i = 0; i < ptr; ++i) {
         if (adj[v][verts[z][i]]) go[verts[z][i]] = min(go[verts[z][i]], ptr);
      }
   }
   for (int z = 0; z < 2; ++z) {
      for (int v : verts[z]) {
         for (int i = go[v]; i < int(verts[z].size()); ++i) {
            can[verts[z][i]][v] = true;
         }
      }
   }
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
         if (i != j && can[i][j] && adj[j][i]) {
            ans += 2;
            numPairs--;
         }
      }
   }
   ans += numPairs * 3;
   cout << ans << "\n";
   return 0;
}