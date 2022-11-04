#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 400005;
int n, m, a[MX], cn[MX], pos[22][MX], ini[22], fin[22];
ll mem[(1<<20)+5], cost[22][22], d[22];

void domap() {
	vi c;
	forn(i, n) c.pb(a[i]);
	sort(all(c));
	c.erase(unique(all(c)), c.end());
	forn(i, n) a[i] = lower_bound(all(c), a[i]) - c.begin();
	m = c.size();
	forn(i, n) cn[a[i]]++;
}

int query (int c, int a, int b) {
	if (a > b) return 0;
	if (a) return pos[c][b] - pos[c][a-1];
	return pos[c][b];
}

ll dp (ll mk) {
	if (mk == (1 << m) - 1) return 0;
	ll &res = mem[mk];
	if (res != -1) return res;
	res = 1e18;

	for (int i = 0; i < m; i++) {
		if (mk & (1 << i)) continue;
		ll c = d[i];
		for (int j = 0; j < m; j++) {
			if (i == j) continue;
			if (mk & (1 << j)) c -= cost[i][j];
			else c += cn[i] * query(j, 0, ini[i]);
		}
		res = min(res, dp(mk | (1 << i)) + c);
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	forn(i, n) cin >> a[i];

	domap();

	forn(i, n) forn(j, m) {
		if (i) pos[j][i] = pos[j][i-1];
		if (a[i] == j) pos[j][i]++;
	}

	memset(ini, -1, sizeof(ini));
	forn(i, n) {
		if (ini[a[i]] == -1) {
			ini[a[i]] = i;
			fin[a[i]] = i + 1;
		} else {
			d[a[i]] += i - fin[a[i]];
			fin[a[i]]++;
		}
	}

	forn(i, n) forn(j, m) {
		cost[a[i]][j] += query(j, ini[a[i]], i);
	}

	memset(mem, -1, sizeof(mem));
	cout << dp(0) << endl;

	return 0;
}