#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

const int MX = 50005, SQ = 150;
int n, q, a[MX], b[MX], blo[MX], lz[MX / SQ + 5], in[MX / SQ + 5][MX], bs[MX];
ll f[MX], res[MX / SQ + 5], mn[MX / SQ + 5][MX];
vi divi[MX], pd[MX];

inline int min (int a, int b) {
	return a < b ? a : b;
}

inline ll min (ll a, ll b) {
	return a < b ? a : b;
}

void push (int blo) {
	res[blo] = 1e18;
	for (int i = max(1, SQ * blo); i <= min(n, SQ * (blo + 1) - 1); i++) {
		a[i] = lz[blo];
		int g = __gcd(a[i], b[i]);
		f[i] = 1ll * a[i] * b[i] / g / g;
		res[blo] = min(res[blo], f[i]);
	}
	lz[blo] = 0;
}

void find_res (int blo) {
	res[blo] = 1e18;
	for (int i = max(1, SQ * blo); i <= min(n, SQ * (blo + 1) - 1); i++) {
		res[blo] = min(res[blo], f[i]);
	}
}

void main_() {
	cin >> n >> q;
	forr (i, 1, n) cin >> a[i];
	forr (i, 1, n) {
		cin >> b[i];
		blo[i] = i / SQ;
		
		for (int d : divi[b[i]])
			in[blo[i]][d] = min(in[blo[i]][d], b[i]);
		
		f[i] = 1ll * a[i] * b[i] / __gcd(a[i], b[i]) / __gcd(a[i], b[i]);
		res[blo[i]] = min(res[blo[i]], f[i]);
	}
	
	for (int i = 1; i <= blo[n]; i++) {
		for (int x = 1; x < MX; x++) {
			mn[i][x] = 1e18;
			
			if (in[i][x] != 1e9)
				mn[i][x] = 1ll * x * in[i][x] / x / x;;
			
			for (int p : pd[x]) {
				int ot = x / p;
				if (mn[i][ot] == 1e18) continue;
				mn[i][x] = min(mn[i][x], mn[i][ot] * p);
			}
		}
	}
	
	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			
			if (lz[blo[l]]) push(blo[l]);
			for (int i = l; i <= r && blo[i] == blo[l]; i++) {
				a[i] = x;
				int g = __gcd(a[i], b[i]);
				f[i] = 1ll * a[i] * b[i] / g / g;		
			}
			find_res(blo[l]);
			
			if (blo[l] != blo[r]) {
				if (lz[blo[r]]) push(blo[r]);
				for (int i = r; i >= l && blo[i] == blo[r]; i--) {
					a[i] = x;
					int g = __gcd(a[i], b[i]);
					f[i] = 1ll * a[i] * b[i] / g / g;
				}
				find_res(blo[r]);
			}
			
			for (int i = blo[l] + 1; i < blo[r]; i++) {
				lz[i] = x;
				res[i] = mn[i][x];
			}
		} else {
			int l, r;
			cin >> l >> r;
			ll bt = 1e18;
			
			if (lz[blo[l]]) push(blo[l]);
			for (int i = l; i <= r && blo[i] == blo[l]; i++) {
				bt = min(bt, f[i]);
			}
			
			if (blo[l] != blo[r]) {
				if (lz[blo[r]]) push(blo[r]);
				for (int i = r; i >= l && blo[i] == blo[r]; i--) {
					bt = min(bt, f[i]);
				}
			}
			
			for (int i = blo[l] + 1; i < blo[r]; i++) {
				bt = min(bt, res[i]);
			}
			
			cout << bt << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	for (int i = 2; i < MX; i++) {
		if (bs[i]) continue;
		for (int j = i; j < MX; j += i) {
			pd[j].pb(i);
			bs[j] = 1;
		}
	}
	
	forr (i, 1, MX - 1)
		for (int j = i; j < MX; j += i)
			divi[j].pb(i);
	
	forn (i, MX / SQ + 5) {
		res[i] = 1e18;
		forn (j, MX)
			in[i][j] = 1e9;
	}
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}