#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, k, res[105];

void solve () {
	cin >> n >> k;
	
	if ((n - 1) / 2 < k) {
		cout << -1 << endl;
		return;
	}
	
	memset(res, 0, sizeof(res));
	int x = n;
	for (int i = 1; k; i += 2, k--)
		res[i] = x--;
	
	forn (i, n)
		if (!res[i])
			res[i] = x--;
	
	forn (i, n)
		cout << res[i] << " ";
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}