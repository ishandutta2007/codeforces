#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int n;
ii p[MX];

ii operator - (ii a, ii b) {
	return {a.fi - b.fi, a.se - b.se};
}

ll operator % (ii a, ii b) {
	return 1ll * a.fi * b.se - 1ll * a.se * b.fi;
}

ll abs (ii a) {
	return 1ll * a.fi * a.fi + 1ll * a.se * a.se;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i].fi >> p[i].se;

	if (n % 2) {
		cout << "no" << endl;
		return 0;
	}

	for (int i = 0; i < n / 2; i++) {
		ii a = p[i + 1] - p[i];
		ii b = p[(i + n / 2 + 1) % n] - p[(i + n / 2) % n];

		if (a % b != 0 || abs(a) != abs(b)) {
			cout << "no" << endl;
			return 0;
		}
	}

	cout << "yes" << endl;

	return 0;
}