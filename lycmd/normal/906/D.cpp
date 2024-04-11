#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=500010;
int n,p,q,tot,a[N];
map<int,int>phi;
int mul(int x,int y,int p,int&flg){
	return flg|=1.0*x*y>=p,(__int128)x*y%p;
}
int getphi(int x){
	if(phi.count(x))
		return phi[x];
	int res=x,t=x;
	for(int i=2;i*i<=x;i++)
		if(x%i==0){
			while(x%i==0)x/=i;
			res=res/i*(i-1);
		}
	if(x>1)
		res=res/x*(x-1);
	return phi[t]=res;
}
int qpow(int x,int y,int p){
	int res=1,flg=0;
	for(x=mul(x,1,p,flg);y;y>>=1){
		if(y&1)res=mul(res,x,p,flg);
		x=mul(x,x,p,flg);
	}
	return res+p*flg;
}
int solve(int l,int r,int p){
	return p==1||l>r?1:qpow(a[l],solve(l+1,r,getphi(p)),p);
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>p;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(cin>>q;q--;){
		int l,r;cin>>l>>r;
		cout<<solve(l,r,p)%p<<"\n";
	}
}