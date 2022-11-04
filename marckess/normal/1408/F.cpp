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

int n;
vii res;

void go (int i, int j) {
	if (i == j) return;
	int m = (j - i + 1) / 2;

	go(i, i + m - 1);
	go(i + m, j);

	for (int k = i; k < i + m; k++)
		res.pb(ii(k, k + m));
}

void solve () {
	cin >> n;

	for (int i = 20; i >= 0; i--)
		if ((1 << i) <= n) {
			go(1, 1 << i);
			go(n - (1 << i) + 1, n);
			break;
		}

	cout << res.size() << endl;
	for (ii &r : res)
		cout << r.fi << " " << r.se << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t = 1;
	//cin >> t;
	while (t--)	
		solve();

	return 0;
}