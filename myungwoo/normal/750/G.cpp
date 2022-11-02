#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
typedef long long lld;
typedef pair<int, int> pii;

// popcount(x) = # of non-zero bits of x
// up(x) = 2*x - popcount(x)

lld S;

lld D[64][120][2];

lld solve(lld sum, int popsum, int l, int r)
{
	// a + b == sum
	// popcount(a)+popcount(b) = popsum
	// bit(a) = 10....
	// bit(b) = 11....
	// bitlen(a) == l
	// bitlen(b) == r

	int n = max(l, r);
	if (sum >= 1LL << (n+1)) return 0;
	memset(D, 0, sizeof(D));
	D[0][0][0] = 1;
	for (int len=0;len<n;len++) for (int p=0;p<=popsum;p++) for (int c=0;c<2;c++) if (D[len][p][c]){
		for (int na=0;na<2;na++) for (int nb=0;nb<2;nb++){
			if (len == l-1 && !na || len == l-2 && na || len == r-1 && !nb || len == r-2 && !nb) continue;
			if (len >= l && na || len >= r && nb) continue;
			int now = (na+nb+c) & 1, nxt = (na+nb+c) >> 1;
			if (now != ((sum >> len)&1)) continue;
			if (p+na+nb > popsum) continue;
			D[len+1][p+na+nb][nxt] += D[len][p][c];
		}
	}
	return D[n][popsum][sum >> n];
}

int main()
{
	cin >> S;
	lld ans = 0;
	for (int l=0;l<60;l++) for (int r=0;r<60;r++){
		// Find exact lca
		lld factor = (1LL << (l+1)) + (1LL << (r+1)) - 3;
		lld lca = S / factor;
		if (!lca) continue;

		// Move lca --> 1
		lld new_s = S - (factor * (lca-1));

		for (int popsum=2;popsum<=l+r+2;popsum++){
			lld v = new_s + 1 + popsum;
			// 2(a+b) = v
			if (v <= 0 || (v&1)) continue;
			v >>= 1;
			// a+b = v
			//if (l == 2 && r == 0) printf("%lld %d %d %d : %lld\n", v, popsum, l+1, r+1, solve(v, popsum, l+1, r+1));
			//if (solve(v, popsum, l+1, r+1)) printf("%d %d\n", l, r);
			ans += solve(v, popsum, l+1, r+1);
		}
	}
	cout << ans << endl;
}