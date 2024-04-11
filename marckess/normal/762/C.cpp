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

const int MX = 100005;
string a, b;
int izq[MX], der[MX], res, n, m, x, y;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> a >> b;

	n = a.size();
	m = b.size();

	for (int i = 0, j = 0; i < n; i++) {
		if (j < m && a[i] == b[j])
			j++;
		izq[i] = j;
	}

	for (int i = n - 1, j = m - 1; i >= 0; i--) {
		if (j >= 0 && a[i] == b[j])
			j--;
		der[i] = j;
	}

	res = izq[n - 1];
	x = izq[n - 1], y = m;

	if (m - der[0] - 1 > res) {
		res = m - der[0] - 1;
		x = 0, y = der[0];
	}

	for (int i = 0; i + 1 < n; i++) {
		int p = izq[i] + (m - der[i + 1] - 1);
		if (p > res) {
			res = p;
			x = izq[i];
			y = der[i + 1];
		}
	}

	if (res >= m) cout << b << endl;
	else if (!res) cout << "-" << endl;
	else {
		forn (i, x) cout << b[i];
		for (int i = y + 1; i < m; i++) cout << b[i];
		cout << endl;
	}

	return 0;
}