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

const int MX = 1e5+5;
int n, a[MX], sig[2][MX], in[MX];
vii res;
vi pos[2];

int isPos (int x) {
	int i = 1, j = 1, pi, pj, a = 0, b = 0;

	while (1) {
		i = sig[0][i];
		if (i != -1) pi = in[i];

		j = sig[1][j];
		if (j != -1) pj = in[j];

		if (i != -1 && pi + x <= pos[0].size() && j != -1 && pj + x <= pos[1].size()) {
			if (pos[0][pi+x-1] < pos[1][pj+x-1]) {
				i = j = pos[0][pi+x-1];
				a++; 

				if (i == n && a > b) return a;

			} else {
				i = j = pos[1][pj+x-1];
				b++;

				if (i == n && a < b) return b;
			}
		} else if (i != -1 && pi + x <= pos[0].size()) {
			i = j = pos[0][pi+x-1];
			a++;

			if (i == n && a > b) return a;

		} else if (j != -1 && pj + x <= pos[1].size()) {
			i = j = pos[1][pj+x-1];
			b++;

			if (i == n && a < b) return b;

		} else {
			return -1;
		}

		i++, j++;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(sig, -1, sizeof(sig));

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i]--;
		
		in[i] = pos[a[i]].size();
		pos[a[i]].pb(i);
		sig[a[i]][i] = i;
	}

	for (int i = n; i; i--)
		sig[1 - a[i]][i] = sig[1 - a[i]][i + 1];

	for (int i = 1; i <= n; i++) {
		int d = isPos(i);
		if (d != -1) res.emplace_back(d, i);
	}

	sort(all(res));

	cout << res.size() << endl;
	for (ii &r : res)
		cout << r.fi << " " << r.se << endl;

	return 0;
}