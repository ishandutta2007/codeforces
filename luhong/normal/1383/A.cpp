#include <iostream>
#include <cstdio>
#define MN 201000

char s[MN], t[MN];
 
int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int n; scanf("%d%s%s", &n, s + 1, t + 1);
		bool ok = 0;
		for(int i = 1; i <= n; i++)
		{
			if(s[i] > t[i]) {ok = 1; break;}
		}
		if(ok) {puts("-1"); continue;}
		int ans = 0;
		for(char i = 'a'; i <= 't'; i++)
		{
			bool ok = 0;
			char Min = 'u';
			for(int j = 1; j <= n; j++)
			{
				if(s[j] == i && s[j] != t[j]) Min = std::min(Min, t[j]);
			}
			if(Min == 'u') continue;
			for(int j = 1; j <= n; j++)
				if(s[j] == i && s[j] != t[j]) s[j] = Min;
			ans++;
		}
		printf("%d\n", ans);
	}
}