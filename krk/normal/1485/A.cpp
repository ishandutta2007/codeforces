#include <bits/stdc++.h>
using namespace std;

int T;
int a, b;

int Get(int a, int b)
{
	if (b == 1) return 1000000000;
	int res = 0;
	while (a) {
		res++;
		a /= b;
	}
	return res;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &a, &b);
		int res = 1000000000;
		for (int i = 0; i <= 20; i++)
			res = min(res, i + Get(a, b + i));
		printf("%d\n", res);
	}
    return 0;
}