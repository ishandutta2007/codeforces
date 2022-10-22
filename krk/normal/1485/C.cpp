#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int x, y;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &x, &y);
		ll res = 0;
		int i = 3;
		while (i <= x && i <= y + 1 && ll(i - 2) * i <= x) {
			res += i - 2;
			i++;
		}
		for (; i <= x && i <= y + 1; ) {
			int tims = x / i;
			int lst = min(y + 1, x / tims);
			res += ll(lst - i + 1) * tims;
			i = lst + 1;
		}
		printf("%I64d\n", res);
	}
    return 0;
}