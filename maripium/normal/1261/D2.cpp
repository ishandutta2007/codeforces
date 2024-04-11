#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200200;
const int MOD = 998244353;

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

int N, K;
int A[MAXN];
int pwK[MAXN];
int pwK2[MAXN];
int fact[MAXN];
int ifact[MAXN];

int C(int N, int K) {
   if (K < 0 || N < K) {
      return 0;
   } else {
      return mul(fact[N], mul(ifact[K], ifact[N - K]));
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> N >> K;
   fact[0] = 1;
   pwK[0] = 1;
   pwK2[0] = 1;
   for (int i = 1; i <= N; ++i) {
      fact[i] = mul(fact[i - 1], i);
      pwK[i] = mul(pwK[i - 1], K);
      pwK2[i] = mul(pwK2[i - 1], K + MOD - 2);
   }
   ifact[N] = pw(fact[N], MOD - 2);
   for (int i = N; i > 0; --i) {
    ifact[i - 1] = mul(ifact[i], i);
   }
   for (int i = 0; i < N; ++i) {
      cin >> A[i];
   }
   int cntDiff = 0;
   for (int i = 0; i < N; ++i) {
      cntDiff += (A[i] != A[(i + 1) % N]);
   }
   int ans = 0;
   for (int i = 0; i <= cntDiff; i += 2) {
      add(ans, mul(C(cntDiff, i), mul(C(i, i / 2), pwK2[cntDiff - i])));
   }
   ans = mul(ans, pwK[N - cntDiff]);
   int realAns = pwK[N];
   sub(realAns, ans);
   realAns = mul(realAns, (MOD + 1) / 2);
   cout << realAns << "\n";
   return 0;
}