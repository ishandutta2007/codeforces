#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 1000005;
int n, k, a[MX], sig[30 * MX][2], cn[30 * MX], sz = 1, acu;
ll res;

void add (int x) {
	int u = 0;

	for (int i = 29; i >= 0; i--) {
		int f = bool(x & (1 << i));

		if (!sig[u][f])
			sig[u][f] = sz++;
		u = sig[u][f];

		cn[u]++;
	}
}

void find (int x) {
	int u = 0;

	for (int i = 29; i >= 0; i--) {
		int f = bool(x & (1 << i));

		if (k & (1 << i)) {
			if (!sig[u][1 - f])
				return;
			
			u = sig[u][1 - f];
		} else {
			if (sig[u][1 - f])
				res += cn[sig[u][1 - f]];
			
			if (!sig[u][f])
				return;
			
			u = sig[u][f];
		}
	}

	res += cn[u];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	forn (i, n) cin >> a[i];

	add(0);

	forn (i, n) {
		acu ^= a[i];
		find(acu);
		add(acu);
	}

	cout << res << endl;

	return 0;
}