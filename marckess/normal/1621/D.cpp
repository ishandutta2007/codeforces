// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

void main_() {
	int n;
	cin >> n;
	
	vvi a(2 * n, vi(2 * n));
	
	for (vi &x : a)
		for (int &y : x)
			cin >> y;
	
	ll res = 0;
	forr (i, n, 2 * n - 1)
	forr (j, n, 2 * n - 1)
		res += a[i][j];
	
	ll p = 2e9;
	p = min({
		a[0][n],
		a[0][2 * n - 1],
		a[n - 1][n],
		a[n - 1][2 * n - 1],
		
		a[n][0],
		a[n][n - 1],
		a[2 * n - 1][0],
		a[2 * n - 1][n - 1]
	});
	
	cout << res + p << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}