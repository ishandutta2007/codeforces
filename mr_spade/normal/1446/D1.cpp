#include<cstdio>
#include<cstring>
#include<algorithm>
using std::max;
using std::max_element;
const int N=4e5+5;
int n,m,t,ans;
int a[N],cnt[N];
int sum[N],fp[N];
signed main()
{
	int mx,se;
	register int i,j;
	scanf("%d",&n);m=100;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]),cnt[a[i]]++;
	mx=*max_element(cnt+1,cnt+m+1);
	se=0;
	for(i=1;i<=m;i++)
		if(cnt[i]==mx)
			t=i,se++;
	if(se>1)
		return printf("%d\n",n),0;
	for(i=1;i<=m;i++)
	{
		if(t==i)
			continue;
		memset(sum,0,sizeof(int)*(n+1));
		memset(fp,-1,sizeof(int)*(2*n+1));
		sum[0]=n;fp[n]=0;
		for(j=1;j<=n;j++)
		{
			sum[j]=sum[j-1]+(a[j]==t)-(a[j]==i);
			if(~fp[sum[j]])
				ans=max(ans,j-fp[sum[j]]);
			else
				fp[sum[j]]=j;
		}
	}
	printf("%d\n",ans);
	return 0;
}