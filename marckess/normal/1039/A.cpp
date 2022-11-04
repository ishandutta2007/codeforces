#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, x[MX], c = 0;
ll t, a[MX], mn[MX], mx[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	fill(mx, mx+MX, 3e18);

	cin >> n >> t;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> x[i];

	for (int i = 1; i <= n; i++) {
		mn[x[i]] = max(mn[x[i]], a[i]+t);
		mn[i] = max(mn[i], a[i]+t);
		if (c >= i) mn[i-1] = max(mn[i-1], a[i]+t);
		c = max(x[i], c);
		
		if (x[i]+1<=n) mx[x[i]] = min(mx[x[i]], a[x[i]+1]+t-1);
	}

	for (int i = n-1; i; i--)
		mx[i] = min(mx[i], mx[i+1]-1);

	for (int i = 1; i <= n; i++)
		if (mn[i] > mx[i]) {
			cout << "No" << endl;
			return 0;
		}

	cout << "Yes" << endl;
	for (int i = 1; i <= n; i++)
		cout << mx[i] << " ";
	cout << endl;

	return 0;
}