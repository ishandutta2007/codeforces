#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 2'000'005;
int zf[MX], n;
string a, b, inv;
char ret[256];

void obtZF (string s) {
	int n = s.size();

	for (int i = 1, l = 0, r = 0; i < n; i++) {
		if (i <= r)
			zf[i] = min(r - i + 1, zf[i - l]);

		while (i + zf[i] < n && s[zf[i]] == s[i + zf[i]])
			zf[i]++;

		if (i + zf[i] - 1 > r)
			l = i, r = i + zf[i] - 1;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ret['N'] = 'S';
	ret['S'] = 'N';
	ret['W'] = 'E';
	ret['E'] = 'W';

	cin >> n >> a >> b;
	n--;
	inv.resize(n);

	for (int i = 0; i < n; i++)
		inv[i] = ret[b[n-i-1]];

	obtZF(inv + "$" + a);

	for (int i = n; i < 2 * n + 1; i++)
		if (zf[i] == 2 * n + 1 - i) {
			cout << "no" << endl;
			return 0;
		}

	cout << "yes" << endl;

	return 0;
}