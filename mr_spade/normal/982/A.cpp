#include<cstdio>
const int N=1005;
int n;
char s[N];
signed main()
{
	register int i;
	scanf("%d%s",&n,s+1);
	s[0]=s[n+1]='0';
	for(i=1;i<=n+1;i++)
	{
		if(i>=2&&s[i]=='1'&&s[i-1]=='1')
			return puts("No"),0;
		if(i>=2&&s[i]=='0'&&s[i-1]=='0'&&s[i-2]=='0')
			return puts("No"),0;
	}
	puts("Yes");
	return 0;
}