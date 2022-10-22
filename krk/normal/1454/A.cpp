#include <bits/stdc++.h>
using namespace std;

int t;
int n;

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n - 1; i++)
			printf("%d ", i + 2);
		printf("1\n");
	}
    return 0;
}