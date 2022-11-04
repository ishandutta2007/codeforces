#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, k, p, x;
vi a[2];
vvi res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k >> p;
	p = k - p;
	res.resize(k);

	for (int i = 0; i < n; i++) {
		cin >> x;
		a[x%2].push_back(x);
	}

	if (a[1].size() < p || (a[1].size() - p) % 2 || p + (a[1].size() - p) / 2 + a[0].size() < k) {
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;

	int i = 0;
	for (int j = 0; j < a[1].size();) {
		if (i < p) {
			res[i].push_back(a[1][j++]);
		} else {
			res[i].push_back(a[1][j++]);
			res[i].push_back(a[1][j++]);
		}
		i = min(i+1, k-1);
	}

	for (int x : a[0]) {
		res[i].push_back(x);
		i = min(i+1, k-1);
	}

	for (vi &v : res) {
		cout << v.size();
		for (int x : v)
			cout << " " << x;
		cout << endl;
	}

	return 0;
}