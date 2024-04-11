#include<bits/stdc++.h>
using namespace std;

const int N = 100 + 10;

int a[N], b[N], f[N];
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d %d", &a[i], &b[i]);
		f[i] = a[i] * 60 + b[i];
		if(i == 1) {
			if(f[i] >= m + 1) {
				printf("0 0");
				return 0;
			}
			else continue;
		}
		if(f[i] - f[i - 1] >= m * 2 + 2) {
			int tmp = f[i - 1] + 1 + m;
			printf("%d %d", tmp / 60, tmp % 60);
			return 0;
		}
	}
	int tmp = f[n] + m + 1;
	printf("%d %d", tmp / 60, tmp % 60);
	return 0;
}