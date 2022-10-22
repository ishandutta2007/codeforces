#include <bits/stdc++.h>
using namespace std;

int T;
int n, k1, k2;
int w, b;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &n, &k1, &k2);
		scanf("%d %d", &w, &b);
		if ((k1 + k2) / 2 >= w && (n - k1 + n - k2) / 2 >= b)
			printf("YES\n");
		else printf("NO\n");
	}
    return 0;
}