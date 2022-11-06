#include<cstdio>
#include<cstring>
const int N=1e6+5;
int n,m,cnt,ans;
char s[N];
signed main()
{
	register int i;
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;i++)
		if(s[i]=='8')
			cnt++;
	m=n-cnt;
	while(1)
	{
		if(!cnt)
			break;
		cnt--;
		if(m>=10)
		{
			ans++;
			m-=10;
		}
		else if(m+cnt>=10)
		{
			ans++;
			cnt-=10-m;
			m=0;
		}
		else
			break;
	}
	printf("%d\n",ans);
	return 0;
}