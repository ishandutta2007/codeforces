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

const int N = 2e5 + 5;

struct ele {
	int x, opt;
	bool operator < (const ele A) const { return x < A.x; }
}a[N], b[N];

int Ans[N], n, m, tot;

int main() {
	read(n); read(m);
	for(register int i = 1; i <= n + m; i++) read(a[i].x);
	for(register int i = 1; i <= n + m; i++) {
		read(a[i].opt);
		if(a[i].opt) a[i].opt = ++tot, b[tot] = a[i];
	} sort(a + 1, a + n + m + 1); sort(b + 1, b + m + 1);
	for(register int i = 1; i <= n + m; i++) {
		if(a[i].opt == 0) {
			int l = 1, r = m, ans1 = -1, Q1;
			while(l <= r) {
				int mid = (l + r) >> 1;
				if(b[mid].x <= a[i].x) ans1 = b[mid].x, Q1 = mid, l = mid + 1;
				else r = mid - 1;
			} l = 1, r = m; int ans2 = -1, Q2;
			while(l <= r) {
				int mid = (l + r) >> 1;
				if(b[mid].x >= a[i].x) ans2 = b[mid].x, Q2 = mid, r = mid - 1;
				else l = mid + 1;
			} int ldis = 0x7fffffff, rdis = ldis;
			if(ans1 != -1) ldis = a[i].x - ans1;
			if(ans2 != -1) rdis = ans2 - a[i].x;
			if(ldis <= rdis) Ans[b[Q1].opt]++; else Ans[b[Q2].opt]++;
		}
	}
	for(register int i = 1; i <= m; i++) print(Ans[i], i == m ? '\n' : ' ');
	return 0;
}