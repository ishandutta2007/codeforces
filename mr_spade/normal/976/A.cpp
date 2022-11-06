#include<cstdio>
const int N=105;
int n;
char s[N];
signed main()
{
	int cnt=0;
	register int i;
	scanf("%d",&n);
	scanf("%s",s+1);
	if(n==1&&s[1]=='0')
	{
		puts("0");
		return 0;
	}
	for(i=1;i<=n;i++)
		if(s[i]=='0')
			cnt++;
	putchar('1');
	for(i=1;i<=cnt;i++)
		putchar('0');
	putchar('\n');
	return 0;
}