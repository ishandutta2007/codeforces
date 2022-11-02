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
const int maxn=2e5+10;
int n,m,mod=998244353,a[maxn],w[maxn],f[3005][3005],g[3005][3005],inv[maxn],sum[5];
int Pow(int x,int num)
{
	int sum=1;//cout<<x<<" "<<num<<endl;
	while(num)
	{
		if(num%2==1)sum=sum*x%mod;
		x=x*x%mod;//cout<<x<<endl;
		num=num/2;
	}
	return sum%mod;
}
signed main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)w[i]=read(),sum[a[i]]+=w[i],sum[2]+=w[i];
	for(int i=0;i<=2*m;i++)inv[i]=Pow(sum[2]-m+i,mod-2);
	for(int i=m;i>=0;i--)
	{
		f[i][m-i]=g[i][m-i]=1;
		for(int j=min(m-i-1,sum[0]);j>=0;j--)
		{
			f[i][j]=((sum[1]+i+1)*f[i+1][j]+(sum[0]-j)*f[i][j+1])%mod*inv[i-j+m]%mod;
			g[i][j]=((sum[1]+i)*g[i+1][j]+(sum[0]-j-1)*g[i][j+1])%mod*inv[i-j+m]%mod;//cout<<f[i][j]<<" "<<g[i][j]<<" "<<inv[i-j+m]<<" "<<i-j+m<<endl;
		}
	}
	for(int i=1;i<=n;i++)if(a[i])printf("%d\n",w[i]*f[0][0]%mod);else printf("%d\n",w[i]*g[0][0]%mod);
	return 0;
}