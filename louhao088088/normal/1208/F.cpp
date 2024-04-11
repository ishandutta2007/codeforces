#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int n,x,f[(1<<22)+1],g[(1<<22)+1],m,s,ans,T,a[1000005];
signed main()
{
	n=read();m=21;memset(f,0,sizeof f);
	s=pow(2,m)-1;ans=0;
	for(int i=1;i<=n;i++)a[i]=read(),g[a[i]]=f[a[i]],f[a[i]]=i;
	for(int i=0;i<m;i++)
		for(int j=0;j<=s;j++)
			if(!(j&(1<<i)))
			{
				if(f[j]>=f[j^(1<<i)])g[j]=max(g[j],f[j^(1<<i)]);
				else g[j]=max(f[j],g[j^(1<<i)]),f[j]=f[j^(1<<i)];
			}
	
	for(int i=1;i<=n-2;i++)
	{
		int p=a[i]^s,c=0;//cout<<p<<endl;
		for(int j=m;j>=0;j--)
			if(p&(1<<j))
			{
				c=c+(1<<j);
				if(g[c]<=i)c-=(1<<j);//ans=max(ans,a[i]+p);
			}
		ans=max(ans,a[i]+c);
		//cout<<ans<<" "<<c<<endl;
	}printf("%d\n",ans);
		
}