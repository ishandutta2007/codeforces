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

const int MX = 35;
bitset<MX * MX> bs[MX * MX];
int n, a[MX][MX], m, sz, h, res;

#define num(i,j) ((i) * n + (j))

void impr () {
	forn (k, m) {
		cout << k << ": " << endl;
		forn (i, n) {
			forn (j, n)
				cout << bs[k][num(i, j)] << " ";
			cout << endl;
		}
		cout << endl;
	}
}

int val (int i, int j, bitset<MX * MX> &bs) {
	return bs[num(i, j)] ? -a[i][j] : a[i][j];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	h = (n + 1) / 2;

	forn (i, n) forn (j, n) {
		cin >> a[i][j];
		res += a[i][j];
	}

	forn (i, h) forn (j, h) {
		forn (x, h) forn (y, h)
			bs[m][num(i + x, j + y)] = 1;
		m++;
	}

	for (int i = 0; i < n * n; i++) {
		int ind = -1;

		for (int j = sz; j < m; j++)
			if (bs[j][i])
				ind = j;

		if (ind == -1) continue;

		swap(bs[ind], bs[sz]);

		for (int j = 0; j < m; j++)
			if (j != sz && bs[j][i])
				bs[j] ^= bs[sz];

		sz++;
	}

	//impr();

	forn (mk, (1 << h)) {
		bitset<MX * MX> act;

		forn (i, h) if (mk & (1 << i)) act ^= bs[h * (i + 1) - 1];

		int p = 0;
		forn (i, n) p += val(i, h - 1, act);

		forn (j, h - 1) {
			bitset<MX * MX> a = act, b = act ^ bs[h * (h - 1) + j];
			int x = val(h - 1, j, a) + val(h - 1, j + h, a);
			int y = val(h - 1, j, b) + val(h - 1, j + h, b);

			forn (i, h - 1) {
				int q = val(i, j, a) + val(i + h, j, a) + val(i, j + h, a) + val(i + h, j + h, a);
				x += max(q, -q);

				q = val(i, j, b) + val(i + h, j, b) + val(i, j + h, b) + val(i + h, j + h, b);
				y += max(q, -q);
			}

			p += max(x, y);
		}

		res = max(res, p);
	}

	cout << res << endl;

	return 0;
}