#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar();int x=0;bool f=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f)x=-x;return x;
}
const int maxn=1e5+5,maxm=35,mod=1e9+7;
bitset<35>b[35],f;
int n,t,a[maxn],tot=0,p[maxn],id[maxm],sum=0;
void ins()
{
	for(int i=maxm;i>=1;i--)
	{
		if(!f[i])continue;
		if(b[i][i])f=f^b[i];
		else {b[i]=f;tot++;break;}
	}
} 
signed main()
{
	//freopen("D.in","r",stdin);
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();int x=a[i];
		for(int j=2;j*j<=x;j++)
		{
			while(x%(j*j)==0)x=x/(j*j);
		}f.reset();
		for(int j=2;j<=sqrt(x);j++)
		{
			if(x%j==0)
			{
				if(!id[j])id[j]=++sum;f.set(id[j]);x=x/j;//cout<<j<<endl;
			}
		} 
		if(x!=1)
		{
			if(!id[x])id[x]=++sum;f.set(id[x]);//,cout<<x<<endl;
		}ins();
	} tot=n-tot; 
	int ans=1;
	for(int i=1;i<=tot;i++)ans=ans*2,ans%=mod;
	cout<<ans-1;
}