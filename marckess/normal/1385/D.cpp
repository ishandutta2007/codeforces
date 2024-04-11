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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, acu[256][MX];
char a[MX];

int obtRes (int i, int j, char c) {
	if (i == j) return a[i] != c;

	int m = (i + j) / 2;
	return min(
		(m - i + 1) - (acu[c][m] - acu[c][i - 1]) + obtRes(m + 1, j, c + 1),
		(j - m) - (acu[c][j] - acu[c][m]) + obtRes(i, m, c + 1)
	);
}

void solve () {
	cin >> n;
	forn (i, n) cin >> a[i + 1];

	for (int i = 1; i <= n; i++) {
		for (int j = 'a'; j <= 'z'; j++)
			acu[j][i] = acu[j][i - 1];
		acu[a[i]][i]++;
	}

	cout << obtRes(1, n, 'a') << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}