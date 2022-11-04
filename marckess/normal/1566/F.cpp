
// Problem : F. Points Movement
// Contest : Codeforces - Codeforces Global Round 16
// URL : https://codeforces.com/contest/1566/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
int n, m, a[MX], nex[MX], pre[MX];
vii b, c;
ll mem[MX][4];

ll dp (int i, int f) {
	if (i == c.size()) return 0;
	
	ll &res = mem[i][f];
	if (res != -1) return res;
	res = 1e18;
	
	if (0 < f && f < 3 && pre[i - 1] != pre[i])
		f = 0;
	if (f == 3 && nex[i - 1] != pre[i])
		f = 0;
	
	// f = 0 -> pre[i] disponible
	// f = 1 -> pre[i] ocupado por el seg anterior
	// f = 2 -> pre[i] ocupado por el seg anterior y debe ser doble
	// f = 3 -> pre[i] debe ser doble
	
	if (f == 0) {
		if (pre[i] != -1)
			res = min(res, dp(i + 1, 1) + abs(a[pre[i]] - c[i].fi));
	}
	if (f == 1) {
		res = min(res, dp(i + 1, 1) + abs(c[i - 1].fi - c[i].fi));
	}
	if (f == 2) {
		res = min(res, dp(i + 1, 2) + 2ll * abs(c[i - 1].fi - c[i].fi));
	}
	if (f == 3) {
		res = min(res, dp(i + 1, 2) + 2ll * abs(a[pre[i]] - c[i].fi));
	}
	
	if (nex[i] != n) {
		int k = upper_bound(nex, nex + c.size(), nex[i]) - nex;
		res = min(res, dp(k, 3) + abs(a[nex[i]] - c[i].se));
		res = min(res, dp(k, 0) + 2ll * abs(a[nex[i]] - c[i].se));
	}
	
	return res;
}

void main_() {
	cin >> n >> m;
	forn (i, n)
		cin >> a[i];
	sort(a, a + n);
	
	b.clear(), c.clear();
	forn (i, m) {
		int x, y;
		cin >> x >> y;
		b.emplace_back(x, y);
	}
	
	sort(all(b), [&] (const ii& i, const ii& j) {
		if (i.se ^ j.se) return i.se < j.se;
		return i.fi > j.fi;
	});
	
	int j = 0, mx = -2e9;
	for (const ii& x : b) {
		while (j + 1 < n && a[j + 1] <= x.se)
			j++;
		
		if (a[j] < x.fi || x.se < a[j])
			if (mx < x.fi)
				c.pb(x);
		mx = max(mx, x.fi);
	}
	
	// DP
	forn (i, c.size()) {
		int j = upper_bound(a, a + n, c[i].fi) - a;
		pre[i] = j - 1;
		nex[i] = j;
	}
	
	forn (i, c.size())
		memset(mem[i], -1, sizeof(mem[i]));
	
	cout << dp(0, 0) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}