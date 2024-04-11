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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const ll mod = 1e9 + 7;

vector<pair<ll, int>> pf(ll N) {
	vector<pair<ll, int>> r;
	for (ll p = 2; p * p <= N; p++) {
		if (N % p == 0) {
			int e = 0;
			while (N % p == 0) e++, N /= p;
			r.eb(p, e);
		}
	}
	if (N > 1) r.eb(N, 1);
	return r;
}

ll powmod(ll b, ll e) {
	ll r = 1;
	for (; e; e /= 2, b = b*b% mod) if (e & 1) r= r*b%mod;
	return r;
}

ll modinv(ll x) { return powmod(x, mod - 2); }

typedef vector<vector<ll>> mat;

mat mulmat(mat a, mat b) {
	mat c(a.size(), vector<ll>(b[0].size(), 0));
	REP(i, (int) a.size()) REP(j, (int) b.size()) REP(k, (int) b[0].size()) {
		c[i][k] = (c[i][k] + a[i][j] * b[j][k]) % mod;
	}
	return c;
}

mat powmod(mat b, int e) {
	mat r(b.size(), vector<ll>(b.size(), 0));
	REP(i, (int) b.size()) r[i][i] = 1;
	for (; e; e /= 2, b = mulmat(b, b)) if (e & 1) r = mulmat(r, b);
	return r;
}


ll solve(ll p, int e, int k) {
	p %= mod;

	mat A(e + 1, vector<ll>(e + 1, 0));
	for (int j = 0; j <= e; j++) {
		ll jinv = modinv(j + 1);
		for (int i = 0; i <= j; i++) {
			A[i][j] = jinv;
		}
	}

	mat powe = powmod(A, k);

	vector<ll> prob(e + 1);
	for (int i = 0; i <= e; i++) prob[i] = powe[i][e];

	ll powp = 1;
	ll ret = 0;
	for (int i = 0; i <= e; i++) {
		// cerr << i << " has prob " << prob[i] << endl;
		ret = (ret + powp * prob[i]) % mod;
		powp = powp * p % mod;
	}
	// cerr << p << ": " << ret << endl;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll N;
	int K;
	cin >> N >> K;

	auto pfs = pf(N);

	ll ret = 1;
	for (auto pp : pfs) {
		ret = ret * solve(pp.x, pp.y, K) % mod;
	}
	cout << ret << endl;
	return 0;
}