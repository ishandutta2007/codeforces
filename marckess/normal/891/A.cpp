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

const int MX = 2005;
int n, a[MX], g, mn, c;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn(i, n) {
		cin >> a[i];
		g = __gcd(g, a[i]);
		if (a[i] == 1) c++;
	}

	if (c) {
		cout << n - c << endl;
		return 0;
	}

	mn = n;

	if (g > 1) {
		cout << -1 << endl;
		return 0;
	}

	forr(i, 0, n - 1) {
		g = 0;
		forr(j, i, n - 1) {
			g = __gcd(g, a[j]);
			if (g == 1) {
				mn = min(mn, j - i + 1);
			}
		}
	}

	cout << mn + n - 2 << endl;

	return 0;
}