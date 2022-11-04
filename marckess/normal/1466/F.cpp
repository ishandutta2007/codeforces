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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 500005, mod = 1000000007;
int n, m, p[MX], ex[MX], ot[MX];
vi res;

int parent (int a) {
	return a == p[a] || a == -1 ? a : p[a] = parent(p[a]);
}

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	iota(p, p + MX, 0);
	
	cin >> n >> m;
	
	forn (i, n) {
		int k;
		cin >> k;
		
		if (k == 1) {
			int x;
			cin >> x;
			
			if (ex[x])
				x = parent(ot[x]);
				
			if (x != -1) {
				ex[x] = 1;
				ot[x] = -1;
				p[x] = -1;
				res.pb(i);
			}
		} else {
			int x, y;
			cin >> x >> y;
			
			if (ex[x])
				x = parent(ot[x]);
			
			if (x == y) continue;
			
			if (ex[y])
				y = parent(ot[y]);
			
			if (x == y) continue;
			
			if (x != -1) {
				ex[x] = 1;
				ot[x] = y;
				p[x] = y;
				res.pb(i);
			} else {
				ex[y] = 1;
				ot[y] = -1;
				p[y] = -1;
				res.pb(i);
			}
		}
	}
	
	cout << pot(2, res.size()) << " " << res.size() << endl;
	for (int x : res)
		cout << x + 1 << " ";
	cout << endl;
	
	return 0;
}