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
int n;char v[1005];double a[1005][1005],rs[1005],fv[1005];
int main()
{
	read(n);for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%lf",a[i]+j),a[i][j]/=100;
	v[n]=1;if(n==1) puts("0");else for(int i=1;i<n;i++) rs[i]=1,fv[i]=1-a[i][n];
	for(int xtw=1;xtw<n;xtw++)
	{
		double mn=1e18;int s=0;
		for(int i=1;i<=n;i++) if(!v[i]&&rs[i]/(1-fv[i])<mn) mn=rs[i]/(1-fv[i]),s=i;
		if(s==1) return printf("%.10lf\n",mn),0;else v[s]=1;
		for(int i=1;i<=n;i++) rs[i]+=rs[s]/(1-fv[s])*a[i][s]*fv[i],fv[i]*=1-a[i][s];
	}
}