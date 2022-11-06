#include <bits/stdc++.h>
using namespace std;
char ch[1050010];
int main()
{
	bool ok = 1;
	while(gets(ch))
	{
		int n = strlen(ch);
		bool flag = 0;
		for(int i = 0; i < n; i ++)
		{
			if(ch[i] == '#') flag = 1;
			if(ch[i] == ' ') continue;
			break;
		}
		if(flag)
		{
			if(ok == 0) puts("");
			for(int i = 0; i < n; i ++)
				putchar(ch[i]);
			puts("");
			ok = 1;
			continue;
		}
		for(int i = 0; i < n; i ++)
			if(ch[i] == ' ') continue;
			else putchar(ch[i]);
		ok = 0;
	}
    if(!ok) puts("");

	return 0;
}