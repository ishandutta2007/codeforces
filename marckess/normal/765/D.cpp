#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int n;
vi f, g, h, a;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	f.resize(n);
	for (int i = 0; i < n; i++) cin >> f[i];

	a.resize(n+1);
	
	h = f;
	sort(ALL(h));
	h.erase(unique(ALL(h)), h.end());

	g.resize(n);
	for (int i = 0; i < n; i++)
		g[i] = upper_bound(ALL(h), f[i]) - h.begin();

	for (int i = 0; i < h.size(); i++)
		if (g[h[i]-1] != i+1) {
			cout << -1 << endl;
			return 0;
		}

	for (int i = 0; i < n; i++)
		if (h[g[i]-1] != f[i]) {
			cout << -1 << endl;
			return 0;
		}

	cout << h.size() << endl;
	for (int x : g) cout << x << " ";
	cout << endl;
	for (int x : h) cout << x << " ";
	cout << endl;

	return 0;
}