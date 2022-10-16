// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1005;

#define I __int128

int n, m;
I a[N], b[N], val[N];

I gcd(I a, I b) {
	return b ? gcd(b, a % b) : a; 
}

struct Seg{
	int n;
	I w[N], d[N << 2];
	#define ls (p << 1)
	#define rs (p << 1 | 1)
	void inline pushup(int p) {
		d[p] = gcd(d[ls], d[rs]);
	}
	void build(int p, int l, int r) {
		if (l == r) {
			d[p] = w[r];
			return;
		}
		int mid = (l + r) >> 1;
		build(ls, l, mid);
		build(rs, mid + 1, r);
		pushup(p);
	}
	void chg(int p, int l, int r, int x) {
		if (l == r) {
			d[p] = 0;
			return;
		}
		int mid = (l + r) >> 1;
		if (x <= mid) chg(ls, l, mid, x);
		else chg(rs, mid + 1, r, x);
		pushup(p);
	}
	void inline init(int len, I *a) {
		n = len;
		for (int i = 1; i <= len; i++) w[i] = a[i];
		build(1, 1, len);
	}
} A[N], B[N];

bool sA[N], sB[N];

int ca, cb;

bool find() {
	for (int i = 1; i <= n; i++) {
		if (!sA[i] && A[i].d[1] != 1) {
			sA[i] = 1, ca--;
			for (int j = 1; j <= m; j++)
				B[j].chg(1, 1, n, i);
			return 1;
		}
	}
	for (int i = 1; i <= m; i++) {
		if (!sB[i] && B[i].d[1] != 1) {
			sB[i] = 1, cb--;
			for (int j = 1; j <= n; j++)
				A[j].chg(1, 1, m, i);
			return 1;
		}
	}
	return 0;
}

void print(I x) {
	if (x >= 10) print(x / 10);
	putchar((x % 10) + '0');
}

int main() {
	int T; read(T);
	while (T--) {
		read(n), read(m);
		for (int i = 1; i <= n; i++) read(a[i]);
		for (int i = 1; i <= m; i++) read(b[i]);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				val[j] = a[i] / gcd(a[i], b[j]);
			A[i].init(m, val);		
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++)
				val[j] = b[i] / gcd(b[i], a[j]);
			B[i].init(n, val);
		}
		ca = n, cb = m;
		while (1) {
			if (!find()) break;
		}
		if (!ca || !cb) puts("NO");
		else  {
			puts("YES");
			printf("%d %d\n", ca, cb);
			for (int i = 1; i <= n; i++)	
				if (!sA[i]) print(a[i]), putchar(' ');
			puts("");
			for (int i = 1; i <= m; i++)	
				if (!sB[i]) print(b[i]), putchar(' ');
			puts("");
		}
		for (int i = 1; i <= max(n, m); i++) sA[i] = sB[i] = 0;
	}
    return 0;
}