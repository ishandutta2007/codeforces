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

const int MX = 500005;
int n, a[MX], nex[MX], cn;
bool f;

void go (int i, int j) {
	if (i > j) return;

	for (int k = i; k <= j; k = nex[k]) {
		if (nex[k] == -1) nex[k] = j + 1;
		if (nex[k] > j + 1) {
			f = 0;
			return;
		}
		go(k + 1, nex[k] - 1);
		if (!f) return;
	}

	for (int k = i; k <= j; k = nex[k])
		a[k] = cn++;
}

void solve () {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> nex[i];

	f = cn = 1;
	go(1, n);
	
	if (f) {
		for (int i = 1; i <= n; i++)
			cout << a[i] << " ";
		cout << endl;
	} else {
		cout << -1 << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}