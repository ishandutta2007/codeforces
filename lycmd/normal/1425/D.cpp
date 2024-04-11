#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333,M=1010,MOD=1000000007;
int n,m,r,ans,x[N],y[N],v[N],s[M][M];
namespace combinatorics{
	int fac[N],inv[N];
	int qpow(int x,int y){
		return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
	}
	int C(int n,int m){
		return n<m||m<0?0:fac[n]*inv[m]%MOD*inv[n-m]%MOD;
	}
	void init(){
		fac[0]=fac[1]=inv[0]=inv[1]=1;
		for(int i=2;i<N;i++)
			fac[i]=fac[i-1]*i%MOD;
		inv[N-1]=qpow(fac[N-1],MOD-2);
		for(int i=N-1;i>1;i--)
			inv[i-1]=inv[i]*i%MOD;
	}
}
using namespace combinatorics;
int sum(int xl,int yl,int xr,int yr){
	xl=max(xl,1ll),yl=max(yl,1ll);
	xr=min(xr,1000ll),yr=min(yr,1000ll);
	return xl>xr||yl>yr?0:s[xr][yr]-s[xr][yl-1]-s[xl-1][yr]+s[xl-1][yl-1];
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>r,init();
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i]>>v[i],s[x[i]][y[i]]++;
	for(int i=1;i<M;i++)
		for(int j=1;j<M;j++)
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			int a=sum(max(x[i],x[j])-r,max(y[i],y[j])-r,
				min(x[i],x[j])+r,min(y[i],y[j])+r),
				b=sum(x[i]-r,y[i]-r,x[i]+r,y[i]+r)-a,
				c=sum(x[j]-r,y[j]-r,x[j]+r,y[j]+r)-a,
				s1=(C(n,m)-C(n-a,m)+MOD)%MOD,
				s2=(C(n-a,m)-C(n-a-b,m)-C(n-a-c,m)+C(n-a-b-c,m)+2*MOD)%MOD;
			ans=(ans+(i==j?v[i]*v[i]%MOD*s1%MOD:
				2*v[i]%MOD*v[j]%MOD*(s1+s2)%MOD))%MOD;
		}
	cout<<ans<<"\n";
}//