#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)

#define N 300111

int n;
int a[N], b[N], id[N];
int fir[N], las[N];
void work() {
	read(n);
	for (int i = 0; i <= n + 3; i++) id[i] = 0, fir[i] = 0x3f3f3f3f, las[i] = 0;
	for (int i = 1; i <= n; i++) read(a[i]), b[i] = a[i];
	sort(b + 1, b + n + 1);
	int I = 0;
	for (int i = 1; i <= n; i++) {
		if (!id[b[i]]) id[b[i]] = ++I;
	}

	for (int i = 1; i <= n; i++) {
		fir[id[a[i]]] = min(fir[id[a[i]]], i);
		las[id[a[i]]] = i;
	}

	int ans = 0x3f3f3f3f;
	for (int i = 1; i <= I; ) {
		int j = i + 1;
		while (j <= I && fir[j] >= las[j - 1]) j++;
	//	cerr << i << " " << j << endl;
		ans = min(ans, I - (j - i));
		i = j;
	}

	printf("%d\n", ans);
}

int main() {
	int Q;
	read(Q);
	while (Q--) work();
}