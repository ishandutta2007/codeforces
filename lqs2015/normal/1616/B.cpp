#include <bits/stdc++.h>
using namespace std;
int test, n, res;
char s[111111];
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		scanf("%s", s);
		res = n - 1;
		for (int i = 0; i < n - 1; i++)
		{
			if (s[i + 1] > s[i] || (i == 0 && s[i + 1] == s[i]))
			{
				res = i;
				break;
			}
		}
		for (int i = 0; i <= res; i++) putchar(s[i]);
		for (int i = res; i >= 0; i--) putchar(s[i]);
		putchar('\n');
	}
	return 0;
}