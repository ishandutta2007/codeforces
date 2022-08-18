#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define DBN(n) cerr << #n << "=" << n << "\n";
#define DB(n) cerr << #n << "=" << n << " ";
#define FI(n) for (int i = 0; i < (n); ++i)
#define FJ(n) for (int j = 0; j < (n); ++j)
#define FK(n) for (int k = 0; k < (n); ++k)
#define FQ(n) for (int q = 0; q < (n); ++q)

string s;
int buffer[100100100];
int *pb = buffer;
int *getNew(int n) {
	pb += n;
	return pb - n;
}
int *tr[11][11][4];
int siz[11][11][4];
void add(int *a, int s, int x, int val) {
	//cout << s << ' ' << x << ' ' << val << endl;
	for (int i = x; i <= s; i |= i + 1) {
		a[i] += val;
	}
}
int getSum(int *a, int x) {
	int res = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
		res += a[i];
	}
	return res;
}
int encode(char c) {
	return c == 'A' ? 0 : c == 'T' ? 1 : c == 'G' ? 2 : 3; 
}
int getCount(int p, int ost, int r, char c) {
	if (r < 0 || r < ost) return 0;
	int k = r / p;
	if (r % p < ost) {
		--k;
	}
	r = k;
	return getSum(tr[p][ost][encode(c)], r);
}
int main() {
	ios_base::sync_with_stdio(false);
	//freopen("in.txt", "rt", stdin);
	cin.tie(0);
	cin >> s;
	for (int p = 1; p <= 10; ++p) {
		for (int ost = 0; ost < p; ++ost) {
			for (int c = 0; c < 4; ++c) {
				siz[p][ost][c] = 100000 / p + 2;
				tr[p][ost][c] = getNew(100000 / p + 4);
			}
		}
	}
	for (int i = 0; i < (int)s.size(); ++i) {
		int c = encode(s[i]);
		for (int p = 1; p <= 10; ++p) {
			add(tr[p][i % p][c], siz[p][i % p][c], i / p, 1);
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int i;
			char c;
			cin >> i >> c;
			--i;
			int oldc = encode(s[i]);
			for (int p = 1; p <= 10; ++p) {
				add(tr[p][i % p][oldc], siz[p][i % p][oldc], i / p, -1);
			}
			int newc = encode(c);
			for (int p = 1; p <= 10; ++p) {
				add(tr[p][i % p][newc], siz[p][i % p][newc], i / p, 1);
			}
			s[i] = c;
		} else {
			int l, r;
			string e;
			cin >> l >> r >> e;
			--l; --r;
			int ans = 0;
			int p = e.size();
			for (int i = 0; i < p; ++i) {
				ans += getCount(p, (i + l) % p, r, e[i]) - getCount(e.size(), (i + l) % p, l - 1, e[i]);
			}
			cout << ans << '\n';
		}
	}
	
	return 0;
}