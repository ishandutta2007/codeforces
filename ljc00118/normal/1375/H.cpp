#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1 << 12, B = 1 << 8;

vector < vector <int> > id[N / B + 5];
vector <int> pos[N / B + 5];
int a[N + 5], res[2200005][2], ans[1 << 16 | 5];
int n, q, tot;

inline int merge(int x, int y) {
	if (!x || !y) return x | y;
	++tot; res[tot][0] = x; res[tot][1] = y; return tot;
}

vector < vector <int> > build(int l, int r, vector <int> pos) {
	if (l == r) {
		vector < vector <int> > ans;
		ans.resize(1, vector <int> (1, pos[0]));
		return ans;
	}
	int mid = (l + r) >> 1;
	vector <int> posl, posr;
	for (int i = 0; i < (int)pos.size(); i++) {
		if (a[pos[i]] <= mid) posl.push_back(pos[i]);
		else posr.push_back(pos[i]);
	}
	vector < vector <int> > resl = build(l, mid, posl), resr = build(mid + 1, r, posr), res(r - l + 1, vector <int> (r - l + 1, 0));
	for (int i = 0; i < r - l + 1; i++) {
		for (int j = i; j < r - l + 1; j++) {
			int idl = 0, idr = 0;
			int L = lower_bound(posl.begin(), posl.end(), pos[i]) - posl.begin();
			int R = upper_bound(posl.begin(), posl.end(), pos[j]) - posl.begin() - 1;
			if (L <= R) idl = resl[L][R];
			L = lower_bound(posr.begin(), posr.end(), pos[i]) - posr.begin();
			R = upper_bound(posr.begin(), posr.end(), pos[j]) - posr.begin() - 1;
			if (L <= R) idr = resr[L][R];
			res[i][j] = merge(idl, idr);
		}
	}
	return res;
}

int main() {
	read(n); read(q); tot = n;
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= (n - 1) / B + 1; i++) {
		int l = (i - 1) * B + 1, r = min(i * B, n);
		for (int j = 1; j <= n; j++) {
			if (l <= a[j] && a[j] <= r) pos[i].push_back(j);
		}
		id[i] = build(l, r, pos[i]);
	}
	for (int _ = 1; _ <= q; _++) {
		int l, r;
		read(l); read(r);
		for (int i = 1; i <= (n - 1) / B + 1; i++) {
			int L = lower_bound(pos[i].begin(), pos[i].end(), l) - pos[i].begin();
			int R = upper_bound(pos[i].begin(), pos[i].end(), r) - pos[i].begin() - 1;
			if (L <= R) ans[_] = merge(ans[_], id[i][L][R]);
		}
	}
	print(tot, '\n');
	for (int i = n + 1; i <= tot; i++) print(res[i][0], ' '), print(res[i][1], '\n');
	for (int i = 1; i <= q; i++) print(ans[i], i == q ? '\n' : ' ');
	return 0;
}