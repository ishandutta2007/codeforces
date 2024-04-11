#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxm=310,maxn=1e5+10,mod=1e9+7;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
struct edge{
	int v,to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to,int v=1){
	e[++len]={v,to,hd[fr]};
	hd[fr]=len;
}
int cnt,dep[maxn],fa[maxn],rev[maxn],seg[maxn],siz[maxn],son[maxn],top[maxn];
void dfs1(int p,int f){
	dep[p]=dep[f]+1;
	fa[p]=f;
	siz[p]=1;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f){
			dfs1(e[i].to,p);
			siz[p]+=siz[e[i].to];
			if(siz[e[i].to]>siz[son[p]])son[p]=e[i].to;
		}
}
void dfs2(int p,int k){
	seg[p]=++cnt;
	rev[cnt]=p;
	top[p]=k;
	if(son[p]){
		dfs2(son[p],k);
		for(ri i=hd[p];i;i=e[i].nxt)
			if(!top[e[i].to])
				dfs2(e[i].to,e[i].to);
	}
}
#define lowbit(k) ((k)&(-k))
template<typename T>
struct BIT{
	T c[maxn];
	int mx_idx;
	inline void clear(){memset(c,0,sizeof(T)*(mx_idx+1));}
	inline void add(int k,T v){
		for(;k<=mx_idx;k+=lowbit(k))c[k]+=v;
	}
	inline T query(int k){
		T ret=0;
		for(;k;k^=lowbit(k))ret+=c[k];
		return ret;
	}
	inline T query(int l,int r){
		return query(r)-query(l-1);
	}
};
BIT<int>t;
inline int query_chain(int x,int y){
	ri ret=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ret+=t.query(seg[top[x]],seg[x]);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	ret+=t.query(seg[x],seg[y]);
	return ret;
}
int k,m,n,q,r;
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
    inline modint &operator++(){return *this+=1;}
};
using mi=modint;
mi f[maxn][maxm];
int main(){
	scanf("%d%d",&n,&q);
	t.mx_idx=n;
	for(ri i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		addedge(x,y),addedge(y,x);
	}
	dfs1(1,0);
	dfs2(1,1);
	while(q--){
		scanf("%d%d%d",&k,&m,&r);
		vector<int>pre,sp;
		ri tmp;
		while(k--){
			scanf("%d",&tmp);
			sp.push_back(tmp);
		}
		for(auto i:sp)t.add(seg[i],1);
		for(auto i:sp)pre.push_back(query_chain(r,i)-1);
		sort(pre.begin(),pre.end());
		f[0][1]=1;
		for(ri i=1;i<pre.size();++i)
			for(ri j=1;j<=m;++j)
				f[i][j]=f[i-1][j]*max(j-pre[i],0)+f[i-1][j-1];
		mi ans=0;
		for(ri i=1;i<=m;++i)ans+=f[pre.size()-1][i];
		printf("%d\n",ans);
		for(auto i:sp)t.add(seg[i],-1);
	}
	return 0;
}