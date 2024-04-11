#include <bits/stdc++.h>
using namespace std;

int t;
int n;

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int a = n / 2020;
		int b = n - a * 2020;
		if (b <= a) printf("YES\n");
		else printf("NO\n");
	}
    return 0;
}