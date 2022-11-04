#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S | (1 << j ) )
#define LSB(S) (S & (-S))

map <char, int> let = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

struct fenwick_tree {
	vi ft;

	fenwick_tree (int n) : ft(n+1, 0) {}

	void update (int k, int x) {
		while ( k < ft.size() ) {
			ft[k] += x;
			k += LSB(k);
		}
	}

	int getVal (int k) {
		int sum = 0;
		while (k) {
			sum += ft[k];
			k -= LSB(k);
		}
		return sum;
	}

	int query (int a, int b) {
		return getVal(b) - getVal(a-1);
	}
};
typedef vector<fenwick_tree> vft;
typedef vector<vft> vvft;
typedef vector<vvft> vvvft;
vvvft bit(4, vvft(11, vft(11, 1e5+20)));

string s, e;
int n, op, a, b, q;
char c;

void update() {
	cin >> a >> c;
	for (int j = 1; j <= 10; j++) {
		b = let[s[a-1]];
		bit[b][j][a%j].update(a, -1);
		bit[let[c]][j][a%j].update(a, 1);
	}
	s[a-1] = c;
}

void query() {
	cin >> a >> b >> e;

	int res = 0;
	for (int i = 0; i < e.size() && a + i <= b; i++) {
		int x = let[e[i]], y = e.size(), z = (i + a) % y;
		res += bit[x][y][z].query(a+i, b);
	}

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s;
	for (int i = 1; i <= s.size(); i++) {
		a = let[s[i-1]];
		for (int j = 1; j <= 10; j++) {
			bit[a][j][i%j].update(i, 1);
		}
	}

	cin >> q;
	while (q--) {
		cin >> op;
		if ( op == 1 )
			update();
		else
			query();
	}

	return 0;
}