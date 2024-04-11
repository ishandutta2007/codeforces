# include <cstdio>
# include <iostream>
using namespace std;

long long f[100010];
int a[100010];

int main() {
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	int p1 = 0, p2 = 0;
	f[1] = 20;
	for(int i = 2; i <= n; ++i) {
		while(a[i] - a[p1 + 1] + 1 > 90) ++p1;
		while(a[i] - a[p2 + 1] + 1 > 1440) ++p2;
		f[i] = f[i - 1] + 20;
		f[i] = min(f[i], f[p1] + 50);
		f[i] = min(f[i], f[p2] + 120);
	}
	for(int i = 1; i <= n; ++i) {
		printf("%d\n", (int)(f[i] - f[i - 1]));
	}
	return 0;
}