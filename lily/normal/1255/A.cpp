#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)


int n, m;
int a[1005];
void work() {
	read(n); read(m);
	int d =abs(n - m);
	printf("%d\n", d / 5 + d % 5 / 2 + d % 5 % 2);
}

int main() {
	int T;
	read(T);
	while (T--) work();
}