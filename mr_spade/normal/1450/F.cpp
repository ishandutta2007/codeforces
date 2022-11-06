#include<cstdio>
#include<cstring>
const int N=1e5+5;
int n,sum;
int a[N],cnt[N];
int b0,b1;
inline void solve()
{
	int fl=1,x;
	register int i;
	scanf("%d",&n);sum=0;
	memset(cnt+1,0,sizeof(int)*n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=2;i<=n;i++)
		if(a[i]==a[i-1])
			sum++,cnt[a[i]]++;
	for(i=1;i<=n;i++)
		fl&=(cnt[i]*2<=sum);
	if(fl)
	{
		printf("%d\n",sum);
		return;
	}
	for(i=1;i<=n;i++)
		if(cnt[i]*2>sum)
		{
			x=i;
			break;
		}
	b0=b1=0;
	if(a[1]!=x)
		b0++;
	if(a[n]!=x)
		b0++;
	for(i=2;i<=n;i++)
		if(a[i]==a[i-1]&&a[i]!=x)
			b0++;
	for(i=2;i<=n;i++)
		if(a[i-1]!=x&&a[i]!=x&&a[i]!=a[i-1])
			b1++;
	if(cnt[x]<=b0)
		printf("%d\n",sum);
	else if(cnt[x]<=b0+b1)
		printf("%d\n",sum+(cnt[x]-b0));
	else
		puts("-1");
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