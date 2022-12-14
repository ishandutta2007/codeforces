#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int test, n;
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		printf("%d\n", (n + 1) / 10);
	}
	return Accepted;
}