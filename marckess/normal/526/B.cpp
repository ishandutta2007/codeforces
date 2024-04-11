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
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = (1 << 11) + 5;
int n, a[MX], s[MX], mx, b[MX], res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 2; i < (1 << n + 1); i++)
		cin >> a[i];

	for (int i = 1 << n; i < (1 << n + 1); i++) {
		int x = i;

		while (x > 1) {
			s[i] += a[x];
			x /= 2;
		}
		
		mx = max(mx, s[i]);
	}

	for (int i = 1 << n; i < (1 << n + 1); i++) {
		b[i] = mx - s[i];
		res += b[i];
	}

	for (int i = (1 << n) - 1; i > 1; i--) {
		b[i] = min(b[2 * i], b[2 * i + 1]);
		res -= b[i];
	}

	cout << res << endl;

	return 0;
}