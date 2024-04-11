#include <bits/stdc++.h>

//#define endl '\n'
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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 105;
int n, k, a[MX];

void solve () {
	cin >> n >> k;
	forn (i, n)
		cin >> a[i];
	
	while (k--) {
		int ind = 0;
		while (ind + 1 < n && !a[ind])
			ind++;
		if (ind + 1 == n)
			break;
		a[ind]--, a[n - 1]++;
	}
	
	forn (i, n)
		cout << a[i] << " ";
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