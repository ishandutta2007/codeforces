//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const ll MAXQ = 1e5 + 10;

ll S, N;
ll quads[MAXQ];

bool canbf(ll bf) {
	if (bf == 1) { return S == N * (N - 1) / 2; }

	ll curs = S;
	ll nodesl = N - 1;
	ll lasttake = 1;
	while (curs > 0 && nodesl != 0) {
		curs -= nodesl;

		ll maxonl = lasttake * bf;
		// limit by 1 + \dots + 

		ll idx = lower_bound(quads, quads + MAXQ, curs) - quads;
		// quads[idx] >= curs
		// we have to have at least idx nodes left.
		maxonl = min(maxonl, nodesl - idx);

		nodesl -= maxonl;
		lasttake = maxonl;
	}
	return curs == 0 && nodesl == 0;
}

void printsol(ll bf) {
	if (bf == 1) {
		printf("Yes\n");
		REP(i, N-1) printf("%d ", i+1);
		printf("\n");
		return;
	}

	vi ath;

	ll curs = S;
	ll nodesl = N - 1;
	ll lasttake = 1;

	ath.pb(lasttake);
	while (curs > 0 && nodesl != 0) {
		curs -= nodesl;

		ll maxonl = lasttake * bf;
		// limit by 1 + \dots + 

		ll idx = lower_bound(quads, quads + MAXQ, curs) - quads;
		// quads[idx] >= curs
		// we have to have at least idx nodes left.
		maxonl = min(maxonl, nodesl - idx);

		nodesl -= maxonl;
		lasttake = maxonl;
	
		ath.pb(lasttake);
	}
	assert(curs == 0 && nodesl == 0);

	vi par(N);
	ll seen = 0;
	for (ll i = 1; i < (ll) ath.size(); i++) {
		ll md = ath[i - 1];
		for (ll j = 0; j < ath[i]; j++) {
			par[seen + md + j] = seen + (j % md);
		}
		seen += ath[i - 1];
	}

	printf("Yes\n");
	for (ll i = 1; i < N; i++)
		printf("%lld ", 1+par[i]);
	printf("\n");
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	REP(i, MAXQ) quads[i] = 1LL * i * (i + 1) / 2;

	cin >> N >> S;

	if (S < 2 * N - 1) return printf("No\n"), 0;
	if (2LL * S > N * (N + 1)) return printf("No\n"), 0;

	// the smaller S, the larger the branching factor
	// the bigger S, the smaller branching factor

	S -= N; // the root always has subtree height N.
	// S >= N-1 >= 1

	ll lo = 0, hi = N; // branching factor of N is always possible.
	assert(canbf(hi));
	while (hi - lo > 1) {
		ll mid = (lo+hi)/2;
		if (canbf(mid)) hi = mid;
		else lo = mid;
	}
	fprintf(stderr, "Branching factor: %lld\n", hi);
	printsol(hi);
	return 0;
}