#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
	scanf("%d", &T);
	while (T--) {
		int res = 0;
		scanf("%d", &n);
		while (n--) {
			int r; scanf("%d", &r);
			if (r == 1 || r == 3)
				res++;
		}
		printf("%d\n", res);
	}
    return 0;
}