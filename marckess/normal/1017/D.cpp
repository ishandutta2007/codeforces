#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, q, m, w[15], k, st[(1<<12)+5], acu[(1<<12)+5][105], mk;
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> q;

	for (int i = 0; i < n; i++)
		cin >> w[i];
	mk = (1 << n) - 1;

	while (m--) {
		int x = 0;
		cin >> s;
		for (int i = 0; i < n; i++)
			if (s[i] == '1')
				x |= (1 << i);
		st[x]++;
	}

	for (int i = 0; i < (1 << n); i++) {
		int val = 0, x = ~i & mk;
		
		for (int j = 0; j < n; j++)
			if (!(i & (1 << j)))
				val += w[j];

		if (val > 100) continue;

		for (int j = 0; j < (1 << n); j++)
			acu[i^j][val] += st[j];
	}

	for (int i = 0; i < (1 << n); i++)
		for (int j = 1; j <= 100; j++)
			acu[i][j] += acu[i][j-1];

	while (q--) {
		cin >> s >> k;

		int x = 0;
		for (int i = 0; i < n; i++)
			if (s[i] == '1')
				x |= (1 << i);

		cout << acu[x][k] << endl;
	}

	return 0;
}