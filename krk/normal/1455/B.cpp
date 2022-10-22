#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int k = 1;
		while (n > 0) {
			n -= k;
			k++;
		}
		if (n == -1) k++;
		printf("%d\n", k - 1);
	}
    return 0;
}