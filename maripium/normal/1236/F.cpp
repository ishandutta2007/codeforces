/*
1 0
*/
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAXN = 500500;
const int MOD = 1000000007;

void add(int &x, int y) {
   x += y;
   if (x >= MOD) {
      x -= MOD;
   }
}

void sub(int &x, int y) {
   x -= y;
   if (x < 0) {
      x += MOD;
   }
}

int mul(int x, int y) {
   return (ll) x * y % MOD;
}

int N, M;
int depth[MAXN];
int pwInv2[MAXN];
int par[MAXN];
int sumProb[MAXN];
vector<int> adj[MAXN];
vector<int> cycles[MAXN];
vector<int> cycleLens;
vector<int> cycleProbs;

int cntPair(int x) {
   return ((ll) x * (x - 1)) % MOD;
}

void dfs(int v) {
   for (int u : adj[v]) {
      if (!depth[u]) {
         par[u] = v;
         depth[u] = depth[v] + 1;
         dfs(u);
      } else if (depth[u] == depth[v] - 1) {
         // par
      } else if (depth[u] < depth[v] - 1) {
         cycles[v].emplace_back(cycleLens.size());
         cycles[u].emplace_back(cycleLens.size());
         cycleLens.emplace_back(depth[v] - depth[u] + 1);
      }
   }
}

int getSum(vector<int> probs) {
   int sum = 0;
   int sumsq = 0;
   for (int v : probs) {
      add(sum, v);
      add(sumsq, mul(v, v));
   }
   sum = mul(sum, sum);
   sub(sum, sumsq);
   return sum;
}

int main() {
   // ios_base::sync_with_stdio(false);
   scanf("%d %d", &N, &M);
   pwInv2[0] = 1;

   for (int i = 1; i < MAXN; ++i) {
      pwInv2[i] = mul(pwInv2[i - 1], (MOD + 1) / 2);
   }
   for (int i = 0; i < M; ++i) {
      int v, u;
      scanf("%d %d", &v, &u);
      adj[v].emplace_back(u);
      adj[u].emplace_back(v);
   }

   depth[1] = 1;
   dfs(1);

   int E = 0;

   add(E, mul(N, pwInv2[1]));
   sub(E, mul(N - 1, pwInv2[2]));

   for (int v : cycleLens) {
      int cur = mul(pwInv2[2], MOD + 1 - pwInv2[v - 2]);
      sub(E, cur);
      cycleProbs.emplace_back(cur);
   }

   for (int i = 1; i <= N; ++i) {
      for (int id : cycles[i]) {
         add(sumProb[i], cycleProbs[id]);
      }
   }
   int ans = 0;

   add(ans, mul(pwInv2[2], mul(N, N + 1)));
   add(ans, mul(pwInv2[2], N - 1));
   int nPair = cntPair(N - 1);
   for (int i = 1; i <= N; ++i) {
      int deg = adj[i].size() - cycles[i].size();
      add(ans, mul(pwInv2[3], cntPair(deg)));
      sub(nPair, cntPair(deg));
   }
   add(ans, mul(nPair, pwInv2[4]));

   vector<vector<int>> sides(cycleLens.size());
   for (int i = 1; i <= N; ++i) {
      for (int id : cycles[i]) {
         sides[id].emplace_back(i);
      }
   }

   for (int v : cycleProbs) {
      add(ans, v);
   }

   add(ans, getSum(cycleProbs));

   for (int i = 1; i <= N; ++i) {
      vector<int> probs;
      for (int id : cycles[i]) {
         probs.emplace_back(cycleProbs[id]);
      }
      int cur = getSum(probs);
      add(ans, cur);
   }

   for (int i = 0; i < cycleLens.size(); ++i) {
      int v = sides[i][0];
      int u = sides[i][1];
      int len = cycleLens[i];
      if (depth[v] > depth[u]) {
         swap(v, u);
      }
      u = par[u];
      int sumProbs = 0;
      while (u != v) {
         add(sumProbs, sumProb[u]);
         u = par[u];
      }
      sumProbs = mul(sumProbs, 2);
      int cur = mul(pwInv2[2], MOD + 1 - pwInv2[len - 2]);
      sub(ans, mul(cur, sumProbs));
      cur = mul(pwInv2[2], MOD + 1 - pwInv2[len - 3]);
      add(ans, mul(cur, sumProbs));
   }
   int prob = pwInv2[1];
   add(prob, mul(N - 2, pwInv2[3]));
   prob = mul(prob, N - 1);
   prob = mul(prob, MOD - 2);
   add(ans, prob);

   // (vertex, out_edge)
   prob = 0;
   for (int v : cycleLens) {
      int cur = mul(pwInv2[2], (MOD + 1 - pwInv2[v - 2]));
      add(prob, mul(cur, 2));
      cur = mul(pwInv2[3], (MOD + 1 - pwInv2[v - 3]));
      add(prob, mul(cur, v - 2));
      cur = mul(pwInv2[3], (MOD + 1 - pwInv2[v - 2]));
      add(prob, mul(cur, N - v));
   }
   prob = mul(prob, MOD - 2);
   add(ans, prob);
   prob = 0;

   for (int i = 0; i < cycleLens.size(); ++i) {
      int v = sides[i][0];
      int u = sides[i][1];
      int len = cycleLens[i];
      int nEdge = N - 1;
      int degV = adj[v].size() - cycles[v].size();
      int degU = adj[u].size() - cycles[u].size();
      int e = degV + degU - 2;
      nEdge -= e;
      int cur = mul(pwInv2[3], MOD + 1 - pwInv2[len - 2]);
      add(prob, mul(cur, e));
      e = 2;
      nEdge -= e;
      cur = mul(pwInv2[3], MOD + 1 - pwInv2[len - 3]);
      add(prob, mul(cur, e));
      if (len >= 4) {
         e = len - 3;
         nEdge -= e;
         cur = mul(pwInv2[4], MOD + 1 - pwInv2[len - 4]);
         add(prob, mul(cur, e));
      }
      vector<int> cycle;
      if (depth[v] > depth[u]) {
         swap(v, u);
      }
      u = par[u];
      e = 0;
      while (u != v) {
         e += adj[u].size() - cycles[u].size() - 2;
         u = par[u];
      }
      nEdge -= e;
      cur = mul(pwInv2[4], (MOD + 1 - pwInv2[len - 3]));
      add(prob, mul(cur, e));
      cur = mul(pwInv2[4], (MOD + 1 - pwInv2[len - 2]));
      add(prob, mul(cur, nEdge));
   }

   add(ans, mul(prob, 2));

   sub(ans, mul(E, E));

   cout << ans << "\n";

   return 0;
}