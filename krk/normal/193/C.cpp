#include <cstdio>
using namespace std;

const int Inf = 1000000000;

int b2, b3, b4;
int h23, h24, h34;
int t23, t24, t34;
int a, b, c, d = Inf;
int xa, xb, xc;

bool findTakes()
{
	t23 = b2 + b3 - h23;
	if (t23 < 0 || t23 % 2) return false;
	t23 /= 2;
	if (t23 > b2 || t23 > b3) return false;
	t24 = b2 + b4 - h24;
	if (t24 < 0 || t24 % 2) return false;
	t24 /= 2;
	if (t24 > b2 || t24 > b4) return false;
	t34 = b3 + b4 - h34;
	if (t34 < 0 || t34 % 2) return false;
	t34 /= 2;
	if (t34 > b3 || t34 > b4) return false;
	return true;
}

int main()
{
	scanf("%d %d %d", &b2, &b3, &b4);
	scanf("%d %d", &h23, &h24);
	scanf("%d", &h34);
	if (!findTakes()) printf("-1\n");
	else {
		a = b2 - t23, b = t23, c = b3 - t23;
		for (int i = 0; i <= a && i <= t24; i++) {
			int j = t24 - i;
			if (j <= t34 && j <= b) {
				int k = t34 - j;
				if (k <= c && i + j + k <= b4) {
					int l = b4 - i - j - k;
					if (l < d) { d = l; xa = i, xb = j; xc = k; }
				}
			}
		}
		if (d == Inf) printf("-1\n");
		else {
			int n = a + b + c + d;
			// first
			printf("%d\n", n);
			for (int i = 0; i < n; i++)
				printf("a");
			printf("\n");
			// second
			for (int i = 0; i < a + b; i++)
				printf("b");
			for (int i = a + b; i < n; i++)
				printf("a");
			printf("\n");
			// third
			for (int i = 0; i < a; i++)
				printf("a");
			for (int i = a; i < a + b + c; i++)
				printf("b");
			for (int i = a + b + c; i < n; i++)
				printf("a");
			printf("\n");
			// fourth
			for (int i = 0; i < a; i++)
				printf("%c", i < xa? 'b': 'a');
			for (int i = 0; i < b; i++)
				printf("%c", i < xb? 'b': 'a');
			for (int i = 0; i < c; i++)
				printf("%c", i < xc? 'b': 'a');
			for (int i = 0; i < d; i++)
				printf("b");
			printf("\n");
		}
	}
	return 0;
}