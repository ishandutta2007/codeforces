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

const int MX = 200005;
ll st[4*MX];
int n, p[MX], q, x, k;

void build (int i, int j, int pos) {
	if (i == j) {
		cin >> st[pos];
		p[i] = pos;
		return;
	}

	int m = (i+j)/2;
	build(i, m, pos*2);
	build(m+1, j, pos*2+1);

	st[pos] = st[pos*2] + st[pos*2+1];
}

void update (int i, int k) {
	int pos = p[i];
	st[pos] = k;
	pos /= 2;

	while (pos) {
		st[pos] = st[pos*2] + st[pos*2+1];
		pos /= 2;
	}
}

ll getSum (int i, int j, int pos, int x) {
	if (x < i)
		return 0;

	if (j <= x)
		return st[pos];

	int m = (i+j)/2;
	return getSum(i, m, pos*2, x) + getSum(m+1, j, pos*2+1, x);
}

int find (int i, int j, int pos, ll k) {
	if (i == j)
		return i;

	int m = (i+j)/2;
	if (st[pos*2] > k)
		return find(i, m, pos*2, k);
	return find(m+1, j, pos*2+1, k - st[pos*2]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> q;
	build(1, n, 1);

	while (q--) {
		cin >> x >> k;
		update(x, k);

		if (st[p[1]] == 0) {
			cout << 1 << endl;
			continue;
		}

		int i = n;
		bool res = 0;

		while (i > 1) {
			ll sum = getSum(1, n, 1, i);
			int j = find(1, n, 1, sum / 2) - 1;

			if (j < n && 2 * getSum(1, n, 1, j) == getSum(1, n, 1, j + 1)) {
				cout << j + 1 << endl;
				res = 1;
				break;
			}

			i = j;
		}

		if (!res)
			cout << -1 << endl;
	}

	return 0;
}