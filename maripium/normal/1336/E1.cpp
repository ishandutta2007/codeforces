/*
43 35
20504858163 15301851228 32286570638 10356701382 25364795726 30081058949 21197495279 26540195249 3516221065 23066998120 2895256225 29247156613 21122921838 8711005301 2617076791 29642846740 32649403076 9804494478 13035639220 1664515038 5099487727 7372356890 17259671686 26348945554 21460570944 8595950546 23477043998 12674676512 724595880 12114622855 7748091775 19687390873 14833615687 8209833036 24512447993 5133151401 24276914611 23111361623 16635356716 33109142243 6298977225 21118066665 25089247331
*/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int add(int x, int y) {
   x += y;
   if (x >= MOD) x -= MOD;
   return x;
}

int sub(int x, int y) {
   x -= y;
   if (x < 0) x += MOD;
   return x;
}

using ll = long long;

int mult(int x, int y) {
   return ll(x) * y % MOD;
}

int pw(int x, int y) {
   int ans = 1;
   for (; y > 0; y >>= 1, x = mult(x, x)) {
      if (y & 1) ans = mult(ans, x);
   }
   return ans;
}

void fwht(vector<int> &A, bool inv) {
   // assert(A.size() == (1 << 18));
   int N = 18;
	for (int k = 1; k < (1 << N); k <<= 1) {
		for (int i = 0; i < (1 << N); i += (k << 1)) {
			for (int j = i; j < i + k; ++j) {
				int x = A[j], y = A[j + k];
				A[j] = add(x, y);
				A[j + k] = sub(x, y);
			}
		}
	}
	if (inv) {
		int x = pw(1 << N, MOD - 2);
		for (int i = 0; i < (1 << N); ++i) {
			A[i] = mult(A[i], x);
		}
	}
}

using ll = long long;

mt19937_64 rng(58);

int main() {
   ios_base::sync_with_stdio(false);
   int N, M;
   // N = 100, M = 35;
   cin >> N >> M;
   vector<ll> A;
   for (int i = 0; i < N; ++i) {
      //
      ll x;
      if (!(cin >> x)) break;
      else A.emplace_back(x);
   }
   vector<ll> basis;
   auto f = [&](ll x) { return 1ll << __lg(x); };
   auto __add = [&](ll x) {
      for (ll z : basis) {
         if (x & f(z)) x ^= z;
      }
      if (!x) return false;
      else {
      	for (ll &z : basis) if (z & f(x)) z ^= x;
         basis.emplace_back(x);
         return true;
      }
   };
   int toMult = 1;
   for (ll v : A) {
      if (!__add(v)) toMult = mult(toMult, 2);
   }
   sort(basis.rbegin(), basis.rend());
   int cut = min(18, int(basis.size()));
   vector<ll> l(basis.begin(), basis.begin() + cut);
   vector<ll> r(basis.begin() + cut, basis.end());
   vector<vector<int>> lv(19, vector<int>(1 << 18));
   vector<int> rv(1 << 18);
//   assert(st.size() == basis.size());
   for (int mask = 0; mask < 1 << int(l.size()); ++mask) {
      ll cur = 0;
      // cerr << mask << "\n";
      for (int i = 0; i < int(l.size()); ++i) if (mask & (1 << i)) {
         cur ^= l[i];
      }
      ll sm = cur & ((1 << 18) - 1);
      int cnt = __builtin_popcountll(cur ^ sm);
      // cerr << cnt << " " << sm << "\n";
      ++lv[cnt][sm];
   }
   for (int mask = 0; mask < 1 << int(r.size()); ++mask) {
      ll cur = 0;
      for (int i = 0; i < int(r.size()); ++i) if (mask & (1 << i)) {
         cur ^= r[i];
      }
      ++rv[cur];
      assert(cur < (1 << 18));
   }
   fwht(rv, false);
   vector<int> ans(37);
   auto solve = [&](int cnt) {
      fwht(lv[cnt], false);
      for (int z = 0; z < (1 << 18); ++z) lv[cnt][z] = mult(lv[cnt][z], rv[z]);
      fwht(lv[cnt], true);
      for (int mask = 0; mask < (1 << 18); ++mask) {
         int cur = cnt + __builtin_popcount(mask);
         ans[cur] = add(ans[cur], lv[cnt][mask]);
      }
   };
   for (int i = 0; i <= 18; ++i) {
      solve(i);
   }
   for (int i = 0; i <= M; ++i) {
      cout << mult(ans[i], toMult) << " ";
   }
}