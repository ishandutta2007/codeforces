#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++) {
				int res;
				if (n % 2 == 0)
					if (i % 2 == 1)
						if (i + 1 == j) res = 0;
						else if (j % 2 == 1) res = 1;
							 else res = -1;
					else if (j % 2 == 1) res = -1;
					  	 else res = 1;
				else if (j - i <= n / 2) res = 1;
					 else res = -1;
				printf("%d%c", res, i == n - 1 && j == n? '\n': ' ');
			}
	}
    return 0;
}