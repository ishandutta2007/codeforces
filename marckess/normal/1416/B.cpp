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

const int MX = 300005;
int n;
ll a[MX], s;
vvi res;

void add (int i, int j, int x) {
	a[i] -= x * i;
	a[j] += x * i;
	res.push_back({i, j, x});
}

void solve () {
	cin >> n;

	s = 0;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s += a[i];
	}

	if (s % n) {
		cout << -1 << endl;
		return;
	}

	res.clear();

	for (int i = 2; i <= n; i++) {
		int ret = a[i] % i;
		if (ret) ret = i - ret;
		add(1, i, ret);

		add(i, 1, a[i] / i);
	}

	for (int i = 2; i <= n; i++)
		add(1, i, s / n);

	cout << res.size() << endl;
	for (vi &r : res) {
		for (int x : r)
			cout << x << " ";
		cout << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)	
		solve();

	return 0;
}