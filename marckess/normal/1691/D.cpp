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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;

struct ST {
	ll mn[4 * MX], mx[4 * MX], lz[4 * MX];
	
	void init (int n) {
		forr (i, 1, 4 * n) {
			mn[i] = 0;
			mx[i] = 0;
			lz[i] = 0;
		}
	}
	
	void push (int i, int j, int pos) {
		if (i < j) {
			lz[pos * 2] += lz[pos];
			lz[pos * 2 + 1] += lz[pos];
		}
		
		mn[pos] += lz[pos];
		mx[pos] += lz[pos];
		lz[pos] = 0;
	}
	
	void update (int i, int j, int pos, int a, int b, ll k) {
		if (lz[pos]) push(i, j, pos);
		
		if (b < i || j < a) return;
		
		if (a <= i && j <= b) {
			lz[pos] = k;
			push(i, j, pos);
			return;
		}
		
		int m = (i + j) / 2;
		update(i, m, pos * 2, a, b, k);
		update(m + 1, j, pos * 2 + 1, a, b, k);
		
		mn[pos] = min(mn[pos * 2], mn[pos * 2 + 1]);
		mx[pos] = max(mx[pos * 2], mx[pos * 2 + 1]);
	}
	
	ii query (int i, int j, int pos, int a, int b) {
		if (lz[pos]) push(i, j, pos);
		
		if (b < i || j < a) return {1e18, -1e18};
		
		if (a <= i && j <= b) return {mn[pos], mx[pos]};
		
		int m = (i + j) / 2;
		ii x = query(i, m, pos * 2, a, b);
		ii y = query(m + 1, j, pos * 2 + 1, a, b);
		
		return {min(x.fi, y.fi), max(x.se, y.se)};
	}
}st;

int n, a[MX], sig[MX], ant[MX];
ll acu[MX];

void main_() {
	cin >> n;
	forr (i, 1, n) {
		cin >> a[i];
		acu[i] = acu[i - 1] + a[i];
	}
	
	map<int, int> mp;
	for (int i = n; i >= 1; i--) {
		auto it = mp.upper_bound(a[i]);
		if (it != mp.end())
			sig[i] = it->se;
		else
			sig[i] = n + 1;
		
		while (mp.size() && mp.begin()->fi <= a[i])
			mp.erase(mp.begin());
		mp[a[i]] = i;
	}
	
	mp.clear();
	forr (i, 1, n) {
		auto it = mp.upper_bound(a[i]);
		if (it != mp.end())
			ant[i] = it->se;
		else
			ant[i] = 0;
		
		while (mp.size() && mp.begin()->fi <= a[i])
			mp.erase(mp.begin());
		mp[a[i]] = i;
	}
	
	st.init(n + 1);
	forr (i, 1, n + 1)
		st.update(1, n + 1, 1, i, i, acu[i - 1]);
	
	forr (i, 1, n) {
		int l = ant[i];
		int r = sig[i];
	
		ll x = st.query(1, n + 1, 1, l + 1, i).fi;
		ll y = st.query(1, n + 1, 1, i + 1, r).se;
		
		if (y - x > a[i]) {
			cout << "NO" << endl;
			return;
		}
	}
	
	cout << "YES" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}