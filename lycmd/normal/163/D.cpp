#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N=505;
int t,n,xa;
ll v,ans,xb,c,k,p[N],w[N];
ll qpow(ll x,int y){
	return y?qpow(x*x,y>>1)*(y&1?x:1):1;
}
void dfs2(int x,ll b,const ll&a,const ll&lim){
	if(b>lim)return;
	if(x>n){
		c=v/a/b,k=(a*b+a*c+b*c);
		if(k<ans)ans=k,xa=a,xb=b;
		return;
	}
	if(w[x])w[x]--,dfs2(x,b*p[x],a,lim),w[x]++;
	dfs2(x+1,b,a,lim);
}
void dfs1(int x,ll a,const ll&lim){
	if(a>lim)return;
	if(x>n){
		if(v/a+2*a*sqrtl(v/a)>=ans)return;
		dfs2(1,1,a,sqrtl(v/a));
		return;
	}
	if(w[x])w[x]--,dfs1(x,a*p[x],lim),w[x]++;
	dfs1(x+1,a,lim);
}
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n,v=1;
		for(int i=1;i<=n;i++)
			cin>>p[i]>>w[i],v*=qpow(p[i],w[i]);
		ans=LLONG_MAX,dfs1(1,1,cbrtl(v));
		cout<<ans*2<<" "<<xa<<" "<<xb<<" "<<v/xa/xb<<"\n";
	}
}