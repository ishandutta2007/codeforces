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

const int maxn = 1506;

int n, s, m, k, A[maxn];
int LL[maxn], PLL[maxn];

int pf[maxn];

// dp[ take m' segments ][ up to position i' ] = # { A[i] <= v }
// int dp[maxn][maxn];
int dp[2][maxn];

bool test(int v)
{
	pf[0] = 0;
	REP(i, n) pf[i+1]=pf[i]+(A[i] <=v);

	int cur = 0, lst = 1;
	REP(i, n + 1) dp[cur][i] = 0;
	REP(i, m) {
		swap(cur, lst);
		// populate cur
		dp[cur][0] = 0;
		REP(j, n) {
			int lhs = PLL[j];
			
			dp[cur][j+1] = max(dp[cur][j], dp[lst][j+1]);
			if (lhs <= j) {
				// alternative: choose this one?

				int alt = dp[lst][lhs] + pf[j + 1] - pf[lhs];
				dp[cur][j + 1] = max(dp[cur][j + 1], alt);
			}
		}
	}

	return dp[cur][n] >= k;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> s >> m >> k;
	REP(i, n) cin >> A[i];

	fill_n(LL, n, n);

	REP(i, s) {
		int l, r;
		cin >> l >> r;
		--l; --r;
		// cerr << l << " -> " << r << endl;
		LL[r] = min(LL[r], l);
	}

	PLL[n-1] = LL[n-1];
	for (int i = n - 2; i >= 0; i--) {
		PLL[i] = min(LL[i], PLL[i + 1]);
	}

	// find smallest $v$ for which this works.
	// (picking values <= v)

	int lo = 0, hi = *max_element(A, A + n) + 1;
	assert(!test(lo));

	if (!test(hi)) return cout << "-1\n", 0;
	// assert(test(hi));
	while (hi - lo > 1) {
		int mi = (lo + hi) / 2;
		if (test(mi)) hi = mi;
		else lo = mi;
	}
	cout << hi << endl;

	return 0;
}