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
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005;
int n, p[MX], x, a, y, b;
ll k;

bool esPos (int m) {
	int j = 1;
	ll acu = 0;

	for (int i = 1; i <= m; i++)
		if (i % a == 0 && i % b == 0) {
			acu += p[j] * (1ll * x + y) / 100;
			j++;
		}
	
	for (int i = 1; i <= m; i++)
		if (i % a == 0 && i % b != 0) {
			acu += p[j] * (1ll * x) / 100;
			j++;
		}

	for (int i = 1; i <= m; i++)
		if (i % a != 0 && i % b == 0) {
			acu += p[j] * (1ll * y) / 100;
			j++;
		}

	return acu >= k;
}

void solve () {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	cin >> x >> a;
	cin >> y >> b;
	cin >> k;
	sort(p+1, p+n+1, greater<int>());

	if (x < y) {
		swap(x, y);
		swap(a, b);
	}

	int i = 1, j = n + 1, rep = 20;
	while (rep--) {
		int m = (i + j) / 2;
		if (esPos(m)) j = m;
		else i = m;
	}

	if (j > n) cout << -1 << endl;
	else cout << j << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}