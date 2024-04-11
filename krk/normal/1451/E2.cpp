#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1 << 16;

int n;
int mask[Maxn + 5];
int my;
int A[Maxn], B[Maxn];

int Xor(int a, int b)
{
	printf("XOR %d %d\n", a, b); fflush(stdout);
	int res; scanf("%d", &res);
	return res;
}

int Or(int a, int b)
{
	printf("OR %d %d\n", a, b); fflush(stdout);
	int res; scanf("%d", &res);
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
		mask[i] = Xor(1, i);
	int p = 2;
	while (1 << p < n) p++;
	int a = p / 2;
	int b = p - a;
	for (int i = 1; i <= n; i++) {
		int num = (mask[i] >> b);
		if (A[num]) {
			int got = Or(A[num], i);
			for (int j = b; j < p; j++)
				if (bool(got & 1 << j) != bool(mask[i] & 1 << j))
					my |= 1 << j;
			break;
		} else A[num] = i;
	}
	int all = (1 << b) - 1;
	for (int i = 1; i <= n; i++) {
		int num = (mask[i] & all);
		if (B[num]) {
			int got = Or(B[num], i);
			for (int j = 0; j < b; j++)
				if (bool(got & 1 << j) != bool(mask[i] & 1 << j))
					my |= 1 << j;
			break;
		} else B[num] = i;
	}
	printf("!");
	for (int i = 1; i <= n; i++)
		printf(" %d", (my ^ mask[i]));
	printf("\n");
	fflush(stdout);
    return 0;
}