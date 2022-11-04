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

const int MX = 305;
int n;
ll c[MX][6], res;
ii p[MX];
bitset<MX> bs[MX][MX];

ii operator - (ii a, ii b) { return {a.fi - b.fi, a.se - b.se}; }
ll operator ^ (ii a, ii b) { return a.fi * b.se - a.se * b.fi; }

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i].fi >> p[i].se;

	c[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= min(5, i); j++)
			c[i][j] = c[i-1][j] + c[i-1][j-1];
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (((p[j] - p[i]) ^ (p[k] - p[i])) > 0)
					bs[i][j][k] = 1;

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++) {
    int cn = ( bs[i][j][k] ? bs[i][j] & bs[j][k] & bs[k][i] : bs[j][i] & bs[k][j] & bs[i][k]).count();
    res += cn * (n - 3 - cn);
}

	cout << c[n][5] - res / 2 << endl;

	return 0;
}