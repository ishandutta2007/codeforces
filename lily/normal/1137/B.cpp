#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define x first
#define y second
#define mp(a, b) make_pair(a, b)
#define read(a) scanf("%d", &a)


#define N 500005

char s[N], t[N];

int nxt[N];

int main() {
	scanf("%s%s", s, t);
	int n = (int)strlen(s), m = (int)strlen(t);
	int c0 = 0, c1 = 0;
	for (int i = 0; i < n; i++) c1 += s[i] == '1';
	c0 = n - c1;
	for (int i = 0; i < m; i++) c0 -= t[i] == '0', c1 -= t[i] == '1';
	if (c0 < 0 || c1 < 0) {
		puts(s);
		return 0;
	}
	nxt[0]=-1;
	for (int i=1,j=-1;i<m;i++) {
		while (t[i]!=t[j+1] && j>=0) j=nxt[j];
		if (t[i]==t[j+1]) j++;
		nxt[i]=j;
	}
	int p = nxt[m - 1], cc0 = 0, cc1 = 0;
	for (int i = p + 1; i < m; i++) cc0 += t[i] == '0', cc1 += t[i] == '1';
	int ans = 0;
	for ( ; c0 >= 0 && c1 >= 0; ans++) {
		c0 -= cc0;
		c1 -= cc1;
	}
	for (int i = 0; i < m; i++) putchar(t[i]);
	while (--ans) {
		for (int i = p + 1; i < m; i++) {
			putchar(t[i]);
		}
	}
	c0 += cc0; c1 += cc1;
	while (c0--) putchar('0');
	while (c1--) putchar('1');
	return 0;
}