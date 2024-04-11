#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005;
int n, m, u[MX], v[MX], w[MX], p[MX], q;
ll cn[MX], res[MX], acu;
vi pos[MX];

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

void join (int a, int b) {
	a = parent(a), b = parent(b);
	if (a == b) return;

	acu -= cn[a] * (cn[a] - 1) / 2;
	acu -= cn[b] * (cn[b] - 1) / 2;
	cn[a] += cn[b];
	acu += cn[a] * (cn[a] - 1) / 2;
	p[b] = a;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		cin >> u[i] >> v[i] >> w[i];
		pos[w[i]].pb(i);
	}

	forn(i, n+1) p[i] = i, cn[i] = 1;
	forn(i, MX) {
		for (int j : pos[i]) 
			join(u[j], v[j]);
		res[i] = acu;
	}

	while (m--) {
		cin >> q;
		cout << res[q] << " ";
	}
	cout << endl;

	return 0;
}