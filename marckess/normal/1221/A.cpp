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

void solve () {
	int n, a[105];

	cin >> n;
	forn (i, n)
		cin >> a[i];

	int i = 0;
	while (i < n && a[i] < 2048) {
		sort(a+i, a+n);
		if (a[i] == a[i+1]) {
			a[i+1] += a[i];
		}
		i++;
	}

	for (int i = 0; i < n; i++) {
		if (a[i] == 2048) {
			cout << "YES" << endl;
			return;
		}
	}

	cout << "NO" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int q;
	cin >> q;
	while (q--)
		solve();

	return 0;
}