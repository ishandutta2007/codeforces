#include <bits/stdc++.h>

using namespace std;

using State = array<int, 2>;
const int MAXN = 200200;
const State bases = {7, 13};
const State mods = {998244353, 1000000007};
using ll = long long;

int addmod(int x, int y, int mod) {
   x += y;
   if (x >= mod) x -= mod;
   return x;
}

int submod(int x, int y, int mod) {
   return addmod(x, mod - y, mod);
}

int mulmod(int x, int y, int mod) {
   return (long long) x * y % mod;
}

State operator + (const State &l, const State &r) {
   return {addmod(l[0], r[0], mods[0]), addmod(l[1], r[1], mods[1])};
}

State operator - (const State &l, const State &r) {
   return {submod(l[0], r[0], mods[0]), submod(l[1], r[1], mods[1])};
}
State operator * (const State &l, const State &r) {
   return {mulmod(l[0], r[0], mods[0]), mulmod(l[1], r[1], mods[1])};
}

int N;
char S[MAXN];
State pw[MAXN];
State hs[MAXN];
State hs0[2][MAXN];
int cnt[MAXN];
int nxt[MAXN];
int __nxt[MAXN];
int prv[MAXN];
State getHs(int l, int r) {
   return hs[r] - pw[r - l + 1] * hs[l - 1];
}

State getHs0(int t, int l, int r) {
   return hs0[t][r] - hs0[t][l - 1] * pw[cnt[r] - cnt[l - 1]];
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> N >> (S + 1);
   pw[0] = {1, 1};
   for (int i = 1; i <= N; ++i) {
      pw[i] = pw[i - 1] * bases;
      hs[i] = hs[i - 1] * bases + State{S[i] - '0' + 5, S[i] - '0' + 5};
   }
   nxt[N + 1] = N + 1;
   __nxt[N + 1] = N + 1;
   for (int i = N; i > 0; --i) {
      nxt[i] = nxt[i + 1];
      __nxt[i] = __nxt[i + 1];
      if (S[i] == '1' && S[i + 1] == '1') {
         __nxt[i] = i;
      }
      if (S[i] == '0') {
         nxt[i] = i;
      }
   }
   for (int i = 1; i <= N; ++i) {
      prv[i] = prv[i - 1];
      if (S[i] == '0') prv[i] = i;
   }
   for (int i = 1; i <= N; ++i) {
      if (S[i] == '1') {
         hs0[0][i] = hs0[0][i - 1];
         hs0[1][i] = hs0[1][i - 1];
         cnt[i] = cnt[i - 1];
      } else {
         hs0[0][i] = hs0[0][i - 1] * bases + State{i & 1, i & 1};
         hs0[1][i] = hs0[1][i - 1] * bases + State{i & 1 ^ 1, i & 1 ^ 1};
         cnt[i] = cnt[i - 1] + 1;
      }
   }
   int Q;
   cin >> Q;
   while (Q--) {
      int xl, yl, len;
      cin >> xl >> yl >> len;
      int xr = xl + len - 1;
      int yr = yl + len - 1;
      bool canMove = (__nxt[xl] < xr) && (__nxt[yl] < yr);
      if (!canMove) {
         if (getHs(xl, xr) == getHs(yl, yr)) {
            cout << "YES\n";
         } else {
            cout << "NO\n";
         }
         continue;
      }
      bool have0 = (cnt[xr] > cnt[xl - 1] && cnt[yr] > cnt[yl - 1]);
      if (!have0) {
         if (getHs(xl, xr) == getHs(yl, yr)) {
            cout << "YES\n";
         } else {
            cout << "NO\n";
         }
         continue;
      }
      int x0 = cnt[xr] - cnt[xl - 1];
      int y0 = cnt[yr] - cnt[yl - 1];
      auto x = getHs0((xl - 1) & 1, nxt[xl], prv[xr]);
      auto y = getHs0((yl - 1) & 1, nxt[yl], prv[yr]);
      if (x == y && x0 == y0) {
         cout << "YES\n";
      } else {
         cout << "NO\n";
      }
   }
}