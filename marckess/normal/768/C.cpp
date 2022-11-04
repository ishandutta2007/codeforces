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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = (1<<10)+3;
int n, k, x, a[2][MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k >> x;
	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;
		a[0][b]++;
	}

	int i = 0, j = 1;
	while (k--) {
		int c = 1;
		memset(a[j], 0, sizeof(a[j]));

		for (int k = 0; k < MX; k++) {
			int d = (a[i][k] + c) >> 1;
			a[j][k^x] += d;
			a[j][k] += a[i][k] - d;
			c = (a[i][k] + c) & 1;
		}

		swap(i, j);
	}

	int mx = 0, mn = MX;
	for (int k = 0; k < MX; k++)
		if (a[i][k]) {
			mx = max(mx, k);
			mn = min(mn, k);
		}

	cout << mx << " " << mn << endl;

	return 0;
}