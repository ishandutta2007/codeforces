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

const int MX = 100005;
int n, k[MX], q, ft[MX], res[MX], l[MX], r;
map<ii, int> mp;
vi pos[MX], x[MX], y[MX];

void update (int i, int k) {
	while (i < MX) {
		ft[i] += k;
		i += i & -i;
	}
}

int query (int i) {
	int s = 0;
	while (i) {
		s += ft[i];
		i -= i & -i;
	}
	return s;
}

int query (int a, int b) {
	return query(b) - query(a - 1);
} 

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		x[i].resize(k[i] + 1), y[i].resize(k[i] + 1);
		for (int j = 0; j < k[i]; j++)
			cin >> x[i][j] >> y[i][j];
		x[i][k[i]] = x[i][0];
		y[i][k[i]] = y[i][0];
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> l[i] >> r;
		pos[r].pb(i);
	}

	for (int i = 1; i <= n; i++) {
		update(i, k[i]);

		for (int j = 0; j < k[i]; j++) {
			int a = x[i][j] - x[i][j+1];
			int b = y[i][j] - y[i][j+1];
			int g = __gcd(abs(a), abs(b));
			a /= g;
			b /= g;

			if (mp.count(ii(a, b)) && mp[ii(a, b)] != i)
				update(mp[ii(a, b)], -1);
			mp[ii(a, b)] = i;
		}

		for (int j : pos[i])
			res[j] = query(l[j], i);
	}

	for (int i = 0; i < q; i++)
		cout << res[i] << endl;

	return 0;
}