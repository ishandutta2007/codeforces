#include<cstdio>
int cnt[100];
char s[1000005];
signed main()
{
	int n;
	register int i;
	scanf("%d%s",&n,s);
	if(n==1)
	{
		puts("Yes");
		return 0;
	}
	for(i=0;s[i];i++)
		cnt[s[i]-'a']++;
	for(i=0;i<26;i++)
		if(cnt[i]>1)
		{
			puts("Yes");
			return 0;
		}
	puts("No");
}