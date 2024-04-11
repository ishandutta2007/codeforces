#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxm=1e3+10,maxq=4e4+10,mod=1e9+7;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
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
    template<class T>friend modint operator^(modint a,T b){return a/=b;}
    template<class T>friend modint operator/(modint a,T b){return a/=b;}
    friend modint operator^(modint a,int b){return a^=b;}
    friend bool operator==(modint a,int b){return a.val==b;}
    friend bool operator!=(modint a,int b){return a.val!=b;}
    inline bool operator!(){return !val;}
    inline modint operator-(){return val?mod-val:0;}
    inline modint &operator++(){return *this+=1;}
};
using mi=modint;
int cnt,l[maxq],m,n,op[maxq],q,r[maxq],v[maxq],w[maxq];
mi p[maxm];
struct segment_tree{
	int l,r;
	vector<int>v;
}t[maxq<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r)return;
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
}
void modify(int p,int l,int r,int v){
	if(t[p].l>r||l>t[p].r)return;
	if(l<=t[p].l&&t[p].r<=r){
		t[p].v.push_back(v);
		return;
	}
	modify(ls(p),l,r,v);
	modify(rs(p),l,r,v);
}
struct bp{
	int f[maxm];
	inline bp(){memset(f,0,sizeof f);}
	inline void operator+=(int id){for(ri i=m;i>=w[id];--i)ckmax(f[i],f[i-w[id]]+v[id]);}
	inline mi calc(){
		mi ret=0;
		for(ri i=1;i<=m;++i)ret+=f[i]*p[i-1];
		return ret;
	}
};
void solve(bp b,int p){
	for(ri i:t[p].v)b+=i;
	if(t[p].l==t[p].r){
		if(op[t[p].l]==3)printf("%d\n",b.calc());
		return;
	}
	solve(b,ls(p));
	solve(b,rs(p));
}
int main(){
	scanf("%d%d",&n,&m);
	p[0]=1,p[1]=1e7+19;
	for(ri i=2;i<=m;++i)p[i]=p[i-1]*p[1];
	for(ri i=1;i<=n;++i)scanf("%d%d",v+i,w+i);
	cnt=n;
	scanf("%d",&q);
	for(ri i=1;i<=n;++i)l[i]=1,r[i]=q;
	for(ri i=1;i<=q;++i){
		scanf("%d",op+i);
		if(op[i]==1){
			l[++cnt]=i,r[cnt]=q;
			scanf("%d%d",v+cnt,w+cnt);
		}
		if(op[i]==2){
			ri pos;
			scanf("%d",&pos);
			r[pos]=i;
		}
	}
	build(1,1,q);
	for(ri i=1;i<=cnt;++i)modify(1,l[i],r[i],i);
	solve(bp(),1);
	return 0;
}