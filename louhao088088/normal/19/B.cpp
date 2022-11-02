#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn=4005;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int w[maxn],v[maxn],n,m,f[maxn],ans;
signed main()
{
	n=read();memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)w[i]=read()+1,v[i]=read(),m=max(m,w[i]);
	f[0]=0;m=m+n;ans=1e18;
	for(int i=1;i<=n;i++)
		for(int j=m;j>=w[i];j--)f[j]=min(f[j-w[i]]+v[i],f[j]);
	for(int i=n;i<=m;i++)ans=min(ans,f[i]);
	cout<<ans<<endl;
	return 0;
}