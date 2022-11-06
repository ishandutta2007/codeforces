#include<cstdio>
#include<algorithm>
using std::max;
using std::min;
const int N=5005,M=20005;
int n,m,k;
int a[M],b[M];
int cnt[N],d[N];
inline int dist(int x,int y)
{
	return ((y-x)%n+n)%n;
}
signed main()
{
	int res,res2;
	register int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		d[i]=n;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		cnt[a[i]]++;d[a[i]]=min(d[a[i]],dist(a[i],b[i]));
	}
	for(i=1;i<=n;i++)
		k=max(k,cnt[i]);
	for(i=1;i<=n;i++)
	{
		res=(k-1)*n;res2=0;
		for(j=1;j<=n;j++)
			if(j!=i&&cnt[j]==k-1&&d[j]<n&&dist(j,i)<d[j])
				res2=max(res2,d[j]-dist(j,i));
		for(j=1;j<=n;j++)
			if(cnt[j]==k)
				res2=max(res2,dist(i,j)+d[j]);
		printf("%d ",res+res2);
	}
	putchar('\n');
	return 0;
}