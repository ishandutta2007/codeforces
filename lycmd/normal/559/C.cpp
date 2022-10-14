#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
int const N=2010,M=200010,MOD=1000000007;
int h,w,n,fac[M],inv[M],f[N];
pair<int,int>p[N];
int qpow(int x,int y){
    return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
}
int C(int n,int m){
	return n<m?0:fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>h>>w>>n;
	for(int i=0;i<n;i++)
        cin>>p[i].x>>p[i].y;
	sort(p,p+n);
	p[n].x=h;p[n].y=w;
	for(int i=0;i<M;i++)
		fac[i]=!i?1:fac[i-1]*i%MOD;
	inv[M-1]=qpow(fac[M-1],MOD-2);
	for(int i=M-1;i;i--)
		inv[i-1]=inv[i]*i%MOD;
	for(int i=0;i<=n;i++){
		f[i]=C(p[i].x+p[i].y-2,p[i].x-1);
		for(int j=0;j<i;j++)
			if(p[j].y<=p[i].y)
				f[i]=(f[i]-f[j]*C(p[i].x-p[j].x+p[i].y-p[j].y,p[i].x-p[j].x)%MOD+MOD)%MOD;
	}
	cout<<f[n]<<"\n";
}