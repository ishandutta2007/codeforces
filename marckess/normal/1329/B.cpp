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

int d, mod;
ll mem[35];

ll dp (int n) {
	ll &res = mem[n];
	if (res != -1) return res;
	res = 1;

	for (int j = n; (1 << j) <= d; j++) {
		ll cn = (1 << j);
		cn = min(cn, 1ll * d - (1 << j) + 1);
		(res += cn * dp(j + 1)) %= mod;
	}

	return res;
}

void solve () {
	cin >> d >> mod;
	memset(mem, -1, sizeof(mem));
	cout << MOD(dp(0) - 1, mod) << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}