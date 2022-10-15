#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)

#define N 101111

__inline int gcd(int a, int b) {
	int c;
	while (b) {
		c = a;
		a = b;
		b = c % b;
	}
	return a;	
}



int n;
pair <int, int> a[N], b[N];
int pre[N], suf[N];
bool fl[N];

__inline void check() {
	for (int i = 1; i <= n; i++) pre[i] = gcd(a[i].first, pre[i - 1]);
	for (int i = n; i >= 1; i--) suf[i] = gcd(a[i].first, suf[i + 1]);
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(b[i].first), b[i].second = i;
	}
	sort(b + 1, b + n + 1);
	int nn = n;
	n = 0;
	for (int i = 1; i <= nn; ) {
		int j = i;
		while (b[j].first == b[i].first) j++;
		for (int k = 0; k < 2 && i + k < j; k++) {
			a[++n] = b[i + k];
		}
		i = j;
	}
	check();
	if (pre[n] != 1) return 0 * puts("NO");
	bool flag = 0;
	for (int i = 1; i + 2 <= n; i++) {
		if (gcd(pre[i], suf[i + 2]) != 1) {
			flag = 1;
			break;
		}
	}
	if (flag) {
		return 0 * puts("NO");
	}
	int cnt = 0;
	do {
		for (int i = 1; i + 1 <= n; i++) {
			if (pre[i] == 1 && suf[i + 1] == 1) {
				puts("YES");
				for (int j = 1; j <= i; j++) fl[a[j].second] = 1;  
				for (int j = 1; j <= nn; j++) printf("%d ", fl[j] + 1);
				puts("");
				return 0;
			}
		}
		shuffle(a + 1, a + n + 1, mt19937(cnt++));
		check();
	} while (clock() < int(CLOCKS_PER_SEC * 0.45));
	puts("NO");
}