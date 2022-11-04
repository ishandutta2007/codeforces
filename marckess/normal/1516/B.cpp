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

const int MX = 2005;
int n, k, a[MX], acu[MX];

void solve () {
	cin >> n;
	forn (i, n) {
		cin >> a[i];
		acu[i] = a[i];
		if (i)
			acu[i] ^= acu[i - 1];
	}
	
	if (!acu[n - 1]) {
		cout << "YES" << endl;
		return;
	}
	
	int x = acu[n - 1];
	int ind = 0;
	
	while (acu[ind] != x)
		ind++;
	
	for (int i = ind + 1; i < n - 1; i++)
		if (!acu[i]) {
			cout << "YES" << endl;
			return;
		}
	
	cout << "NO" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}