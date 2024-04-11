#include <bits/stdc++.h>
using namespace std;

int T;
int a, b;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", (a ^ b));
	}
    return 0;
}