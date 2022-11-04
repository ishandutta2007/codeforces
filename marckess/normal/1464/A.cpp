#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, m, x[MX], y[MX], p[MX], cn[MX], sz[MX];

int parent (int a) {
	return p[a] == a ? a : p[a] = parent(p[a]);
}

void reset () {
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		cn[i] = 0;
		sz[i] = 1;
	}
}

void join (int a, int b) {
	a = parent(a), b = parent(b);
	cn[a]++;
	
	if (a == b) return;
	
	p[b] = a;
	cn[a] += cn[b];
	sz[a] += sz[b];
}

void solve () {
	cin >> n >> m;
	reset();
	forn (i, m) {
		cin >> x[i] >> y[i];
		if (x[i] != y[i])
			join(x[i], y[i]);
	}
	
	int res = 0;
	for (int i = 1; i <= n; i++)
		if (p[i] == i) {
			res += cn[i];
			res += sz[i] == cn[i];
		}
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}