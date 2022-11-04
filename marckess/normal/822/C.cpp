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

const int MX = 200005;
int n, x, l[MX], r[MX], c[MX], res = -1, mn[MX];
vi ini[MX], fin[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	fill(mn, mn+MX, -1);
	
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i] >> c[i];
		ini[l[i]].push_back(i);
		fin[r[i]].push_back(i);
	}

	for (int i = MX-2; i >= 0; i--) {
		for (int j : ini[i+1]) {
			int d = r[j] - l[j] + 1;
			if (mn[d] == -1 || mn[d] > c[j])
				mn[d] = c[j];
		}
		for (int j : fin[i]) {
			int d = r[j] - l[j] + 1;
			if (d >= x) continue;
			if (mn[x-d] != -1)
				if (res == -1 || c[j] + mn[x-d] < res)
					res = c[j] + mn[x-d];
		}
	}

	cout << res << endl;

	return 0;
}