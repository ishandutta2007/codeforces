#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

ll n, k, p;

bool query (ll a, ll b) {
	cout << a << " " << b << endl;
	fflush(stdout);
	string s;
	cin >> s;
	if (s == "Bad") exit(0);
	return s == "Yes";
}

ll rand (ll a, ll b) {
	return rand() % (b - a + 1) + a;
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	srand(time(0));

	cin >> n >> k;

	ll i = 1, j = n, rep = 4500;

	while (rep--) {
		if (j - i + 1 <= 50) {
			ll d = rand(i, j);
			if (query(d, d))
				return 0;
			i = max(1ll, i-k);
			j = min(n, j+k);
			continue;
		} 

		ll m = (i+j)/2;
		if (query(i, m)) {
			i = max(1ll, i-k);
			j = min(n, m+k);
		} else {
			i = max(1ll, m-k);
			j = min(n, j+k);
		}
	}

	return 0;
}