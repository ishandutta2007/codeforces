#include <bits/stdc++.h>
using namespace std;

int n;
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		res += abs(a);
	}
	printf("%d\n", res);
	return 0;
}