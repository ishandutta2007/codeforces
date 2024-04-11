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
int n,m,a[maxn*2];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();m=read();n=n*2;
	for(int i=1;i<=m;i++)a[i]=i+1;a[m+1]=1;
	for(int i=m+2;i<=n;i++)a[i]=i;
	if(m%2==0&&m!=0)swap(a[m],a[m+2]),swap(a[m+1],a[m+2]);
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	return 0;
}