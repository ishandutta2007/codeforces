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

const int MX = 300005, LMX = 20;
int n, a[MX], mn[MX][LMX], g[MX][LMX];
vi res;

int gcd (int a, int b) {
	return b ? gcd(b, a%b) : a;
}

ii query (int l, int r) {
	int k = log2(r-l+1);
	return {
		min(mn[l][k], mn[r-(1<<k)+1][k]),
		gcd(g[l][k], g[r-(1<<k)+1][k])
	};
}

bool esPos (int m, int f) {
	for (int i = 0; i + m - 1 < n; i++) {
		ii r = query(i, i+m-1);
		if (f && r.fi == r.se)
			res.push_back(i+1);
		if (!f && r.fi == r.se)
			return 1;
	}

	return 0;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
		mn[i][0] = g[i][0] = a[i];

	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 0; i + (1 << j) - 1 < n; i++) {
			mn[i][j] = min(mn[i][j-1], mn[i+(1<<(j-1))][j-1]);
			g[i][j] = gcd(g[i][j-1], g[i+(1<<(j-1))][j-1]);
		}

	int i = 1, j = n, rep = 20;
	while (rep--) {
		int m = (i+j)/2;
		if (esPos(m, 0)) i = m;
		else j = m;
	}

	if (esPos(j, 0)) i = j;
	esPos(i, 1);
	cout << res.size() << " " << i-1 << endl;
	for (int x : res)
		cout << x << " ";
	cout << endl;

	return 0;
}