#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') fu = -1; c = getchar();}
	while (c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
	f *= fu;
}

const int N = 2e5 + 5;

struct ele {
	int l, r;
	bool operator < (const ele A) const {return r < A.r || (r == A.r && l < A.l);}
}p[N];

int f[N]; 
int n;

int main() {
	read(n);
	for(int i = 1; i <= n; i++) {
		int a, b;
		read(a); read(b);
		p[i].l = a - b, p[i].r = a + b;
	}
	sort(p + 1, p + n + 1);
	for(int i = 1; i <= n; i++) {
		f[i] = f[i - 1];
		int l = 1, r = i - 1, ans = 0;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(p[mid].r <= p[i].l) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		f[i] = max(f[i], f[ans] + 1);
//		fprintf(stderr, "l = %d, r = %d, f[%d] = %d\n", p[i].l, p[i].r, i, f[i]);
	}
	printf("%d\n", f[n]);
	return 0;
}