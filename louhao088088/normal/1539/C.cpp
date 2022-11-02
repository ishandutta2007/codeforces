#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+5;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int n,m,sum[maxn],x,y,len,a[maxn],p[maxn],cnt=0,ans,k;
signed main()
{
	n=read(),k=read();x=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
		if(a[i]-a[i-1]>x)p[++cnt]=(a[i]-a[i-1]-1)/x;
	sort(p+1,p+cnt+1);ans=cnt+1;
	for(int i=1;i<=cnt;i++)
		if(k>=p[i])ans--,k-=p[i];
	cout<<ans;
	return 0;
}