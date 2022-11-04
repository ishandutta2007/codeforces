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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, q, a[MX], res[2*MX], s[MX], x[MX], p[MX], st[4*MX], in[4*MX];
vi pos[2*MX];

void build (int i, int j, int pos) {
	if (i == j) {
		p[i] = pos;
		return;
	}
	int m = (i + j) / 2;
	build(i, m, pos*2);
	build(m+1, j, pos*2+1);
}

void update (int i, int x, int y) {
	int pos = p[i];
	st[pos] = x;
	in[pos] = y;
	pos /= 2;

	while (pos) {
		if (st[pos*2] == 1) st[pos] = st[pos*2+1];
		else st[pos] = -in[pos*2+1];
		if (in[pos*2] == 1) in[pos] = in[pos*2+1];
		else in[pos] = -st[pos*2+1];
		pos /= 2;
	}
}

void update (int j, int act, int num, int s) {	
	int x, y;
	if (act < num && s == -1) x = -1;
	else if (act > num && s == 1) x = -1;
	else x = 1;
	if (-act < num && s == -1) y = -1;
	else if (-act > num && s == 1) y = -1;
	else y = 1;
	update(j, x, y);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= q; i++) {
		char c;
		cin >> c >> x[i];
		if (c == '>') s[i] = 1;
		else s[i] = -1;
		pos[x[i]+MX].pb(i);
	}

	build(1, q, 1);

	int i = -100000;
	for (int j = 1; j <= q; j++)
		update(j, i, x[j], s[j]);

	do {
		for (int j : pos[i+MX]) update(j, i, x[j], s[j]);
		for (int j : pos[-i+MX]) update(j, i, x[j], s[j]);

		res[i+MX] = i * st[1];

		for (int j : pos[i+MX]) update(j, i+1, x[j], s[j]);
		for (int j : pos[-i+MX]) update(j, i+1, x[j], s[j]);

		i++;
	} while (i <= 100000);

	for (int i = 1; i <= n; i++)
		cout << res[a[i]+MX] << " ";
	cout << endl;

	return 0;
}