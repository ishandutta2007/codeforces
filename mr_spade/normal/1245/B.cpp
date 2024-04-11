#include<cstdio>
#include<cstring>
const int N=1e6+5;
int n,a,b,c,cnt;
char s[N],t[N];
inline void solve()
{
	register int i;
	scanf("%d%d%d%d",&n,&a,&b,&c);cnt=0;
	scanf("%s",s+1);
	memset(t+1,0,sizeof(char)*(n+1));
	for(i=1;i<=n;i++)
		switch(s[i])
		{
			case 'R':
			if(b)
				t[i]='P',b--,cnt++;
			break;
			case 'P':
			if(c)
				t[i]='S',c--,cnt++;
			break;
			case 'S':
			if(a)
				t[i]='R',a--,cnt++;
			break;
		}
	if((n+1)/2>cnt)
		return puts("NO"),void();
	puts("YES");
	for(i=1;i<=n;i++)
		if(t[i]==0)
		{
			if(a)
				t[i]='R',a--;
			else if(b)
				t[i]='P',b--;
			else
				t[i]='S',c--;
		}
	printf("%s\n",t+1);
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