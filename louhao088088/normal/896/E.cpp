#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;
static char buf[1000000],*p1=buf,*p2=buf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
const int maxn=1e5+5;;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int n,m,a[maxn],l,r,opt,ans=0,x;
signed main()
{
	n=read(),m=read();
	for(re int i=1;i<=n;i++)a[i]=read();
	for(re int i=1;i<=m;i++)
	{
		opt=read(),l=read(),r=read(),x=read();ans=0;
		if(opt==1)for(re int j=l;j<=r;j++) a[j]-=(a[j]>x)?x:0;
		else 
		{
			for(re int j=l;j<=r;j++) ans+=!(a[j]-x);
			printf("%d\n",ans);
		}
	}
	return 0;
}