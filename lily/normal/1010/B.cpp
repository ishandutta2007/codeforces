/* Heroes Never Die. */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
#define mp(a, b) make_pair(a, b)
#define x first
#define y second
#define read(a) scanf("%d", &a)

int m, n, p;
int a[1005];

int qry(int x) {
	printf("%d\n", x);
	fflush(stdout);
	scanf("%d", &x);
	if (p < n) {
		a[p] = x;
	}
	else {
		if (a[p % n] == -1) x = -x;
	}
	if (x == 0 || x == -2) exit(0);
	p++;
	return x;
}

int main() {
	scanf("%d%d", &m, &n);	
	for (int i = 1; i <= n; i++) qry(1);
	int l = 1, r = m;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		int ret = qry(mid);
		if (ret == 1) l = mid + 1;
		else r = mid - 1;
	}
	qry(l);
	return 0;
}