#include <bits/stdc++.h>
using namespace std;

int T;
int a, b, c;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &a, &b, &c);
		int sum = a + b + c;
		int x = sum / 9;
		if (sum % 9 == 0 && x <= a && x <= b && x <= c)
			printf("YES\n");
		else printf("NO\n"); 
	}
    return 0;
}