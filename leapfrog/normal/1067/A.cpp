#include<bits/stdc++.h>
using namespace std;const int M=200,P=998244353;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,a[100005];long long f[2][205][3];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	if(a[1]==-1) for(int i=1;i<=M;i++) f[0][i][0]=1;else f[0][a[1]][0]=1;
	for(int i=2;i<=n;i++)
	{
		long long sm=0;
		for(int j=1;j<=200;j++) f[(i+1)&1][j][0]=(a[i]==-1||a[i]==j)?sm:0,(sm+=(f[i&1][j][0]+f[i&1][j][1]+f[i&1][j][2])%P)%=P;
		sm=0;for(int j=1;j<=200;j++) f[(i+1)&1][j][1]=(a[i]==-1||a[i]==j)?(f[i&1][j][0]+f[i&1][j][1]+f[i&1][j][2])%P:0;
		for(int j=200;j>=1;j--) f[(i+1)&1][j][2]=(a[i]==-1||a[i]==j)?sm:0,(sm+=(f[i&1][j][1]+f[i&1][j][2])%P)%=P;
	}
	int res=0;for(int i=1;i<=200;i++) (res+=(f[(n+1)&1][i][1]+f[(n+1)&1][i][2])%P)%=P;
	return printf("%d\n",res),0;
}