#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define rep(i,a,b) for (auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

ostream& operator<<(ostream &out, const ii &pr) { return out << '(' << pr.x << ',' << pr.y << ')'; }

ll f(ll X, ll k, ll a, ll b)
{
	if (X == 1) return 0;
	if (k == 1 || X < k) return (X - 1) * a;

	vector<ll> r;
	while (X) {
		r.pb(X % k);
		X /= k;
	}

	ll cost = (r.size() - 1) * b;
	for (ll x : r) cost += x * a;

	ll best = cost;

	while (r.size() > 1) {
		ll bc = r.back();
		r.pop_back();
		r.back() += bc * k;

		cost += bc * (k - 1) * a - b;
		best = min(best, cost);
	}
	return best - a;
}

void run()
{
	ll x, k, a, b;
	cin >> x >> k >> a >> b;
	ll ans = f(x, k, a, b);
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	run();

	return 0;
}