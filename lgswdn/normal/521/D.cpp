#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=1e6+9,mod=1e9+7;

int ksm(int x,int y,int res=1) {
	x%=mod; if(x==0) return 1;
	for(;y;y>>=1,x=x*x%mod) if(y%2==1) res=res*x%mod;
	return res;
}

struct frac {
	__int128 x,y,z;
	frac(int _x=1,int _y=1) {x=_x, y=_y, z=x*ksm(y,mod-2)%mod;}
	bool operator > (const frac &b) const {return x*b.y>b.x*y;}
} val[N];

int k,n,m,a[N],d1[N],c[N],mxd[N],ww[N];
vi op[N],ans;

bool cmp(const int &a,const int &b) {return d1[a]>d1[b];}
bool cmp2(const int &a,const int &b) {return val[a]>val[b];}
bool cmp3(const int &a,const int &b) {return ww[a]<ww[b];}

signed main() {
	k=read(), n=read(), m=read();
	rep(i,1,k) a[i]=read();
	rep(i,1,n) {
		int t=read(), x=read(), b=read(); d1[i]=b;
		if(!b) continue;
		if(t==1) {if(b>d1[c[x]]) c[x]=i; ww[i]=-1;}
		else if(t==2) op[x].emplace_back(i), mxd[x]=max(mxd[x],b), ww[i]=0;
		else ans.emplace_back(i), val[i]=frac(b), ww[i]=1;
	}
	rep(i,1,k) {
		if(d1[c[i]]>a[i]) op[i].emplace_back(c[i]), d1[c[i]]=d1[c[i]]-a[i];
		sort(op[i].begin(),op[i].end(),cmp);
		int s=a[i];
		for(auto id:op[i]) ans.emplace_back(id),val[id]=frac(s+d1[id],s), s+=d1[id];
	}
	sort(ans.begin(),ans.end(),cmp2);
	int rans=1;
	rep(i,1,k) rans=rans*a[i]%mod;
	vi pans;
	for(auto p:ans) {
		if(m) pans.emplace_back(p), m--;
		else break;
	}
	cout<<pans.size()<<'\n'; sort(pans.begin(),pans.end(),cmp3);
	for(auto x:pans) printf("%lld ",x); puts("");
	return 0;
}