#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1005;
int n, x, a[MX], par, imp;

void solve () {
	cin >> n >> x;
	par = imp = 0;

	forn (i, n) {
		cin >> a[i];
		if (a[i] % 2) imp++;
		else par++;
	}

	for (int i = 0; i <= x; i++)
		if (i % 2 && i <= imp && x - i <= par) {
			cout << "Yes" << endl;
			return;
		}

	cout << "No" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}