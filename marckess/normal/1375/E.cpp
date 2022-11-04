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

const int MX = 1005;
int n, a[MX];
vi c;
vii res;
map<int, int> pos;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	
	forn (i, n) {
		cin >> a[i];
		c.pb(a[i]);
	}

	sort(all(c));
	forn (i, n)
		if (!pos.count(c[i]))
			pos[c[i]] = i;

	forn (i, n)
		a[i] = pos[a[i]]++;

	forn (i, n) {
		vii v;

		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				v.emplace_back(a[j], j);

		sort(all(v), greater<ii>());

		for (ii x : v) {
			res.emplace_back(i, x.se);
			swap(a[i], a[x.se]);
		}
	}

	cout << res.size() << endl;
	for (ii r : res)
		cout << r.fi + 1 << " " << r.se + 1 << endl;

	return 0;
}