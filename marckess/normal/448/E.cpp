#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100000;
map<ll, vector<ll>> dp;
ll x, k, c = 0;

void obtDiv (ll n) {
	vector<ll> &f = dp[n];

	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			f.push_back(i);
			if (i * i < n)
				f.push_back(n/i);
		}
	}

	sort(ALL(f));
}

void obtRes (ll n, int lvl) {
	if (c > MX) return;

	if (lvl == k) {
		cout << n << " ";
		c++;
		return;
	}

	if (n == 1) {
		cout << 1 << " ";
		c++;
		return;
	}

	if (!dp.count(n))
		obtDiv(n);

	for (ll x : dp[n])
		if (c < MX)
			obtRes(x, lvl+1);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> x >> k;
	
	obtRes(x, 0);
	cout << endl;

	return 0;
}