#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005;
int n;
ll a[MX], b[MX];
vi f;

bool esPos (int x) {
	forr (i, 1, n - 1)
		if (a[i] % x && b[i] % x)
			return 0;
	return 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	cin >> n;
	forn(i, n) cin >> a[i] >> b[i];

	for (int i = 2; i < MX; i++)
		while (a[0] % i == 0) {
			f.pb(i);
			a[0] /= i;
		}

	for (int i = 2; i < MX; i++)
		while (b[0] % i == 0) {
			f.pb(i);
			b[0] /= i;
		}

	if (a[0] > 1) f.pb(a[0]);
	if (b[0] > 1) f.pb(b[0]);

	sort(all(f));
	f.erase(unique(all(f)), f.end());

	for (int x : f)
		if (esPos(x)) {
			cout << x << endl;
			return 0;
		}

	cout << -1 << endl;
 
	return 0;
}