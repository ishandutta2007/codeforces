#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>

char s[101000];
int main()
{
	int len; scanf("%d%s", &len, s + 1);
	bool ok = 1; int st = 0;
	int cnt = (s[1] == 'G');
	for(int i = 2; i <= len; i++)
	{
		cnt += (s[i] == 'G');
		if(s[i] == 'G' && s[i - 1] == 'S' && st == 0)
		{
			st = 1;
		}
		else if(s[i] == 'S' && s[i - 1] == 'G' && st == 1)
		{
			st = 2;
		}
		else if(s[i] == 'S' && s[i - 1] == 'G' || s[i] == 'G' && s[i - 1] == 'S') ok = 0;
	}
	int ans = 0;
	if(ok == 1)
	{
		printf("%d\n", cnt);
	}
	else
	{
		for(int i = 1; i <= len; i++)
		{
			if(s[i] == 'S')
			{
				int len1 = 0, len2 = 0;
				for(int j = i - 1; j >= 1; j--)
				{
					if(s[j] == 'S') break;
					len1++;
				}
				for(int j = i + 1; j <= len; j++)
				{
					if(s[j] == 'S') break;
					len2++;
				}
				ans = std::max(ans, std::min(cnt, len1 + len2 + 1));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}