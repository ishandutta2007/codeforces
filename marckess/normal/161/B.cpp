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

const int MX = 1005;
int n, k, res[MX];
ld sum;
vii a, b;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(1);
	
	cin >> n >> k;
	forn (i, n) {
		int t, c;
		cin >> c >> t;
		if (t == 1) a.emplace_back(c, i);
		else b.emplace_back(c, i);
		sum += c;
	}

	sort(all(a), greater<ii>());
	sort(all(b), greater<ii>());

	int j = 0;

	if (a.size()) {
		if (a.size() < k || !b.size()) sum -= a.back().fi / 2.0l;
		else sum -= min(a.back().fi, b.back().fi) / 2.0l;
		j++;
	}

	for (int i = 0; i < (int)a.size() - 1 && j < k; i++) {
		res[a[i].se] = j++;
		sum -= a[i].fi / 2.0l;
	}

	if (a.size() < k) {
		for (int i = 0; i < b.size(); i++) {
			if (j < k) res[b[i].se] = j++;
			else res[b[i].se] = k - 1;
		}
	}

	cout << sum << endl;
	forn (i, k) {
		vi v;
		forn (j, n)
			if (res[j] == i)
				v.pb(j);
		cout << v.size();
		for (int x : v)
			cout << " " << x + 1;
		cout << endl;
	}

	return 0;
}