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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, a[MX], fp[MX];
ll ft[MX];
vi ls[MX];
vii t[MX];

void update (int i, ll k) {
	while (i < MX) {
		ft[i] += k;
		i += i & -i;
	}
}

ll query (int i) {
	ll s = 0;
	while (i) {
		s += ft[i];
		i -= i & -i;
	}
	return s;
}

ll query (int a, int b) {
	return query(b) - query(a - 1);
}

ll tr (ll n) {
	return n * (n + 1) / 2;
}

void main_() {
	cin >> n;
	forr (i, 1, n)
		cin >> a[i];
	
	int j = 1;
	ll acu = 0;
	
	forr (i, 1, n) {
		while (j <= n && a[j] >= j - i + 1) {
			fp[j] = i;
			j++;
		}
		
		ls[j].pb(i);
		acu += j - i;
		update(i, j - i);
	}
	
	map<int, int> mp;
	mp[-1e9] = n + 1;
	
	for (int j = n; j >= 1; j--) {
		t[j].pb({int(-1e9), 0});
		
		for (int i : ls[j]) {
			auto it = mp.lower_bound(-i + 1);
			it--;
			t[j].pb({j - i + 1, it->se - j});
		}
		
		sort(all(t[j]));
		for (int i = 1; i < (int)t[j].size(); i++)
			t[j][i].se += t[j][i - 1].se;
		
		while (mp.rbegin()->fi >= a[j] - j)
			mp.erase(mp.rbegin()->fi);
		mp[a[j] - j] = j;
	}
	
	int q; 
	cin >> q;
	
	while (q--) {
		int j, x;
		cin >> j >> x;
		
		if (x <= a[j]) {
			int l = j - x + 1;
			ll res = acu;
			
			if (fp[j] < l && l <= j) {
				res -= query(fp[j], l - 1);
				res += tr(j - fp[j]) - tr(j - l);
			}
			
			cout << res << endl;
		} else {
			auto it = upper_bound(all(t[j]), ii(x, MX));
			it--;
			cout << acu + it->se << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}