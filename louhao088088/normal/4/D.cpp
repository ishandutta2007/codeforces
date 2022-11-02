#include<bits/stdc++.h>
using namespace std;
static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
const int maxn=5e3+5;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
struct node{
	int x,y,id;bool operator <(const node&a)const{return x<a.x;}
}a[maxn];
int n,m,b,c,f[maxn],g[maxn],x,y,ans,d,res[maxn],cnt=0;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();b=read(),c=read();
	for(int i=1;i<=n;i++)a[i].x=read(),a[i].y=read(),a[i].id=i;
	sort(a+1,a+n+1);memset(f,0x80,sizeof f);g[0]=0;f[0]=0;a[0].x=b,a[0].y=c;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i].x>a[j].x&&a[i].y>a[j].y&&f[i]<=f[j])f[i]=f[j]+1,g[i]=j;
		}
		if(ans<f[i])ans=f[i],d=i;
	}
	printf("%d\n",ans);
	while(d>0)res[++cnt]=a[d].id,d=g[d];
	for(int i=cnt;i>=1;i--)printf("%d ",res[i]);
	return 0;
}