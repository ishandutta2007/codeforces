// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
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

struct BIT {
	ll b1[MX], b2[MX];

	BIT () {
		memset(b1, 0, sizeof(b1));
		memset(b2, 0, sizeof(b2));
	}

	void update (ll ft[], int i, ll k) {
		while (i < MX) {
			ft[i] += k;
			i += i & -i;
		}
	}

	void update (int a, int b, ll k) {
		update(b1, a, k);
		update(b1, b + 1, -k);
		update(b2, a, k * (a - 1));
		update(b2, b + 1, -k * b);
	}

	ll query (ll ft[], int i) {
		ll sum = 0;
		while (i) {
			sum += ft[i];
			i -= i & -i;
		}
		return sum;
	}

	ll query (int i) {
		return query(b1, i) * i - query(b2, i);
	}
}lin, con;

int n, q, p[MX], ini[MX], fin[MX], ant[MX], inv[MX], o[MX];
ll res[5 * MX];
set<int> st;
vii pos[MX], in[MX];
vvi back[MX];

void main_() {
	cin >> n >> q;
	forr (i, 1, n) {
		cin >> p[i];
		inv[p[i]] = i;
	}
	
	st.insert(0);
	st.insert(n + 1);
	
	for (int i = n; i >= 1; i--) {
		auto it = st.lower_bound(inv[i]);
		
		fin[i] = *it - 1;
		ant[i] = *it;
		it--;
		ini[i] = *it + 1;
		
		st.insert(inv[i]);
	}
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i && i * j <= n; j++) {
			int l = min({inv[i], inv[j], inv[i * j]});
			int r = max({inv[i], inv[j], inv[i * j]});
			
			if (ini[i * j] <= l && r <= fin[i * j]) {
				in[l].pb({r, i * j});
			}
		}
	
	forn (i, q) {
		int l, r;
		cin >> l >> r;
		pos[l].pb({r, i});
	}
	
	for (int i = n; i >= 1; i--) {
		for (ii &p : in[i])
			if (p.fi < ant[p.se]) {
				lin.update(p.fi, ant[p.se] - 1, 1);
				con.update(p.fi, ant[p.se] - 1, -(n - i));
				back[ini[p.se]].pb({p.fi, ant[p.se] - 1, i});
				
				ant[p.se] = p.fi;
			}
		
		for (ii &p : pos[i]) {
			res[p.se] = con.query(p.fi);
			res[p.se] += (n - i + 1) * lin.query(p.fi);
		}
		
		for (vi &v : back[i]) {
			int l = v[0], r = v[1], j = v[2];
			lin.update(l, r, -1);
			con.update(l, r, (n - j) + (j - i + 1));
		}
	}
	
	forn (i, q)
		cout << res[i] << endl; 
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}