#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int n, a[111111], cnt, test;
int main()
{
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] != 0 && a[i - 1] == 0) cnt++;
		}
		printf("%d\n", min(cnt, 2));
    }
	return Accepted;
}