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

ll n, k, res[105][105];

void solve () {
	cin >> n;
	forn (i, n) {
		int t = 0;
		forn (j, n) if (i != j) {
			if ((i + t) % 2)
				res[i][j] = 1;
			else
				res[i][j] = -1;
			t++;
		}
	}
	forn (i, n)
		for (int j = i + 1; j < n; j++) {
			if (n % 2 == 0 && i % 2 == 0 && j == i + 1)
				cout << 0 << " ";
			else
				cout << res[i][j] << " ";
		}
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