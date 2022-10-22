#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
void exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){x=1,y=0;return;}
	exgcd(b,a%b,y,x);
	y-=(a/b)*x;
}
int mod;
struct modint{
	int val;
	inline modint(int val_=0):val(val_){}
	inline modint &operator=(int val_){return val=val_,*this;}
	inline modint &operator+=(const modint &k){return val=val+k.val>=mod?val+k.val-mod:val+k.val,*this;}
	inline modint &operator-=(const modint &k){return val=val-k.val<0?val-k.val+mod:val-k.val,*this;}
    inline modint &operator*=(const modint &k){return val=1ll*val*k.val%mod,*this;}
    inline modint &operator^=(int k){
        modint ret=1,tmp=*this;
        for(;k;k>>=1,tmp*=tmp)if(k&1)ret*=tmp;
        return val=ret.val,*this;
    }
    inline modint &operator/=(modint k){return *this*=(k^=mod-2);}
    inline modint &operator+=(int k){return val=val+k>=mod?val+k-mod:val+k,*this;}
    inline modint &operator-=(int k){return val=val<k?val-k+mod:val-k,*this;}
    inline modint &operator*=(int k){if(k<0)k+=mod;return val=1ll*val*k%mod,*this;}
    inline modint &operator/=(int k){return *this*=((modint(k))^=mod-2);}
    template<class T>friend modint operator+(modint a,T b){return a+=b;}
    template<class T>friend modint operator-(modint a,T b){return a-=b;}
    template<class T>friend modint operator*(modint a,T b){return a*=b;}
    template<class T>friend modint operator/(modint a,T b){return a/=b;}
    friend modint operator^(modint a,int b){return a^=b;}
    friend bool operator==(modint a,modint b){return a.val==b.val;}
    friend bool operator!=(modint a,int b){return a.val!=b;}
    inline bool operator!(){return !val;}
    inline modint operator-(){return val?mod-val:0;}
    inline modint &operator++(){return *this+=1;}
    inline int operator%(int k){return val%k;}
};
using mi=modint;
mi inv10[maxn],pw10[maxn];
struct edge{
	int v,to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to,int v=1){
	e[++len]={v,to,hd[fr]};
	hd[fr]=len;
}
int mx[maxn],rt,siz[maxn],tot;
bool vis[maxn];
void calc_siz(int p,int f){
	mx[p]=0;
	siz[p]=1;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(!vis[e[i].to]&&e[i].to!=f){
			calc_siz(e[i].to,p);
			ckmax(mx[p],siz[e[i].to]);
			siz[p]+=siz[e[i].to];
		}
	ckmax(mx[p],tot-siz[p]);
	if(mx[p]<mx[rt])rt=p;
}
int dep[maxn];
mi dis[maxn],rdis[maxn];
const int hmod=1e6+7;
template<class T1,class T2>
struct hmap{
	struct data{
		T1 id;
		T2 val;
		int nxt;
	}d[maxn];
	int cnt,hd[hmod],len,vis[hmod];
	inline void clear(){
		++cnt;
		len=0;
	}
	void insert(T1 p,T2 v){
		ri tmp=p%hmod;
		if(vis[tmp]!=cnt)hd[tmp]=0,vis[tmp]=cnt;
		for(ri i=hd[tmp];i;i=d[i].nxt)
			if(d[i].id==p){
				d[i].val+=v;
				return;
			}
		d[++len]={p,v,hd[tmp]};
		hd[tmp]=len;
	}
	T2 query(T1 p){
		ri tmp=p%hmod;
		if(vis[tmp]!=cnt)hd[tmp]=0,vis[tmp]=cnt;
		for(ri i=hd[tmp];i;i=d[i].nxt)
			if(d[i].id==p)
				return d[i].val;
		return 0;
	}
};
hmap<mi,int>m;
vector<int>tmp;
void calc_dis(int p,int f){
	m.insert(-dis[p]*inv10[dep[p]],1);
	tmp.push_back(p);
	for(ri i=hd[p];i;i=e[i].nxt)
		if(!vis[e[i].to]&&e[i].to!=f){
			dep[e[i].to]=dep[p]+1;
			dis[e[i].to]=dis[p]*10+e[i].v;
			rdis[e[i].to]=rdis[p]+e[i].v*pw10[dep[p]];
			calc_dis(e[i].to,p);
		}
}
ll ans;
inline void calc_ans(int p,int len1,int len2,int sign){
	dep[p]=len1,dis[p]=rdis[p]=len2;
	m.clear();
	tmp.clear();
	calc_dis(p,0);
	ll sum=0;
	for(auto i:tmp){
		m.insert(-dis[i]*inv10[dep[i]],-1);
		sum+=m.query(rdis[i]);
		m.insert(-dis[i]*inv10[dep[i]],1);
	}
	ans+=sign*sum;
}
void dfs(int p){
	vis[p]=true;
	calc_ans(p,0,0,1);
	for(ri i=hd[p];i;i=e[i].nxt)
		if(!vis[e[i].to]){
			calc_ans(e[i].to,1,e[i].v,-1);
			rt=0,tot=siz[e[i].to];
			calc_siz(e[i].to,0);
			dfs(rt);
		}
}
int n;
signed main(){
	scanf("%d%d",&n,&mod);
	if(mod==1)return printf("%lld",1ll*n*(n-1)),0;
	ll tx=0,ty=0;
	exgcd(10,mod,tx,ty);
	inv10[0]=1,inv10[1]=(tx+mod)%mod;
	pw10[0]=1,pw10[1]=10;
	for(ri i=2;i<=n;++i){
		inv10[i]=inv10[i-1]*inv10[1];
		pw10[i]=pw10[i-1]*10;
	}
	for(ri i=1,x,y,z;i<n;++i){
		scanf("%d%d%d",&x,&y,&z);
		++x,++y,z%=mod;
		addedge(x,y,z),addedge(y,x,z);
	}
	mx[0]=INT_MAX,tot=n;
	calc_siz(1,0);
	dfs(rt);
	printf("%lld",ans);
	return 0;
}