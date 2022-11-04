#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 105;
int n, m, a[MX], b[MX], sa[MX], sb[MX], res;

void solve () {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sa[i] = a[i] + sa[i - 1];
	}
	
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		sb[i] = b[i] + sb[i - 1];
	}
	
	res = 0;
	forn (i, n + 1) forn (j, m + 1)
		res = max(res, sa[i] + sb[j]);
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}