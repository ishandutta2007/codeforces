#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring> 

char s[101000]; int cnt[27];
int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		memset(cnt, 0, sizeof(cnt));
		scanf("%s", s);
		int len = strlen(s);
		for(int i = 0; i < len; i++) cnt[s[i] - 'a']++;
		bool ok = 0;
		for(int i = 1; i < len; i++)
		{
			if(s[i] != s[i - 1]) {ok = 1; break;}
		}
		if(len == 1) ok = 0;
		if(!ok) puts("-1");
		else
		{
			for(int i = 0; i < 26; i++)
			{
				for(int j = 1; j <= cnt[i]; j++) printf("%c", i + 'a');
			}
			puts("");
		}
	}
	return 0;
}