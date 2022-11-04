#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005, LG = 18;
int n, q, a[MX], p[LG][MX], bs[MX], ant[MX];
vi adj[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (ll i = 2; i < MX; i++)
		if (!bs[i]) {
			bs[i] = i;
			for (ll j = i * i; j < MX; j += i)
				bs[j] = i;
		}
	
	cin >> n >> q;
	forn (i, n)
		cin >> a[i];
	
	memset(ant, -1, sizeof(ant));
	p[0][n] = n;
	
	for (int i = n - 1; i >= 0; i--) {
		int nex = p[0][i + 1];
		
		while (a[i] > 1) {
			int x = bs[a[i]];
			while (a[i] % x == 0)
			 	a[i] /= x;
			
			if (ant[x] != -1)
				nex = min(nex, ant[x]);
			ant[x] = i;
		}
		
		p[0][i] = nex;
	}
	
	for (int j = 1; j < LG; j++)
		forn (i, n + 1)
			p[j][i] = p[j - 1][p[j - 1][i]];
	
	while (q--) {
		int l, r, res = 1;
		cin >> l >> r;
		l--, r--;
		
		for (int j = LG - 1; j >= 0; j--)
			if (p[j][l] <= r) {
				res += 1 << j;
				l = p[j][l];
			}
		
		cout << res << endl;
	}
	
	return 0;
}