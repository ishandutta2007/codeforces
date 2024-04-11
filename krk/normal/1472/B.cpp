#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int sum = 0;
		bool one = false;
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			sum += a;
			if (a == 1) one = true;
		}
		if (!one && sum / 2 % 2 == 0 ||
			one && sum % 2 == 0)
			printf("YES\n");
		else printf("NO\n");
	}
    return 0;
}