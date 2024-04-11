#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int b = 0;
		while (1 << b + 1 <= n) b++;
		printf("%d\n", (1 << b) - 1);
	}
    return 0;
}