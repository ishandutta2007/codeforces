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
int n, a[MX], b[MX], dp[MX][2 * MX * MX];

void maxi (int &a, int b) {
	a = max(a, b);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);
	
	cin >> n;
	forn (i, n) {
		cin >> a[i] >> b[i];
		a[i] *= 2;
		b[i] *= 2;
	}
	
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	
	forn (i, n)
		for (int j = i; j >= 0; j--)
			forn (k, 200 * i + 1)
				if (dp[j][k] != -1) {
					maxi(dp[j + 1][k + a[i]], dp[j][k] + b[i]);
					dp[j][k] += b[i] / 2;
				}
	
	for (int j = 1; j <= n; j++) {
		int res = 0;
		forn (k, 200 * j + 1)
			res = max(res, min(dp[j][k], k));
		cout << res * .5 << " ";
	}
	cout << endl;
	
	return 0;
}