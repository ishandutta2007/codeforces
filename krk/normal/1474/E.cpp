#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int T;
int n;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		ll res = 0;
		for (int i = 1; i < n; i++)
			res += ll(i) * i;
		ll res2 = 0;
		int A = (n - 2) / 2;
		int B = n - 2 - A;
		for (int i = A + 1; i < n - 1; i++)
			res2 += ll(i) * i;
		for (int i = B + 1; i < n - 1; i++)
			res2 += ll(i) * i;
		res2 += ll(n - 1) * (n - 1);
		if (res >= res2) {
			printf("%I64d\n", res);
			for (int i = 2; i <= n; i++)
				printf("%d ", i);
			printf("1\n");
			printf("%d\n", n - 1);
			for (int i = 1; i < n; i++)
				printf("%d %d\n", i, n);
		} else {
			printf("%I64d\n", res2);
			printf("%d ", n - 1);
			for (int i = 1; i <= A; i++)
				printf("%d ", i == A? 1: i + 2);
			printf("%d ", n);
			for (int i = 2; i <= B; i++)
				printf("%d ", A + i);
			printf("2\n");
			printf("%d\n", n - 1);
			for (int i = 1; i <= A; i++)
				printf("%d %d\n", 1 + i, n);
			for (int i = B; i >= 1; i--)
				printf("%d 1\n", A + 1 + i);
			printf("1 %d\n", n);
		}
	}
    return 0;
}