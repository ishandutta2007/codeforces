#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, u, v, d[MX], cn = 0, x = 0;
vi le;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		d[u]++;
		d[v]++;
	}

	for (int i = 1; i <= n; i++) {
		if (d[i] == 1) le.pb(i);
		else if (d[i] > 2) {
			cn++;
			x = i;
		}
	}

	if (cn > 1) {
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
	cout << le.size() / 2 + le.size() % 2 << endl;
	for (int i = 1; i < le.size(); i += 2)
		cout << le[i-1] << " " << le[i] << endl;
	if (le.size() % 2) {
		cout << x << " " << le.back() << endl;
	}
	
	return 0;
}