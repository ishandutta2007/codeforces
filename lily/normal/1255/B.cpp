#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)


int n, m;
int a[1005];
void work() {
	read(n); read(m);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
	}
	if (m < n || n <= 2) puts("-1");
	else {
		int su = 0;
		for (int i = 1; i <= n; i++) su += a[i];
		su *= 2;
		printf("%d\n", su);
		for (int i = 1; i <= n; i++) printf("%d %d\n", i, i % n + 1);
	}
}

int main() {
	int T;
	read(T);
	while (T--) work();


}