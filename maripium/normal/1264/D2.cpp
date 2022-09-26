#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000100;
const int MOD = 998244353;

int add(int x, int y) {
   x += y;
   if (x >= MOD) {
      x -= MOD;
   }
   return x;
}

int mul(int x, int y) {
   return (long long) x * y % MOD;
}

int pw(int x, int y) {
   int ans = 1;
   for (; y > 0; y >>= 1, x = mul(x, x)) {
      if (y & 1) {
         ans = mul(ans, x);
      }
   }
   return ans;
}

int N;
char S[MAXN];
int prefO[MAXN];
int prefC[MAXN];
int prefQ[MAXN];
int fact[MAXN];
int ifact[MAXN];
int sum[MAXN];
int sum1[MAXN];

void precalc() {
   fact[0] = 1;
   for (int i = 1; i < MAXN; ++i) {
      fact[i] = mul(fact[i - 1], i);
   }
   ifact[MAXN - 1] = pw(fact[MAXN - 1], MOD - 2);
   for (int i = MAXN - 1; i > 0; --i) {
      ifact[i - 1] = mul(ifact[i], i);
   }
}

int C(int N, int K) {
   if (N < K || K < 0) {
      return 0;
   }
   return mul(fact[N], mul(ifact[K], ifact[N - K]));
}

void precalc(int N, int *sum) {
   for (int i = 0; i <= N; ++i) {
      sum[i] = C(N, i);
      if (i > 0) {
         sum[i] = add(sum[i], sum[i - 1]);
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   precalc();
   cin >> (S + 1);
   N = strlen(S + 1);
   for (int i = 1; i <= N; ++i) {
      prefO[i] = prefO[i - 1] + (S[i] == '(');
      prefC[i] = prefC[i - 1] + (S[i] == ')');
      prefQ[i] = prefQ[i - 1] + (S[i] == '?');
   }
   precalc(prefQ[N], sum);
   if (prefQ[N]) {
      precalc(prefQ[N] - 1, sum1);
   }
   int ans = 0;
   for (int i = 1; i <= N; ++i) {
      if (S[i] == ')') continue;
      int lQ = prefQ[i - 1];
      int rQ = prefQ[N] - prefQ[i];
      int lO = prefO[i - 1] + 1;
      int rC = prefC[N] - prefC[i];
      int lim = min(lQ + rQ, rQ + rC - lO);
      if (lim >= 0) {
         ans = add(ans, (lQ + rQ == prefQ[N]) ? sum[lim] : sum1[lim]);
      }
   }
   cout << ans << "\n";
   return 0;
}