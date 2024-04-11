#include <bits/stdc++.h>

using namespace std;

int MOD;

int add(int x, int y) { return ((x += y) >= MOD) ? x - MOD : x; }
int sub(int x, int y) { return ((x -= y) < 0) ? x + MOD : x; }
int mul(int x, int y) { return (long long) x * y % MOD; }
int pw(int x, int y) {
   int ans = 1;
   for (; y > 0; y >>= 1, x = mul(x, x)) { if (y & 1) ans = mul(ans, x); }
   return ans;
}

const int MAXN = 250250;

int fact[MAXN];
int ifact[MAXN];

int main() {
   ios_base::sync_with_stdio(false);
   int N;
   cin >> N >> MOD;
   fact[0] = 1;
   ifact[0] = 1;
   for (int i = 1; i <= N; ++i) {
      fact[i] = mul(fact[i - 1], i);
      ifact[i] = pw(ifact[i], MOD - 2);
   }
   int ans = 0;
   for (int i = 1; i <= N; ++i) {
      ans = add(ans, mul(mul(N - i + 1, N - i + 1), mul(fact[i], fact[N - i])));
   }
   cout << ans << "\n";
}