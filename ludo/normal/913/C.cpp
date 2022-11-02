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
typedef vector<ll> vi;

const int MAXN = 100;

int N;
ll v[MAXN], mv[MAXN];

ll solve(ll L)
{
	if (L == 0) return 0;

	int k = 0;
	while (k + 1 < N && (1LL << (k + 1)) < L) k++;
	// (1LL << k) < L

	if (k + 1 >= N) {
		ll Q = L / (1LL << k);

		return Q * v[k] + solve(L - Q * (1LL << k));
	}

	ll alt = mv[k + 1];
	// cerr << L << ": " << alt << " " << k << " " << v[k] << endl;
	return min(alt, v[k] + solve(L - (1LL << k)));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll L;
	cin >> N >> L;
	REP(i, N) cin >> v[i];

	rep(i, 1, N) v[i] = min(v[i], 2 * v[i - 1]);

	mv[N - 1] = v[N - 1];
	for (ll i = N - 2; i >= 0; i--)
		mv[i] = min(v[i], mv[i + 1]);

	cout << solve(L) << endl;
	return 0;
}