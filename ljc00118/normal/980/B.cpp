#include<bits/stdc++.h>
using namespace std;

int a[5][100];
int n, k;

int main() {
	scanf("%d %d", &n, &k);
	int A = k % 2, b = k / 2;
	printf("YES\n");
	for(int i = 2; i <= n / 2 && b > 0; i++) {
		a[2][i] = a[2][n - i + 1] = 1;
		b--;
	}
	for(int i = 2; i <= n / 2 && b > 0; i++) {
		a[3][i] = a[3][n - i + 1] = 1;
		b--;
	}
	if(b == 1) {
		a[2][n / 2 + 1] = a[3][n / 2 + 1] = 1;
	}
	else if(A == 1) a[2][n / 2 + 1] = 1;
	for(int i = 1; i <= 4; i++) {
		for(int j = 1; j <= n; j++) {
			if(a[i][j] == 1) printf("#");
			else printf(".");
		}
		printf("\n");
	}
	return 0;
}