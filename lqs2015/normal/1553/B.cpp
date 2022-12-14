#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int test, n, m, cur;
char s[555], t[1111];
bool flg;
bool check(int x, int y)
{
	int pos = x;
	for (int i = y; i < m; i++)
	{
		if (pos < 0 || s[pos] != t[i]) return 0;
		pos--;
	}
	return 1;
}
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%s%s", s, t);
		n = strlen(s);
		m = strlen(t);
		flg = 0;
		for (int i = 0; i < n; i++)
		{
			cur = 0;
			for (int j = i; j < n; j++)
			{
				if (s[j] != t[cur]) break;
				cur++;
				if (check(j - 1, cur)) flg = 1;
				if (cur >= m) break;
			}
		}
		if (flg) printf("YES\n");
		else printf("NO\n");
	}
	return Accepted;
}