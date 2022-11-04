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
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int n, a[MX], b[MX];

void solve () {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	int k, ini = -1, fin = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] < b[i]) {
			if (ini == -1)
				ini = i;
			fin = i;
			k = b[i] - a[i];
		}
	}

	if (ini != -1) {
		for (int i = ini; i <= fin; i++)
			a[i] += k;
	}

	for (int i = 0; i < n; i++)
		if (a[i] != b[i]) {
			cout << "NO" << endl;
			return;
		}
	cout << "YES" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}