#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 500005;
int n, c, a[MX], acu[MX];
vi pos[MX];
int b[2*MX], m;

int sum (int a, int b) {
	if (a > b) return 0;
	return acu[b] - acu[a-1];
}

int kadane () {
	int res = 0, s = 0;

	for (int i = 0; i < m; i++) {
		s += b[i];
		if (s < 0) s = 0;
		res = max(res, s);
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> c;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];

		if (a[i] == c) acu[i] = 1;
		else pos[a[i]].pb(i);
		acu[i] += acu[i-1];
	}

	int res = acu[n];

	for (int i = 1; i < MX; i++)
		if (pos[i].size()) {
			m = 0;
			
			for (int j = 0; j < pos[i].size(); j++) {
				if (j) {
					b[m++] = -sum(pos[i][j-1]+1, pos[i][j]-1);
				}
				b[m++] = 1;
			}

			res = max(res, acu[n] + kadane());
		}

	cout << res << endl;

	return 0;
}