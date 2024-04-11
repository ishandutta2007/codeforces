//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n,K,sm[4005][4005],f[4005],wh[4005];
int main()
{
	read(n),read(K);for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) read(sm[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) sm[i][j]+=sm[i-1][j]+sm[i][j-1]-sm[i-1][j-1];
	wh[n+1]=n;for(int k=2;k<=K;k++) for(int i=n;i;i--)
	{
		f[i]=-1e9;for(int j=wh[i],v;j<=wh[i+1]&&j<i;j++)
			{v=f[j]-sm[j][j]+sm[j][i];if(v>f[i]) f[i]=v,wh[i]=j;}
	}
	return printf("%d\n",sm[n][n]/2-f[n]),0;
}