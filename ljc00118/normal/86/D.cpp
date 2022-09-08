#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define For(i, a, b) for(register int i = a; i <= b; i++)
#define Rof(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
	while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
	f *= fu;
}

template <typename T>
void print(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int N = 2e5 + 5, M = 1e6 + 5;

struct ele { int l, r, id; } Q[N];

int B[N], cnt[M], a[N];
int n, m, blk; ll Ans[N], ans;

inline bool cmp(ele a, ele b) { return B[a.l] == B[b.l] ? a.r < b.r : a.l < b.l; }

inline void add(int x) {
	ans += (ll)x * (cnt[x] << 1 | 1);
	cnt[x]++;
}

inline void del(int x) {
	cnt[x]--;
	ans -= (ll)x * (cnt[x] << 1 | 1);
}

int main() {
	read(n); read(m); blk = n / (sqrt(m * 2 / 3) + 1) + 1;
	for(register int i = 1; i <= n; i++) read(a[i]), B[i] = (i - 1) / blk + 1;
	for(register int i = 1; i <= m; i++) read(Q[i].l), read(Q[i].r), Q[i].id = i;
	sort(Q + 1, Q + m + 1, cmp); int l = 1, r = 0;
	for(register int i = 1; i <= m; i++) {
		while(r < Q[i].r) add(a[++r]);
		while(l > Q[i].l) add(a[--l]);
		while(r > Q[i].r) del(a[r--]);
		while(l < Q[i].l) del(a[l++]);
		Ans[Q[i].id] = ans;
	}
	for(register int i = 1; i <= m; i++) print(Ans[i], '\n');
	return 0;
}