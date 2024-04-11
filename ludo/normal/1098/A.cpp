#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vi p(n), h(n), S(n), A(n);
	vvi E(n);
	for (int i = 1; i < n; i++) {
		cin >> p[i]; p[i]--;
		E[p[i]].pb(i);
	}
	h[0] = 0;
	REP(i, n) cin >> S[i];

	A[0] = S[0];
	for (int i = 1; i < n; i++) {
		h[i] = h[p[i]] + 1;
		if (h[i] & 1) {
			// unknown sum...
			int here = 1e9;
			if (E[i].empty()) here = 0;
			for (int j : E[i]) here = min(here, S[j] - S[p[i]]);

			if (here < 0) return printf("-1\n"), 0;

			A[i] = here;
			S[i] = S[p[i]] + A[i];
		} else {
			A[i] = S[i] - S[p[i]];
			if (A[i] < 0) return printf("-1\n"), 0;
		}
	}

	ll ret = 0;
	REP(i, n) ret += A[i];
	printf("%lld\n", ret);
	return 0;
}