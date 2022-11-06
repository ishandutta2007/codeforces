#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int r[101000],k[101000];
int n,l,w;
int t1=0,t2=0;
long long Abs(long long x){return x<0?-x:x;}
int ef(int L,int R,int K)
{
	while(L<R)
	{
		int mid=L+R>>1;
		long long T=(r[mid]+l-k[K]);
		if(Abs(T+k[K]*2)-w*T<0)R=mid;
		else L=mid+1;
	}
	return R;
}
int main()
{
	scanf("%d%d%d",&n,&l,&w);
	for(int i=1;i<=n;i++)
	{
		int x,v;scanf("%d%d",&x,&v);
		if(v==1)k[++t1]=x;
		if(v==-1)r[++t2]=x;
	}
	sort(r+1,r+t2+1);long long ans=0;
	for(int i=1;i<=t1;i++)
	{
		int u=lower_bound(r+1,r+t2+1,k[i])-r;
		int x=ef(u,t2+1,i);
		ans+=t2-x+1;
	}
	printf("%lld",ans);return 0;
 }