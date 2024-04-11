#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
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

int n, ini, fin;
string s;

void solve () {
	cin >> n >> s;
	
	ini = 0;
	while (ini < n && s[ini] == '0') ini++;

	fin = 0;
	while (fin < n && s[n - fin - 1] == '1') fin++;

	int f = ini + fin < n;
	while (ini-- ) cout << '0';
	if (f) cout << '0';
	while (fin--) cout << '1';
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