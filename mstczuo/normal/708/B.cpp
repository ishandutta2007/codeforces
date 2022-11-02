# include <iostream>
# include <cmath>
# include <cstdio>

using namespace std;

int main() {
	int A, B, C, D;
	scanf("%d%d%d%d", &A, &B, &C, &D);
	if(!A && !B && !C && !D) {
		puts("0");
		return 0;
	}
	if(A == 0 && D > 0 && B == 0 && C == 0) {
		int b = sqrt(D * 2) + 1;
		if(b * (b - 1) / 2 == D) {
			while(b--) putchar('1'); puts("");
		} else {
			puts("Impossible");
		}
		return 0;
	}
	if(A > 0 && D == 0 && B == 0 && C == 0) {
		int a = sqrt(A * 2) + 1;
		if(a * (a - 1) / 2 == A) {
			while(a--) putchar('0'); puts("");
		} else {
			puts("Impossible");
		}
		return 0;
	}
	int a = sqrt(A * 2) + 1;
	int b = sqrt(D * 2) + 1;
	if(a * (a - 1) / 2 != A || b * (b - 1) / 2 != D || a * b != B + C) {
		puts("Impossible");
		return 0;
	}

	int cnt = b;
	for(int i = 0; i < a + b; ++i) {
		if(B >= cnt) {
			putchar('0');
			B -= cnt;
		} else {
			putchar('1');
			cnt -= 1;
		}
	}
	puts("");
	
	return 0;
}