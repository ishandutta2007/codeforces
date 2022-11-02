#include<bits/stdc++.h>
using namespace std;
static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
const int maxn=1e5+5;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
struct node
{
	int v,id;
}a[maxn],b[maxn];
int n,m,sum[maxn],sum2[maxn],g,ans1,ans2,cnt1=0,cnt2=0,ans;
bool cmp(node a,node b)
{
	return a.v>b.v;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		g=read();if(g==1)a[++cnt1].v=read(),a[cnt1].id=i;
		else b[++cnt2].v=read(),b[cnt2].id=i;
	}
	sort(a+1,a+cnt1+1,cmp);
	sort(b+1,b+cnt2+1,cmp);
	for(int i=1;i<=cnt1;i++)
		sum[i]=sum[i-1]+a[i].v;
	for(int i=1;i<=cnt2;i++)
		sum2[i]=sum2[i-1]+b[i].v;
	if(cnt1+cnt2*2<=m)
	{
		cout<<sum[cnt1]+sum2[cnt2]<<endl;
		for(int i=1;i<=n;i++)cout<<i<<" ";
		return 0;
	}
	for(int i=0;i<=min(cnt1,m);i++)
	{
		int j=min(cnt2,(m-i)/2);
		if(i+j*2>m)continue;
		if(sum[i]+sum2[j]>ans)ans=sum[i]+sum2[j],ans1=i,ans2=j;
	}
	cout<<ans<<endl;
	for(int i=1;i<=ans1;i++)
		printf("%d ",a[i].id);
	for(int i=1;i<=ans2;i++)
		printf("%d ",b[i].id);
	return 0;
}