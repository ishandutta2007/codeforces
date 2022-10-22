#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define SZ(k) k.size()
#define ALL(k) k.begin(),k.end()
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ll;
typedef pair<ll,ll> pll;
template<class T>inline bool chkmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chkmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
inline ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
struct frac{
	ll a,b;
	inline frac(){}
	inline frac(const ll &k):a(k),b(1){}
	inline frac(const ll &a_,const ll &b_){
		ll g=gcd(a_,b_);
		a=a_/g,b=b_/g;
	}
	inline void simp(){
		*this=frac(a,b);
	}
	inline frac operator+(const ll &k){
		return frac(a+k*b,b);
	}
	inline frac operator+(const frac &k){
		return frac(a*k.b+b*k.a,b*k.b);
	}
	inline frac operator-(const ll &k){
		return frac(a-k*b,b);
	}
	inline frac operator-(const frac &k){
		return frac(a*k.b-b*k.a,b*k.b);
	}
	inline frac operator*(const ll &k){
		return frac(a*k,b);
	}
	inline frac operator*(const frac &k){
		return frac(a*k.a,b*k.b);
	}
	inline frac operator/(const ll &k){
		return frac(a,b*k);
	}
	inline frac operator/(const frac &k){
		return frac(a*k.b,b*k.a);
	}
	inline bool operator<(const frac &k)const{
		return a*k.b<b*k.a;
	}
	inline bool operator==(const frac &k){
		return a==k.a&&b==k.b;
	}
};
typedef pair<frac,frac> pff;
pff a[maxn];
typedef pair<int,int> pii;
vector<pii>e[maxn<<1];
vector<pii>ans;
int cnt,n;
bool vis[maxn];
map<frac,int>p;
inline int idx(frac x,frac y){
	frac z=x/y;
	map<frac,int>::iterator it=p.find(z);
	if(it!=p.end())return it->se;
	return p[z]=++cnt;
}
int dfs(int now){
	vector<int>tmp;
	while(e[now].size()){
		pii ele=e[now].back();e[now].pop_back();
		if(vis[ele.se])continue;
		vis[ele.se]=true;
		ri mch=dfs(ele.fi);
		if(mch)ans.pb({ele.se,mch});
		else tmp.pb(ele.se);
	}
	while(tmp.size()>1){
		ri x=tmp.back();tmp.pop_back();
		ri y=tmp.back();tmp.pop_back();
		ans.pb({x,y});
	}
	return tmp.size()?tmp.back():0;
}
signed main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i){
		ll x,y,xx,yy;
		scanf("%llu%llu%llu%llu",&x,&y,&xx,&yy);
		a[i].fi=frac(x,y),a[i].se=frac(xx,yy);
		ri v1=idx(a[i].fi+1,a[i].se),v2=idx(a[i].fi,a[i].se+1);
		e[v1].pb({v2,i}),e[v2].pb({v1,i});
	}
	for(ri i=1;i<=cnt;++i)dfs(i);
	printf("%d\n",SZ(ans));
	for(ri i=0;i<SZ(ans);++i)printf("%d %d\n",ans[i].fi,ans[i].se);
	return 0;
}