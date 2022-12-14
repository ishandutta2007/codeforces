#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int test, n, ans, res[2222], lst1, lst2, p1, p2;
bool can;
char s[11];
int main()
{
	scanf("%d", &test);
	for (int i = 0; i < (1 << 10); i++)
	{
		lst1 = lst2 = 5;
		p1 = p2 = 0;
		for (int j = 0; j < 10; j++)
		{
			if (j & 1)
			{
				lst2--;
				if (i & (1 << j)) p2++;
			}
			else
			{
				lst1--;
				if (i & (1 << j)) p1++;
			}
			if (p1 + lst1 < p2 || p2 + lst2 < p1 || j == 9) 
			{
				res[i] = j + 1;
				break;
			}
		}
	}
	while(test--)
	{
		scanf("%s", s);
		ans = 10;
		for (int i = 0; i < (1 << 10); i++)
		{
			can = 1;
			for (int j = 0; j < 10; j++)
			{
				if (s[j] != '?' && ((s[j] - '0') << j) != (i & (1 << j))) can = 0;
			}
			if (can)
			{
				ans = min(ans, res[i]);
			}
		}
		printf("%d\n", ans);
	}
	return Accepted;
}