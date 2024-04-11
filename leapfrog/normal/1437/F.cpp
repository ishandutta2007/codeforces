//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n,a[5005],f[5005][5005],s[5005],pre[5005];
const int P=998244353;
int main()
{
	read(n),f[0][0]=1,s[0]=1;for(int i=1;i<=n;i++) read(a[i]),s[i]=1;
	sort(a+1,a+n+1);int r=0;
	for(int i=1,pw=1;i<=n;i++)
	{
		while(a[pw]*2<=a[i]) pw++;
		pre[i]=pw-1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) (f[i][j]+=s[pre[j]])%=P;
		for(int j=1;j<=n;j++) f[i][j]=(f[i][j]+1ll*f[i-1][j]*(max(0,pre[j]-i+2))%P)%P;
		s[0]=0;for(int j=1;j<=n;j++) s[j]=(s[j-1]+f[i][j])%P;
	}
	for(int i=1;i<=n;i++) (r+=f[n][i])%=P;
	return printf("%d\n",r),0;
}