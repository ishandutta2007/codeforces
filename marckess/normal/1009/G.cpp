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

const int MX = 100005;
int n, m, p, cn[6], pos[MX][64], mk[MX];
string s, t, res;

void no () {
	cout << "Impossible" << endl;
	exit(0);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s >> m;
	n = s.size();

	while (m--) {
		cin >> p >> t;

		for (int c : t)
			mk[p-1] |= 1 << (c - 'a');
	}

	for (int i = 0; i < n; i++) {
		if (!mk[i])
			mk[i] = 63;

		for (int j = 1; j < 64; j++)
			if (j & mk[i])
				pos[i][j] = 1;
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 64; j++)
			pos[i][j] += pos[i+1][j];
		cn[s[i]-'a']++;
	}

	for (int k = 0; k < n; k++) {
		int d[64];

		for (int i = 1; i < 64; i++) {
			d[i] = pos[k+1][i];

			for (int j = 0; j < 6; j++)
				if (i & (1 << j))
					d[i] -= cn[j];
		}

		for (int j = 0;; j++) {
			if (j == 6) no();
			if (!cn[j] || !(mk[k] & (1 << j))) continue;

			for (int i = 1; i < 64; i++)
				if (i & (1 << j))
					d[i]++;

			bool f = 1;
			for (int i = 1; i < 64; i++) 
				if (d[i] < 0)
					f = 0;

			if (f) {
				cn[j]--;
				res.pb(j + 'a');
				break;
			}

			for (int i = 1; i < 64; i++)
				if (i & (1 << j))
					d[i]--;
		}
	}

	cout << res << endl;

	return 0;
}