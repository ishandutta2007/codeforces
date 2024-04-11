/*input
10 4
agtFrgF4aF
2 5 g
4 9 F
1 5 4
1 7 a
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define N 200005
#define bit(x,y) ((x>>y)&1LL)
#define na(x) (#x) << ":" << x
ostream& operator << (ostream &os, vector<int>&x) {
	for (int i = 0; i < x.size(); i++) os << x[i] << sp;
	return os;
}
ostream& operator << (ostream &os, pair<int, int> x) {
	cout << x.fi << sp << x.se << sp;
	return os;
}
ostream& operator << (ostream &os, vector<pair<int, int> >&x) {
	for (int i = 0; i < x.size(); i++) os << x[i] << endl;
	return os;
}

int b[N];

class ITrangeSum {
private:
	int f[4 * N]; vector<int> s;
public:
	void update(int k, int l, int r, int pos, int val) {
		if (r < pos || pos < l) return;
		if (pos <= l && r <= pos) {
			f[k] += val;
			return;
		}
		int mid = (l + r) / 2;
		update(k * 2, l, mid, pos, val); update(k * 2 + 1, mid + 1, r, pos, val);
		f[k] = f[k * 2] + f[k * 2 + 1];
	}
	int locateITx(int k, int l, int r, int lim) {
		if (l == r) return l;
		int mid = (l + r) / 2;
		if (f[k * 2] >= lim)
			return locateITx(k * 2, l, mid, lim);
		lim -= f[k * 2];
		return locateITx(k * 2 + 1, mid + 1, r, lim);
	}
	int locate(int k, int l, int r, int L, int R) {
		if (r < L || R < l || f[k] == 0) return -1;
		if (l == r) {
			if (f[k] == 1) return l;
			return -1;
		}
		int mid = (l + r) / 2;
		int rec = locate(k * 2, l, mid, L, R);
		if (rec != -1) return rec;
		return locate(k * 2 + 1, mid + 1, r, L, R);
	}
	int get(int k, int l, int r, int L, int R) {
		if (r < L || R < l) return 0;
		if (L <= l && r <= R) return f[k];
		int mid = (l + r) / 2;
		return get(k * 2, l, mid, L, R) + get(k * 2 + 1, mid + 1, r, L, R);
	}
	int Sget(int k, int l, int r, int L, int R) {
		if (r < L || R < l) return 0;
		if (L <= l && r <= R) {
			if (f[k] == 0) return -1;
			return s[k];
		}
		int mid = (l + r) / 2;
		return Sget(k * 2, l, mid, L, R) + Sget(k * 2 + 1, mid + 1, r, L, R);
	}
	void init(int k, int l, int r) {
		if (k == 1) {
			s.assign(4 * N, 0);
		}
		if (l == r) {
			s[k] = b[l];
			return;
		}
		int mid = (l + r) / 2;
		init(k * 2, l, mid); init(k * 2 + 1, mid + 1, r);
	}
} IT[62], ITx;

int n, m;
char a[N];

void update(int wh, int pos, int val) {
	IT[wh].update(1, 1, n, pos, val);
	ITx.update(1, 1, n, pos, val);
}

void clear(int l, int r, int wh) {
	while (1) {
		int rec = IT[wh].locate(1, 1, n, l, r);
		if (rec == -1) break;
		IT[wh].update(1, 1, n, rec, -1);
		ITx.update(1, 1, n, rec, -1);
	}
}

#define dec dec__
map<char, int> enc;
int dec[105];
void prep() {
	int peak = -1;
	for (char c = '0'; c <= '9'; c++) {
		enc[c] = ++peak;
		dec[peak] = c;
	}
	for (char c = 'a'; c <= 'z'; c++) {
		enc[c] = ++peak;
		dec[peak] = c;
	}
	for (char c = 'A'; c <= 'Z'; c++) {
		enc[c] = ++peak;
		dec[peak] = c;
	}
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	prep();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		int c = enc[a[i]];
		b[i] = c;
		update(c, i, 1);
	}
	ITx.init(1, 1, n);
	for (int i = 1; i <= m; i++) {
		int l, r; char c;
		cin >> l >> r >> c;
		l = ITx.locateITx(1, 1, n, l); r = ITx.locateITx(1, 1, n, r);
		clear(l, r, enc[c]);
	}
	for (int i = 1; i <= n; i++) {
		int rec = ITx.Sget(1, 1, n, i, i);
		if (rec != -1) cout << char(dec[rec]);
	}
	cout << endl;
}