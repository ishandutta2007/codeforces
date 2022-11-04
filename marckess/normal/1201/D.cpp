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
typedef vector<ll> vl;
typedef vector<ii> vii;
 
const int MX = 200005;
int n, m, k, q;
ll mem[MX][4];
int r[MX], c[MX], b[MX];
vi pos[MX];

int izq (int k) {
	int i = upper_bound(b, b + q, k) - b;
	if (i) i--;
	return b[i];
}

int der (int k) {
	int i = lower_bound(b, b + q, k) - b;
	if (i == q) i--;
	return b[i];
}

ll dp (int i, int j, int k) {
	ll &res = mem[i][j];
	
	if (res != -1) return res;
	if (pos[i].empty()) return res = dp(i + 1, j, der(k)) + 1 + abs(k - der(k));

	if (i == n) {
		res = 1ll * abs(k - pos[i].back()) + abs(pos[i].back() - pos[i][0]);

		res = min(
			res,
			1ll * abs(k - pos[i][0]) + abs(pos[i][0] - pos[i].back())
		);

		return res;;
	}

	int to = izq(pos[i][0]);
	res = dp(i + 1, 0, to) + abs(k - pos[i].back()) + abs(pos[i].back() - pos[i][0]) + abs(pos[i][0] - to) + 1;

	to = der(pos[i][0]);
	res = min(
		res,
		dp(i + 1, 1, to) + abs(k - pos[i].back()) + abs(pos[i].back() - pos[i][0]) + abs(pos[i][0] - to) + 1
	);

	to = izq(pos[i].back());
	res = min(
		res,
		dp(i + 1, 2, to) + abs(k - pos[i][0]) + abs(pos[i][0] - pos[i].back()) + abs(pos[i].back() - to) + 1
	);

	to = der(pos[i].back());
	res = min(
		res,
		dp(i + 1, 3, to) + abs(k - pos[i][0]) + abs(pos[i][0] - pos[i].back()) + abs(pos[i].back() - to) + 1
	);

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> k >> q;
	n = 0;
	forn(i, k) {
		cin >> r[i] >> c[i];
		n = max(n, r[i]);
		pos[r[i]].pb(c[i]);
	}
	forn(i, q) cin >> b[i];
	
	forn(i, MX) sort(all(pos[i]));
	sort(b, b + q);

	memset(mem, -1, sizeof(mem));
	cout << dp(1, 0, 1) << endl;
 
	return 0;
}