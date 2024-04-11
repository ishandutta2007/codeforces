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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;
int n, x;
ll a[MX], izq[MX], der[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> x;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	ll mx = 0, s = 0;
	for (int i = 1; i <= n; i++) {
		s += a[i];
		s = max(0ll, s);
		mx = max(mx, s);
		izq[i] = s;
	}
	mx *= x;

	if (x > 0) {
		cout << mx << endl;
		return 0;
	}

	s = 0;
	for (int i = n; i >= 1; i--) {
		s += a[i];
		s = max(0ll, s);
		der[i] = s;
	}

	s = 0;
	for (int i = 1; i <= n; i++) {
		s += a[i] * x;
		s = max(s, izq[i]);
		mx = max(mx, s + der[i+1]);
	}

	cout << mx << endl;

	return 0;
}