#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200200;
const int MOD = 998244353;

int add(int x, int y) {
   x += y;
   if (x >= MOD) {
      x -= MOD;
   }
   return x;
}

int sub(int x, int y) {
   x -= y;
   if (x < 0) {
      x += MOD;
   }
   return x;
}

int mul(int x, int y) {
   return (long long) x * y % MOD;
}

int inv(int x) {
   int y = MOD - 2;
   int ans = 1;
   for (; y > 0; y >>= 1, x = mul(x, x)) {
      if (y & 1) {
         ans = mul(ans, x);
      }
   }
   return ans;
}

int N, Q;
int P[MAXN];
set<int> ps;
int prefProb[MAXN];
int prefSeries[MAXN];

int getCost(int l, int r) {
   int down = mul(prefProb[r - 1], inv(prefProb[l - 1]));
   int up = sub(prefSeries[r - 1], prefSeries[l - 1]);
   up = mul(up, inv(prefProb[l - 1]));
   up = add(up, 1);
   up = sub(up, down);
   return mul(up, inv(down));
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> N >> Q;
   for (int i = 1; i <= N; ++i) {
      cin >> P[i];
      P[i] = mul(P[i], inv(100));
   }
   prefProb[0] = 1;
   for (int i = 1; i <= N; ++i) {
      prefProb[i] = mul(prefProb[i - 1], P[i]);
      prefSeries[i] = add(prefSeries[i - 1], prefProb[i]);
   }
   ps.emplace(1);
   ps.emplace(N + 1);
   int tot = getCost(1, N + 1);
   while (Q--) {
      int v;
      cin >> v;
      if (ps.count(v)) {
         auto it = ps.find(v);
         auto lt = prev(it);
         auto rt = next(it);
         tot = add(tot, getCost(*lt, *rt));
         tot = sub(tot, getCost(*lt, v));
         tot = sub(tot, getCost(v, *rt));
         ps.erase(it);
      } else {
         auto it = ps.insert(v).first;
         auto lt = prev(it);
         auto rt = next(it);
         tot = sub(tot, getCost(*lt, *rt));
         tot = add(tot, getCost(*lt, v));
         tot = add(tot, getCost(v, *rt));
      }
      cout << tot << "\n";
   }
}