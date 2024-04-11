#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxm=2e5+10,maxn=1e5+10,mod=1e9+7,inv2=(mod+1)>>1;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
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
    inline modint &operator*=(int k){return val=1ll*val*k%mod,*this;}
    inline modint &operator/=(int k){return *this*=((modint(k))^=mod-2);}
    template<class T>friend modint operator+(modint a,T b){return a+=b;}
    template<class T>friend modint operator-(modint a,T b){return a-=b;}
    template<class T>friend modint operator*(modint a,T b){return a*=b;}
    template<class T>friend modint operator/(modint a,T b){return a/=b;}
    friend modint operator^(modint a,int b){return a^=b;}
    friend bool operator==(modint a,int b){return a.val==b;}
    friend bool operator!=(modint a,int b){return a.val!=b;}
    inline bool operator!(){return !val;}
    inline modint operator-(){return val?mod-val:0;}
    inline modint &operator++(int){return *this+=1;}
};
using mi=modint;
struct LB{
	int cnt,len,tot;
	ll d[61];
	inline void clear(){
		cnt=tot=0;
		memset(d,0,sizeof d);
	}
	inline LB(int l_):len(l_){clear();}
	inline bool insert(ll k){
		++tot;
		for(ri i=len;~i;--i)
			if((k>>i)&1){
				if(!d[i]){
					++cnt;
					d[i]=k;
					return true;
				}
				else k^=d[i];
			}
		return false;
	}
	inline ll getrk(ll k){
		ll ret=0,tmp=1;
		for(ri i=0;i<=len;++i)
			if(d[i]){
				if((k>>i)&1)ret+=tmp;
				tmp<<=1;
			}
		return ret;
	}
	inline ll getkth(ll k){
		if(cnt<tot)--k;
		for(ri i=1;i<=len;++i)
			for(ri j=i-1;~j;--j)
				if((d[i]>>j)&1)
					d[i]^=d[j];
		ll ret=0;
		for(ri i=0;i<=len;++i)
			if(d[i]){
				if(k&1)ret^=d[i];
				k>>=1;
			}
		return k?-1:ret;
	}
	inline ll getmx(ll k){
		for(ri i=len;~i;--i)ckmax(k,k^d[i]);
		return k;
	}
}lb(60);
struct edge{
	ll v;
	int to,nxt;
}e[maxm<<1];
int hd[maxn],len;
inline void addedge(int fr,int to,ll v=1){
	e[++len]={v,to,hd[fr]};
	hd[fr]=len;
}
int cnt[61],pcnt;
bool cur[maxn],vis[maxn];
ll val[maxn];
void dfs(int p,ll xsum){
	for(ri i=0;i<61;++i)
		if((xsum>>i)&1)
			++cnt[i];
	cur[p]=vis[p]=true;
	++pcnt;
	val[p]=xsum;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(!vis[e[i].to])dfs(e[i].to,xsum^e[i].v);
		else if(cur[e[i].to])lb.insert(xsum^e[i].v^val[e[i].to]);
	cur[p]=false;
}
int m,n;
mi ans,pw2[61];
signed main(){
	pw2[0]=1;
	for(ri i=1;i<61;++i)pw2[i]=pw2[i-1]+pw2[i-1];
	scanf("%d%d",&n,&m);
	while(m--){
		ri x,y;
		ll z;
		scanf("%d%d%lld",&x,&y,&z);
		addedge(x,y,z),addedge(y,x,z);
	}
	for(ri i=1;i<=n;++i)
		if(!vis[i]){
			memset(cnt,0,sizeof cnt);
			lb.clear();
			pcnt=0;
			dfs(i,0);
			for(ri j=60;~j;--j){
				bool flag=false;
				for(ri k=j;k<61;++k)flag|=((lb.d[k]>>j)&1);
				if(flag)ans+=pw2[j]*pw2[lb.cnt-1]*pcnt*(pcnt-1)*inv2;
				else ans+=pw2[j]*pw2[lb.cnt]*cnt[j]*(pcnt-cnt[j]);
			}
		}
	printf("%d",ans);
	return 0;
}