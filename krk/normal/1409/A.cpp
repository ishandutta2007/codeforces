#include <bits/stdc++.h>
using namespace std;

int T;
int a, b;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &a, &b);
		int res = 0;
		if (a != b) res = (abs(a - b) - 1) / 10 + 1;
		printf("%d\n", res);
	}
    return 0;
}