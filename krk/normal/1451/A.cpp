#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int res = 0;
		while (n > 1) {
			res++;
			if (n > 2 && n % 2 == 0) n = 2;
			else n--;
		}
		printf("%d\n", res);
	}
    return 0;
}