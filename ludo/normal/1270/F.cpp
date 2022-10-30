#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MAXN = 200'000;
const int MAXT = sqrt(MAXN) + 1;

char S[MAXN + 1];
int n, T, pf[MAXN + 1];

int cnt[MAXT * MAXN + MAXN + 1] = {};

int main() {
	fgets(S, 200'001, stdin);
	n = strlen(S);
	if (S[n-1] == '\n') {
		S[--n] = '\0';
	}

	T = (int) sqrt(n);
	// T = n;

	pf[0] = 0;
	for (int i=1; i <= n; i++) {
		pf[i] = pf[i-1] + (S[i-1] == '1');
	}

	ll ans = 0;

	// k <= T
	for (int k=1; k <= T; k++) {
		for (int i=0; i <= n; i++) {
			int val = k * pf[i] + n - i;
			assert(0 <= val && val <= MAXT * MAXN + MAXN);

			if ((cnt[val] >> 18) != k) cnt[val] = k<<18;
			ans += cnt[val] & ((1<<18) - 1);
			cnt[val]++;
		}
		// fprintf(stderr, "k=%d: %lld\n", k, ans);
	}

	fprintf(stderr, "n=%d, T=%d\n", n, T);
	fprintf(stderr, "Low count: %lld\n", ans);

	// k > T: #1s  n/k  n.
	vi ones;
	for (int i=0; i<n; i++)
		if (S[i] == '1')
			ones.pb(i);
	for (int rpos = n-1; rpos >= 0 && !ones.empty(); rpos--) {
		// number of ones:
		ll inc = 0;

		int lpos = ones.back(), pos = ones.size() - 1, nr_ones = 1;
		while (nr_ones <= T) {
			int npos = pos ? ones[pos-1]+1 : 0;
			// determine all values for k between [npos, lpos] -- rpos.
			// all these intervals have nr_ones nr of ones.
			// the length must be a multiple of nr_ones...

			int end_len = 1 + rpos - npos;
			int sta_len = 1 + rpos - lpos;

			sta_len = max(sta_len, nr_ones * (T+1));
			if (sta_len <= end_len) {
				int r1 = end_len % nr_ones, r2 = sta_len % nr_ones;
				if (r1 != 0) end_len -= r1;
				if (r2 != 0) sta_len += nr_ones - r2;

				// fprintf(stderr, "(rpos, nr_ones) = (%d, %d): %d, %d, %d, %d\n", rpos, nr_ones, npos, lpos, sta_len, end_len);

				if (sta_len <= end_len) {
					inc += (end_len - sta_len) / nr_ones + 1;
				}
			}

			if (pos == 0) break;
			lpos = ones[--pos];
			nr_ones++;
		}

		// fprintf(stderr, "r=%d: %lld\n", rpos, inc);
		ans += inc;
		if (ones.back() == rpos) ones.pop_back();
	}

	printf("%lld\n", ans);
	return 0;
}