#include<cstdio>
#include<cstring>
const int N=1e6+5;
int n;
char s[N];
inline void solve()
{
	int lst=-1;
	register int i;
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;i++)
		switch(s[i]-'0')
		{
			case 0:
			if(lst==1)
				putchar('0'),lst=0;
			else
				putchar('1'),lst=1;
			break;
			case 1:
			if(lst==2)
				putchar('0'),lst=1;
			else
				putchar('1'),lst=2;
		}
	putchar('\n');
	return;
}
signed main()
{
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}