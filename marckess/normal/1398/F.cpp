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

const int MX = 1000005;
int n, sig[MX][2], p[MX], to[MX];
vi pos[MX];
string s;

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

void join (int a, int b) {
	a = parent(a);
	b = parent(b);
	if (a < b) swap(a, b);
	p[b] = a;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	iota(p, p + MX, 0);
	
	cin >> n >> s;
	
	sig[n][0] = sig[n][1] = n;

	for (int i = n - 1; i >= 0; i--) {
		sig[i][0] = sig[i + 1][0];
		sig[i][1] = sig[i + 1][1];

		if (s[i] == '0') sig[i][0] = i;
		if (s[i] == '1') sig[i][1] = i;
	}

	forn (i, n) {
		to[i] = max(sig[i][0], sig[i][1]);
		pos[to[i] - i].pb(i);
	}

	for (int i = 1; i <= n; i++) {
		int res = 0, u = parent(0);

		while (u + i <= n) {
			res++;
			u = parent(u + i);
		}

		cout << res << " ";

		for (int j : pos[i])
			join(j, j + 1);
	}

	cout << endl;

	return 0;
}