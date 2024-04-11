#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n;

void solve () {
	vi res;
	ll sum = 1;

	cin >> n;

	res.pb(1);
	for (ll i = 2; sum < n; i *= 2) {
		sum += i;
		res.pb(i);
	}

	res.back() -= sum - n;
	sort(all(res));

	cout << res.size() - 1 << endl;
	for (int i = 1; i < res.size(); i++)
		cout << res[i] - res[i - 1] << " ";
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}