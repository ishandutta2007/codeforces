// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5;

int n, q, x, y, b[N];

double w[3];

int ban[3][3];

struct Node{
	double w[3][3];
	Node operator + (const Node &b) const {
		Node c; 
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				c.w[i][j] = 0;
				for (int k = 0; k < 3; k++) {
					for (int l = 0; l < 3; l++) {
						if (ban[k][l]) continue;
						chkMax(c.w[i][j], w[i][k] + b.w[l][j]);
					}
				}
			}
		}
		return c;
	}	
	double mx() {
		double ans = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) chkMax(ans, w[i][j]);
		return ans;
	}
};

Node ne(int x) {
	Node c; memset(c.w, 0, sizeof c.w);
	for (int i = 0; i < 3; i++) c.w[i][i] = w[i] * x;
	return c;
}

Node t[N << 2];

#define ls (p << 1)
#define rs (p << 1 | 1)

void inline pu(int p) {
	t[p] = t[ls] + t[rs];
}

void bd(int p, int l, int r) {
	if (l == r) {
		t[p] = ne(b[r]);
		return;
	}
	int mid = (l + r) >> 1;
	bd(ls, l, mid), bd(rs, mid + 1, r), pu(p);
}

void chg(int p, int l, int r, int x, int y) {
	if (l == r) {
		t[p] = ne(y); return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) chg(ls, l, mid, x, y);
	else chg(rs, mid + 1, r, x, y);
	pu(p);
}

Node qry(int p, int l, int r, int x, int y) {
	if (x <= l && r <= y) return t[p];
	int mid = (l + r) >> 1;
	if (y <= mid) return qry(ls, l, mid, x, y);
	if (x > mid) return qry(rs, mid + 1, r, x, y);
	return qry(ls, l, mid, x, y) + qry(rs, mid + 1, r, x, y);
}

int main() {
	read(n), read(q), read(x), read(y);
	if (x > y) swap(x, y);
	w[1] = 1.0 / y, w[2] = 1.0 / (x + y);
	ban[1][1] = 1, ban[2][1] = ban[1][2] = 1;
	for (int i = 1; i <= n; i++) read(b[i]);
	bd(1, 1, n);
	while (q--) {
		int op, x, y; read(op), read(x), read(y);
		if (op == 1) {
			chg(1, 1, n, x, y);
		} else {
			printf("%.14lf\n", qry(1, 1, n, x, y).mx());
		}
	}
    return 0;
}