#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

char s[101000];
int ls, rs;
char lc, rc;
std::vector<char> v[101000];

int main()
{
	int n; scanf("%d", &n);
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		int len = strlen(s);
		for(int j = 0; j < len; j++) v[i].push_back(s[j]);
		if(i == n)
		{
			int now = 0;
			for(int j = 0; j < len; j++)
			{
				if(j == 0 || s[j] == s[j - 1]) now++;
				else
				{
					if(ls == 0) ls = now; 
					now = 1;
				}
				ans = std::max(ans, now);
			}
			if(ls == 0) ls = now; 
			rs = now;
			lc = s[0];
			rc = s[len - 1];
		}
	}
	bool OK = (strlen(s) == ls);
	for(int i = n - 1; i >= 1; i--)
	{
		if(OK)
		{
			int now = rs; ls = 0;
			int len = v[i].size();
			for(int j = 0; j < len; j++)
			{
				if(v[i][j] == rc) now += rs + 1;
				else
				{
					now = rs;
					if(!ls) ls = now;
				}
				ans = std::max(ans, now);
			}
			rs = now;
			if(!ls) ls = now;
			else OK = 0;
		}
		else
		{
			int len = v[i].size();
			for(int j = 0; j < len; j++)
			{
				int sum = 1;
				if(v[i][j] == lc) sum += ls;
				if(v[i][j] == rc) sum += rs;
				ans = std::max(ans, sum);
			}
		}
	}
	printf("%d\n", ans);
}