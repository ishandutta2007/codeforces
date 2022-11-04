#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005;
int n, m, k, s, c = 1;
ll a[MX], res = 1e18;
bitset<MX> bs;
int ant[MX];

void no() {
	cout << -1 << endl;
	exit(0);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	bs.set();

	cin >> n >> m >> k;

	while (m--) {
		cin >> s;
		if (!s) no();
		bs[s] = 0;
	}

	for (int i = 1; i <= k; i++) cin >> a[i];

	ant[0] = 0;
	for (int i = 1; i < n; i++) {
		if (bs[i]) ant[i] = i;
		else ant[i] = ant[i-1];
		c = max(c, i - ant[i] + 1);
	}

	for (int i = c; i <= k; i++) {
		int x = 0;
		for (int j = 0; j < n; ) {
			x++;
			j += i;
			if (j < n) j = ant[j];
		}
		res = min(res, ll(x) * a[i]);
	}

	if (res == 1e18) no();
	else cout << res << endl;

	return 0;
}