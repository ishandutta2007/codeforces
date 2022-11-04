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
int n, q, l, r, k;
int st[4*MX][26], res[26], lz[4*MX];
char c[MX];

void build (int i, int j, int pos) {
	lz[pos] = -1;

	if (i == j) {
		for (int l = 0; l < 26; l++)
			st[pos][l] = 0;
		st[pos][c[i]-'a'] = 1;
		return;
	}

	int m = (i+j)/2;
	build(i, m, pos*2);
	build(m+1, j, pos*2+1);

	for (int l = 0; l < 26; l++)
		st[pos][l] = st[pos*2][l] + st[pos*2+1][l];
}

void push (int i, int j, int pos) {
	for (int l = 0; l < 26; l++)
		st[pos][l] = 0;
	st[pos][lz[pos]] = j-i+1;

	if (i < j) {
		lz[pos*2] = lz[pos];
		lz[pos*2+1] = lz[pos];
	}

	lz[pos] = -1;
}

void query (int i, int j, int pos, int a, int b) {
	if (lz[pos] != -1)
		push(i, j, pos);

	if (b < i || j < a)
		return;

	if (a <= i && j <= b) {
		for (int l = 0; l < 26; l++)
			res[l] += st[pos][l];
		return;
	}

	int m = (i+j)/2;
	query(i, m, pos*2, a, b);
	query(m+1, j, pos*2+1, a, b);
}

void update (int i, int j, int pos, int a, int b, int c) {
	if (lz[pos] != -1)
		push(i, j, pos);

	if (b < i || j < a)
		return;

	if (a <= i && j <= b) {
		lz[pos] = c;
		push(i, j, pos);
		return;
	}

	int m = (i+j)/2;
	update(i, m, pos*2, a, b, c);
	update(m+1, j, pos*2+1, a, b, c);

	for (int l = 0; l < 26; l++)
		st[pos][l] = st[pos*2][l] + st[pos*2+1][l];
}

void impr (int i, int j, int pos) {
	if (lz[pos] != -1)
		push(i, j, pos);

	if (i == j) {
		for (int l = 0; l < 26; l++)
			if (st[pos][l])
				cout << char(l+'a');
		return;
	}

	int m = (i+j)/2;
	impr(i, m, pos*2);
	impr(m+1, j, pos*2+1);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> c[i];

	build(1, n, 1);

	while (q--) {
		cin >> l >> r >> k;

		for (int l = 0; l < 26; l++)
			res[l] = 0;
		query(1, n, 1, l, r);

		int z = l;
		if (k) {
			for (int l = 0; l < 26; l++)
				if (res[l]) {
					update(1, n, 1, z, z+res[l]-1, l);
					z += res[l];
				}
		} else {
			for (int l = 25; l >= 0; l--)
				if (res[l]) {
					update(1, n, 1, z, z+res[l]-1, l);
					z += res[l];
				}
		}
	}

	impr(1, n, 1);
	cout << endl;

	return 0;
}