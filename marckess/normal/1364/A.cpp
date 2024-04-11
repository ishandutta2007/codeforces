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

const int MX = 100005;
int n, x, a[MX], p = -1, s[MX], res = -1;

void solve () {
	cin >> n >> x;
	res = p = -1;

	forn (i, n) {
		cin >> a[i];
		s[i] = a[i];

		if (i) s[i] += s[i - 1];

		if (s[i] % x) res = max(res, i + 1);
		else if (p != -1) res = max(res, i - p);

		if (s[i] % x && p == -1) p = i;
	}

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