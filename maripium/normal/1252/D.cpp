#pragma optimize("-Ofast")

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1 << 19;
const int LG = 19;
const int MOD = 998244353;


int rev[MAXN];
int rts[MAXN + 1];
int inv[MAXN + 1];

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

int pw(int x, int y) {
   int ans = 1;
   for (; y > 0; y >>= 1, x = mul(x, x)) {
      if (y & 1) {
         ans = mul(ans, x);
      }
   }
   return ans;
}

void precalc() {
   for (int i = 0; i < MAXN; ++i) {
      for (int j = 0; j < LG; ++j) {
         if (i >> j & 1) {
            rev[i] |= (1 << (LG - j - 1));
         }
      }
   }
   for (int i = 1; i <= MAXN; i <<= 1) {
      inv[i] = pw(i, MOD - 2);
   }
   int z = pw(3, (MOD - 1) / MAXN);
   rts[0] = 1;
   for (int i = 1; i <= MAXN; ++i) {
      rts[i] = mul(rts[i - 1], z);
   }
}

void fft(vector<int> &A, int sgn) {
   int N = A.size();
   int d = LG - __lg(N);
   for (int i = 0; i < N; ++i) {
      int crev = rev[i] >> d;
      if (i < crev) {
         swap(A[i], A[crev]);
      }
   }
   for (int len = 2; len <= N; len <<= 1) {
      int delta = MAXN / len * sgn;
      for (int i = 0; i < N; i += len) {
         int *w = sgn > 0 ? rts : rts + MAXN;
         for (int j = 0; j < (len >> 1); ++j) {
            int v = A[i + j];
            int u = mul(*w, A[i + j + (len >> 1)]);
            A[i + j] = add(v, u);
            A[i + j + (len >> 1)] = sub(v, u);
            w += delta;
         }
      }
   }
   if (sgn == -1) {
      for (int i = 0; i < N; ++i) {
         A[i] = mul(A[i], inv[N]);
      }
   }
}

vector<int> multiply(vector<int> A, vector<int> B) {
   int NA = A.size();
   int NB = B.size();
   int N = 1;
   while (N < max(NA, NB)) {
      N <<= 1;
   }
   N <<= 1;
   A.resize(N);
   B.resize(N);
   fft(A, 1);
   fft(B, 1);
   for (int i = 0; i < N; ++i) {
      A[i] = mul(A[i], B[i]);
   }
   fft(A, -1);
   A.resize(NA + NB - 1);
   return A;
}

int main() {
   ios_base::sync_with_stdio(false);
   precalc();
   int N;
   cin >> N;
   map<int, int> facs;
   for (int i = 0; i < N; ++i) {
      int x;
      cin >> x;
      ++facs[x];
   }
   vector<vector<int>> polys;
   for (auto z : facs) {
      polys.emplace_back(z.second + 1, 1);
   }

   sort(polys.begin(), polys.end());
   function<vector<int>(int, int)> solve = [&](int l, int r) {
      if (l == r) {
         return polys[l];
      } else {
         int md = (l + r) >> 1;
         return multiply(solve(l, md), solve(md + 1, r));
      }
   };

   auto ans = solve(0, polys.size() - 1);

   assert(ans.size() == N + 1);

   cout << ans[N / 2] << "\n";
   return 0;
}