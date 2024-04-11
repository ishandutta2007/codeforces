#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
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

const int N = 2e5 + 5;

struct find_first {
	const int block = (int)sqrt(N);
	
	int cnt[N], cnt2[N], B[N], bl[N], br[N], n;
	
	void init() {
		memset(bl, -1, sizeof(bl));
		for(register int i = 0; i <= n; i++) {
			B[i] = i / block + 1;
			if(bl[B[i]] == -1) bl[B[i]] = i;
			br[B[i]] = i;
		}
	}
	
	void add(int x) {
		cnt[x]++;
		if(cnt[x] == 1) cnt2[B[x]]++;
	}
	
	void del(int x) {
		cnt[x]--;
		if(cnt[x] == 0) cnt2[B[x]]--;
	}
	
	int query() {
//		fprintf(stderr, "debug >>> \n");
//		for(register int i = 0; i <= n; i++) print(cnt[i], i == n ? '\n' : ' ');
		for(register int i = 1; i <= B[n]; i++) {
			if(cnt2[i] != br[i] - bl[i] + 1) {
				for(register int j = bl[i]; j <= br[i]; j++)
					if(cnt[j] == 0) return j;
			}
		}
		throw "query error";
	}
} wxw;

struct modify { int x, y; modify (int a = 0, int b = 0) : x(a), y(b) {} } m[N];

int B[N];

struct ele {
	int l, r, t, id;
	ele (int a = 0, int b = 0, int c = 0, int d = 0) : l(a), r(b), t(c), id(d) {} 
	bool operator < (const ele A) { return B[l] == B[A.l] ? (B[r] == B[A.r] ? t < A.t : r < A.r) : l < A.l; }
} Q[N];

int a[N], b[N], Ans[N], cnt[N], cntt[N];
int n, q, cnt1, cnt2, blk, big, l = 1, r = 0, t = 0;

void add(int x) { wxw.del(cnt[x]); cnt[x]++; wxw.add(cnt[x]); }

void del(int x) { wxw.del(cnt[x]); cnt[x]--; wxw.add(cnt[x]); }

void change(int u) {
	if(m[u].x >= l && m[u].x <= r) del(a[m[u].x]);
	swap(m[u].y, a[m[u].x]);
	if(m[u].x >= l && m[u].x <= r) add(a[m[u].x]);
}

int main() {
	read(n); read(q); blk = (int)pow(n + q, 2.0 / 3.0); wxw.n = n; wxw.init(); big = n;
	for(register int i = 1; i <= n; i++) read(a[i]), b[i] = a[i];
	for(register int i = 1; i <= q + n; i++) B[i] = (i - 1) / blk + 1;
//	sort(b + 1, b + n + 1); big = unique(b + 1, b + n + 1) - b - 1;
//	for(register int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + big + 1, a[i]) - b; 
	for(register int i = 1; i <= q; i++) {
		int opt, x, y; read(opt); read(x); read(y);
		if(opt == 1) Q[++cnt1] = ele(x, y, cnt2, cnt1);
		if(opt == 2) m[++cnt2] = modify(x, y), b[++big] = y;
	}
	sort(b + 1, b + big + 1); big = unique(b + 1, b + big + 1) - b - 1;
	for(register int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + big + 1, a[i]) - b;
	for(register int i = 1; i <= cnt2; i++) m[i].y = lower_bound(b + 1, b + big + 1, m[i].y) - b;
	sort(Q + 1, Q + cnt1 + 1); for(register int i = 1; i <= big + 1; i++) wxw.add(0);
	for(register int i = 1; i <= cnt1; i++) {
		while(r < Q[i].r) add(a[++r]);
		while(l > Q[i].l) add(a[--l]);
		while(r > Q[i].r) del(a[r--]);
		while(l < Q[i].l) del(a[l++]);
		while(t < Q[i].t) change(++t);
		while(t > Q[i].t) change(t--);
		Ans[Q[i].id] = wxw.query();
	}
	for(register int i = 1; i <= cnt1; i++) print(Ans[i], '\n');
	return 0;
}

// Rotate Flower Round.