#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 3005;

int n, m;
int p[MX], c[MX], q[MX], cn[MX];
vii v[MX];
bitset<MX> us;
ll res = 1e18, acu = 0;

int s[MX], mx;
int maxi () {
	while (mx > 0 && !s[mx])
		mx--;
	return max(0, mx);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> p[i] >> c[i];
		q[i] = i;
		v[p[i]].emplace_back(c[i], i);
	}

	for (int i = 1; i <= m; i++) sort(ALL(v[i]));
	sort(q, q+n, [&] (int i, int j) {
		return c[i] < c[j];
	});

	for (int i = 0; i <= n; i++) {
		us.reset();
		for (int j = 1; j <= m; j++) cn[j] = v[j].size();
		acu = 0;

		for (int j = 2; j <= m; j++) {
			for (int k = 0; cn[j] > i; k++) {
				acu += v[j][k].fi;
				us[v[j][k].se] = 1;
				cn[j]--;
				cn[1]++;
			}
		}

		memset(s, 0, sizeof(s));
		mx = 0;
		for (int j = 2; j <= m; j++) {
			mx = max(mx, cn[j]);
			s[cn[j]]++;
		}


		int j = 0;
		while (maxi() >= cn[1]) {
			while (us[q[j]] || p[q[j]] == 1) j++;
			acu += c[q[j]];
			s[cn[p[q[j]]]]--;
			cn[p[q[j]]]--;
			s[cn[p[q[j]]]]++;
			cn[1]++;
			j++;
		}

		res = min(res, acu);
	}

	cout << res << endl;

	return 0;
}