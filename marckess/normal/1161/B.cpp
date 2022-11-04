#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, m, x, y;
vi seg[MX], a;
map<vi, int> mp;

vi obtZF (vi &s) {
    int n = s.size();
    vi zf(n);

    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
			zf[i] = min (r - i + 1, zf[i - l]);
        while (i + zf[i] < n && s[zf[i]] == s[i + zf[i]])
			zf[i]++;
        if (i + zf[i] - 1 > r)
			l = i, r = i + zf[i] - 1;
	}

	return zf;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	while (m--) {
		cin >> x >> y;
		seg[x-1].pb(MOD(x-y, n));
		seg[y-1].pb(MOD(y-x, n));
	}

	a.resize(2 * n);

	for (int i = 0; i < n; i++) {
		sort(all(seg[i]));
		if (!mp.count(seg[i])) mp[seg[i]] = mp.size();
		a[i] = a[i+n] = mp[seg[i]];
	}

	vi z = obtZF(a);
	for (int i = 1; i < n; i++) {
		if (z[i] >= n) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << endl;

	cout << "No" << endl;

	return 0;
}