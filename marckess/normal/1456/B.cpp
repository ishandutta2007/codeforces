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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, a[MX];

int msb (int n) {
	for (int i = 30; i >= 0; i--)
		if (n & (1 << i))
			return i;
}

void solve () {
	cin >> n;
	forn (i, n) cin >> a[i];
	
	int cn = 0, ant = -1;
	forn (i, n) {
		int b = msb(a[i]);
		if (ant == b) {
			cn++;
		} else {
			ant = b;
			cn = 1;
		}
		
		if (cn == 3) {
			cout << 1 << endl;
			return;
		}
	}
	
	int res = 1e9;
	
	forn (i, n)
		for (int j = i + 1; j < n; j++)
			for (int k = i; k < j; k++) {
				int x = 0;
				int y = 0;
				
				for (int l = i; l <= j; l++) {
					if (l <= k) x ^= a[l];
					else y ^= a[l];
				}
				
				if (x > y)
					res = min(res, j - i - 1);
			}
	
	if (res == 1e9) cout << -1 << endl;
	else cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	
	return 0;
}