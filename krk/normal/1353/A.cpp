#include <bits/stdc++.h>
using namespace std;

int T;
int n, m;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		if (n == 1) printf("0\n");
		else if (n == 2) printf("%d\n", m);
		else printf("%d\n", 2 * m);
	}
    return 0;
}