#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 400005, inf = 2e9;
int n, s[MX], rn = 1, rm = 1;
map<int, int> mp;
vii a;
vvi res;

bool esPos (int m, int k) {
	int i = lower_bound(all(a), ii(m, -1)) - a.begin();
	ll x = i ? s[i-1] : 0;
	x += ((ll)a.size() - i) * m;
	return x >= 1ll * m * k;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		mp[a]++;
	}

	for (auto it = mp.begin(); it != mp.end(); it++)
		a.emplace_back(it->se, it->fi);
	sort(all(a));

	s[0] = a[0].fi;
	for (int i = 1; i < a.size(); i++)
		s[i] = s[i-1] + a[i].fi;

	for (int k = 1; k <= a.size(); k++) {
		int i = 1, j = k, rep = 20;
		if (!esPos(1, k)) continue;
		
		while (rep--) {
			int m = (i + j + 1) / 2;
			if (esPos(m, k)) i = m;
			else j = m;
		}
		
		if (i * k > rn * rm)
			rn = i, rm = k;
	}

	cout << rn * rm << endl;
	cout << rn << " " << rm << endl;

	reverse(all(a));
	res.resize(rn, vi(rm));

	for (int j = 0, p = 0, cn = 0; j < rm; j++)
		for (int i = 0; i < rn; i++) {
			res[i][(j+i)%rm] = a[p].se;
			cn++;
			if (cn >= rn || cn == a[p].fi)
				p++, cn = 0;
		}

	for (int i = 0; i < rn; i++) {
		for (int j = 0; j < rm; j++)
			cout << res[i][j] << " ";
		cout << endl;
	}

	return 0;
}