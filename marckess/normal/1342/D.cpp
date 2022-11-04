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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, k, a[MX], acu[MX], c[MX], tot;
vector<vi> res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	forn (i, n) {
		cin >> a[i];
		acu[a[i]]++;
	}

	for (int i = 1; i <= k; i++)
		cin >> c[i];

	sort(a, a + n, greater<int>());

	for (int i = k; i > 0; i--) {
		acu[i] += acu[i + 1];
		tot = max(tot, (acu[i] + c[i] - 1) / c[i]);
	}

	forn (i, n) {
		if (res.size() <= i % tot)
			res.resize(i % tot + 1);
		res[i % tot].pb(a[i]);
	}

	cout << res.size() << endl;
	for (auto &r : res) {
		cout << r.size();
		for (auto x : r)
			cout << " " << x;
		cout << endl;
	}

	return 0;
}