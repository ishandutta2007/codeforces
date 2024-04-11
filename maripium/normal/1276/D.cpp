#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
const int MOD = 998244353;
 
struct Mint {
   int x;
   Mint(ll _x = 0) {
      _x %= MOD;
      if (_x < 0) {
         _x += MOD;
      }
      x = _x;
   }
   explicit operator int() const { return x; }
   Mint operator + (const Mint &mt) const {
      Mint ans;
      ans.x = x + mt.x;
      if (ans.x >= MOD) {
         ans.x -= MOD;
      }
      return ans;
   }
   Mint operator - (const Mint &mt) const {
      Mint ans;
      ans.x = x - mt.x;
      if (ans.x < 0) {
         ans.x += MOD;
      }
      return ans;
   }
   Mint operator * (const Mint &mt) const {
      return Mint((ll) x * mt.x);
   }
   friend Mint& operator += (Mint &l, const Mint &r) { l = l + r; }
   friend Mint& operator -= (Mint &l, const Mint &r) { l = l - r; }
   friend Mint& operator *= (Mint &l, const Mint &r) { l = l * r; }
   friend ostream& operator << (ostream& os, Mint &mt) {
      return os << int(mt);
   };
};
 
const int MAXN = 200200;
 
int N;
vector<int> adj[MAXN];
Mint stillAlive[MAXN];
Mint lateDie[MAXN];
Mint earlyDie[MAXN];
Mint killedByPar[MAXN];
 
void Dfs(int v, int p) {
   stillAlive[v] = 1;
   bool toPar = false;
   for (int u : adj[v]) {
      if (u != p) {
         Dfs(u, v);
         if (toPar) {
            lateDie[v] *= (stillAlive[u] + lateDie[u] + earlyDie[u]);
            lateDie[v] += stillAlive[v] * (lateDie[u] + stillAlive[u]);
            earlyDie[v] *= (stillAlive[u] + lateDie[u] + earlyDie[u]);
            killedByPar[v] *= (stillAlive[u] + lateDie[u] + earlyDie[u]);
            stillAlive[v] *= (earlyDie[u] + killedByPar[u]);
         } else {
            earlyDie[v] *= (stillAlive[u] + lateDie[u] + earlyDie[u]);
            earlyDie[v] += stillAlive[v] * (lateDie[u] + stillAlive[u]);
            stillAlive[v] *= (earlyDie[u] + killedByPar[u]);
         }
      } else {
         killedByPar[v] = stillAlive[v];
         toPar = true;
      }
   }
}
 
int main() {
   ios_base::sync_with_stdio(false);
   cin >> N;
   for (int i = 0; i < N - 1; ++i) {
      int v, u;
      cin >> v >> u;
      --v, --u;
      adj[v].emplace_back(u);
      adj[u].emplace_back(v);
   }
   Dfs(0, -1);
   cout << int(stillAlive[0] + earlyDie[0]) << "\n";
   return 0;
}