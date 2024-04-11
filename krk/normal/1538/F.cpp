#include <bits/stdc++.h>
using namespace std;

int T;
int l, r;

int main()
{
	scanf("%d", &T);
	while (T--) {
		long long res = 0;
		scanf("%d %d", &l, &r);
		while (l < r) {
			res += r - l;
			l /= 10;
			r /= 10;
		}
		printf("%I64d\n", res);
	}
    return 0;
}