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
typedef vector<ii> vii;

int n, d, a[105];

void solve () {
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 2; i <= n; i++) {
		int t = min(a[i], d / (i - 1));
		a[1] += t;
		d -= t * (i - 1);
	}

	cout << a[1] << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);	

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}