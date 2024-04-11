#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, q, x[MX], y[MX], k[MX], res[MX], a[MX];
vi pos[MX];

void main_() {
	cin >> n >> q;
	forn (i, q) {
		cin >> x[i] >> y[i] >> k[i];
		
		x[i]--;
		y[i]--;
		
		if (x[i] != y[i]) {
			pos[x[i]].pb(i);
			pos[y[i]].pb(i);
		}
	}
	
	forn (b, 30) {
		memset(a, -1, sizeof(a));
		
		forn (i, q) {
			if (~k[i] & (1 << b))
				a[x[i]] = a[y[i]] = 0;
			
			if (x[i] == y[i])
				a[x[i]] = bool(k[i] & (1 << b));
		}
		
		forn (i, n) {
			if (a[i] != -1) continue;
			int f = 0;
			
			for (int j : pos[i]) {
				if (i == x[j] && a[y[j]] == 0 && (k[j] & (1 << b)))
					f = 1;
				
				if (i == y[j] && a[x[j]] == 0 && (k[j] & (1 << b)))
					f = 1;
			}
			
			a[i] = f;
		}
		
		forn (i, n)
			res[i] |= a[i] << b;
	}
	
	forn (i, n)
		cout << res[i] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}