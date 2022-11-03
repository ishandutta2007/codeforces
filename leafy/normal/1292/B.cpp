#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
const int N=1e6+5,mod=998244353;
inline int pls(int a,int b){a+=b;return a>=mod?a-mod:a;}
inline int dec(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return 1ll*a*b%mod;}
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=mul(a,a)) if(b&1) res=mul(res,a);
	return res;
}
ll x0,y0,ax,ay,bx,by,xs,ys,t;
ll ans=1;
vector<pair<ll,ll> > G;
int main(){
	cin>>x0>>y0>>ax>>ay>>bx>>by>>xs>>ys>>t;
	G.push_back({x0,y0});
	while(1) {
		x0=ax*x0+bx;y0=ay*y0+by;
		if(x0-xs+y0-ys>t||x0>2e16||y0>2e16) break;
		G.push_back({x0,y0});
	}
	ll ans=0;
	for(int i=0;i<G.size();i++){
		pair<ll,ll> pre(xs,ys);ll s=0,res=0;
		for(int j=i;j>=0;j--) {
			pair<ll,ll> now=G[j];
			s+=abs(now.X-pre.X)+abs(now.Y-pre.Y);
			if(s>t) break;
			res++;pre=now;
		}
		ans=max(ans,res);
		res=s=0;pre={xs,ys};
		for(int j=i;j<G.size();j++) {
			pair<ll,ll> now=G[j];
			s+=abs(now.X-pre.X)+abs(now.Y-pre.Y);
			if(s>t) break;
			res++;pre=now;
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}