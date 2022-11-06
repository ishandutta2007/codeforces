#include<cstdio>
const int N=1e5+5;
int n;
int a[N];
int tot;
int ii[N],jj[N],xx[N];
inline void solve()
{
	int t=0,x;
	register int i,j;
	scanf("%d",&n);tot=0;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]),t+=a[i];
	if(t%n)
		return puts("-1"),void();
	t/=n;
	for(i=2;i<=n;i++)
	{
		ii[++tot]=1;jj[tot]=i;xx[tot]=(i-a[i]%i)%i;
		a[1]-=xx[tot];a[i]+=xx[tot];
		ii[++tot]=i;jj[tot]=1;xx[tot]=a[i]/i;
		a[i]-=xx[tot]*i;a[1]+=xx[tot]*i;
	}
	for(i=2;i<=n;i++)
	{
		ii[++tot]=1;jj[tot]=i;xx[tot]=t;
		a[1]-=t;a[i]+=t;
	}
	printf("%d\n",tot);
	for(i=1;i<=tot;i++)
		printf("%d %d %d\n",ii[i],jj[i],xx[i]);
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