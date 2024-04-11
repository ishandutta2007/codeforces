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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int n, s, mn = 1e9;
bitset<25*50000+5> dp[52][27];
vi a, ra, rb;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		int in;
		cin >> in;
		a.pb(in);
		s += in;
	}

	a.pb(-1);
	sort(all(a));

	s -= a[1] + a[2];
	ra.pb(a[1]);
	rb.pb(a[2]);

	n--;
	a.erase(a.begin()+1, a.begin()+3);

	dp[0][0][0] = 1;

	for (int i = 1; i <= 2 * n; i++) {
		dp[i][0] = dp[i-1][0];
		for (int j = 1; j <= min(i, n); j++)
			dp[i][j] = dp[i-1][j] | (dp[i-1][j-1] << a[i]);
	}

	for (int i = 0; i <= s; i++)
		if (dp[2*n][n][i])
			mn = min(mn, max(i, s - i));

	for (int i = 2 * n, j = n; i; i--) {
		int ant = mn - a[i];
		if (j && ant >= 0 && dp[i-1][j-1][ant]) {
			mn = ant;
			j--;
			ra.pb(a[i]);
		} else {
			rb.pb(a[i]);
		}
	}

	sort(all(ra));
	sort(all(rb));
	reverse(all(rb));

	for (int x : ra)
		cout << x << " ";
	cout << endl;

	for (int x : rb)
		cout << x << " ";
	cout << endl;

	return 0;
}