#include<cstdio>
#include<cstdlib>
#define abs(x) ((x)<0?-(x):(x))
const int N=1e5+5;
int n,k;
char s[100];
int dis[N],w[N];
inline int find(int x)
{
	if(dis[x]==x)
		return x;
	int d=find(dis[x]);
	w[x]^=w[dis[x]];
	return dis[x]=d;
}
inline void merge(int x,int y,int z)
{
	int fx=find(x),fy=find(y);
	if(fx==fy&&(w[x]^w[y])!=z)
		puts("0"),exit(0);
	if(fx==fy)
		return;
	w[fx]=w[x]^w[y]^z;dis[fx]=fy;
	return;
}
inline int l(int x,int y)
{
	return abs(x-y);
}
inline int r(int x,int y)
{
	return n-1-l(x,n-1-y);
}
signed main()
{
	int ans=1,cnt=0,x,y;
	register int i;
	scanf("%d%d",&n,&k);
	for(i=0;i<=n;i++)
		dis[i]=i;
	while(k--)
	{
		scanf("%d%d%s",&x,&y,s);x--;y--;
		if(l(x,y)>=2)
			merge(l(x,y)-2,r(x,y),s[0]=='o');
		else
			merge(n,r(x,y),s[0]=='o');
	}
	for(i=0;i<=n;i++)
		if(dis[i]==i)
			cnt++;
	for(i=0;i<cnt-1;i++)
		ans=(ans+ans)%1000000007;
	printf("%d\n",ans);
	return 0;
}