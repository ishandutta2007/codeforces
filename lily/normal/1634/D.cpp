#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second

int query (int i, int j, int k) {
	printf("? %d %d %d\n", i, j, k);
	fflush(stdout);
	int ret; scanf("%d", &ret);
	if (ret == -1) exit(0);
	return ret;
}

void answer (int i, int j) {
	printf("! %d %d\n", i, j);
	fflush(stdout);
}



void work() {
	int n;
	read(n);
	int i = 1, j = 2, w = 3, l = query (1, 2, 3);
	for (int k = 4; k <= n; k++) {
		int d1 = query (i, j, k);
		int d2 = query (j, w, k);
		if (l >= d1 && l >= d2) continue;
		else if (d1 >= l && d1 >= d2) w = k, l = d1;
		else if (d2 >= l && d2 >= d1) i = k, l = d2;
	}
	for (int k = 1; k <= n; k++) if (k != i && k != j && k != w) {
		int ij = query (i, j, k);
		int iw = query (i, w, k);
		if (ij == l) answer (i, j);
		else if (iw == l) answer (i, w);
		else answer (j, w);
		break;
	}
}

int main() {
	int T;
	read(T);
	while (T--) {
		work();
	}
}