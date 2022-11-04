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

const int MX = 2005;
int n, f;
ll a[MX], b[MX], c[MX], res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn(i, n)
		cin >> a[i] >> b[i] >> c[i];

	for (int i = 0; i < n; i++) {
		map<ii, int> mp;

		for (int j = i + 1; j < n; j++) {
			ll ai = a[i] * a[i] + b[i] * b[i];
			ll aj = a[j] * a[j] + b[j] * b[j];

			ll p = b[i] * c[i] * aj - b[j] * c[j] * ai;
			ll q = a[i] * c[i] * aj - a[j] * c[j] * ai;

			ll g = __gcd(p, q);
			if (g) p /= g, q /= g;
			if (q < 0) p = -p, q = -q;
			if (!q) p = abs(p);

			if (p || q) {
				res += mp[ii(p, q)]++;
			} else {
				res += n - i - 2;
			}
		}
	}

	cout << res << endl;

	return 0;
}