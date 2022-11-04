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

int c, m, x;
bool esPos (int mit) {
	int s = c - mit;
	s += m - mit;
	s += x;
	return s >= mit;
}

void solve () {
	cin >> c >> m >> x;

	int i = 0, j = min(c, m), rep = 30;
	while (rep--) {
		int m = (i + j + 1) / 2;
		if (esPos(m)) i = m;
		else j = m;
	}
	cout << i << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int q;
	cin >> q;
	while (q--)
		solve();

	return 0;
}