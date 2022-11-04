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
int n, w, q, acu[MX];
ii res[11][11];
string s;

int query (int a, int b) {
	if (a) return MOD(acu[b] - acu[a - 1], 9);
	return acu[b];
}

void main_() {
	cin >> s >> w >> q;
	n = s.size();
	
	forn (i, 9)
	forn (j, 9)
		res[i][j] = {MX, MX};
	
	forn (i, n) {
		acu[i] = int(s[i] - '0') % 9;
		if (i) (acu[i] += acu[i - 1]) %= 9;
	}
	
	map<int, vi> mp;
	forn (i, n - w + 1)
		mp[query(i, i + w - 1)].pb(i);
	
	forn (l1, n - w + 1) {
		ll x = query(l1, l1 + w - 1);
		
		forn (i, 9)
		forn (j, 9) {
			// x * i + y = j
			ll y = MOD(j - x * i, 9);
			
			int l2 = -1;
			for (int k : mp[y])
				if (k != l1) {
					l2 = k;
					break;
				}
			
			if (l2 != -1)
				res[i][j] = min(res[i][j], ii(l1, l2));
		}
	}
	
	while (q--) {
		int l, r, j;
		cin >> l >> r >> j;
		l--, r--;
		
		ll i = MOD(query(l, r), 9);
		
		if (res[i][j].fi == MX) cout << -1 << " " << -1 << endl;
		else cout << res[i][j].fi + 1 << " " << res[i][j].se + 1 << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}