#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		long long res = 0;
		int st = 1, len = (n + 1) / 2;
		for (int i = 0; i < len; i++) {
			res += ll(st) * i;
			st = ll(i * 2 + 1) * 4 + 4;
		}
		printf("%I64d\n", res);
	}
    return 0;
}