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

const int MX = 500005;
int n, x[2 * MX], y[2 * MX];
string s;

void solve () {
	cin >> s;
	n = s.size();
	
	for (int i = MX - n; i <= MX + n; i++)
		x[i] = y[i] = 0;
	
	int sum = MX;
	for (char c : s) {
		if (c == '0') {
			y[sum]++;
			sum--;
		} else {
			x[sum]++;
			sum++;
		}
	}
	
	int u = MX;
	forn (i, n) {
		if (y[u] && (!x[u] || x[u - 1])) {
			cout << 0;
			y[u]--;
			u--;
		} else {
			cout << 1;
			x[u]--;
			u++;
		}
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