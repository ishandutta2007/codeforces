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
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
ll n, m, a[MX], s = 0, mx = 0, res = 0;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
		mx = max(mx, a[i]);
	}

	sort(a, a+n);

	ll acu = 0;
	for (int i = 0; i < n; i++) {
		acu += a[i], res += a[i];
		if (i) acu -= a[i-1], res -= a[i-1];

		if (acu) acu--;
		else res++;
	}

	cout << s - res << endl;

	return 0;
}