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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, k, p[MX], cn[MX][30], sz[MX];
string s;

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

void join (int a, int b) {
	p[parent(a)] = parent(b);
}

void solve () {
	cin >> n >> k >> s;
	for (int i = 0; i < k; i++) {
		p[i] = i;
		memset(cn[i], 0, sizeof(cn[i]));
		sz[i] = 0;
	}

	for (int i = 0, j = n - 1; i <= j; i++, j--)
		join(i % k, j % k);

	for (int i = 0; i < n; i++) {
		sz[parent(i % k)]++;
		cn[parent(i % k)][s[i]-'a']++;
	}

	int tot = 0;
	for (int i = 0; i < k; i++)
		if (parent(i) == i) {
			int res = sz[i];

			for (int j = 0; j < 26; j++)
				res = min(res, sz[i] - cn[i][j]);

			tot += res;
		}

	cout << tot << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}