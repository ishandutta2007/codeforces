#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxm=1e5+10,maxn=610;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
struct edge{
	int to,nxt;
}e[maxm];
int hd[maxn],ideg[maxn],len,odeg[maxn];
inline void addedge(int fr,int to){
	++ideg[to],++odeg[fr];
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int m,mod,n;
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
mi f[maxn][maxn];
vector<int>s,t;
bool vis[maxn];
void dfs(int p){
	vis[p]=true;
	if(!odeg[p]){f[p][p]=1;return;}
	for(ri i=hd[p];i;i=e[i].nxt){
		if(!vis[e[i].to])dfs(e[i].to);
		for(auto j:t)f[p][j]+=f[e[i].to][j];
	}
}
mi a[maxn][maxn];
inline int det(int siz){
	mi ret=1;
	for(ri i=1;i<=siz;++i){
		if(!a[i][i].val)
			for(ri j=i+1;j<=siz;++j)
				if(a[j][i].val){
					swap(a[i],a[j]);
					ret=-ret;
					break;
				}
		if(!a[i][i].val)return 0;
		mi inv=1/a[i][i];
		for(ri j=i+1;j<=siz;++j){
			mi mul=a[j][i]*inv;
			for(ri k=i;k<=siz;++k)a[j][k]-=a[i][k]*mul;
		}
		ret*=a[i][i];
	}
	return ret.val;
}
signed main(){
	scanf("%d%d%d",&n,&m,&mod);
	while(m--){
		ri x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	for(ri i=1;i<=n;++i){
		if(!ideg[i])s.push_back(i);
		if(!odeg[i])t.push_back(i);
	}
	for(auto i:s)dfs(i);
	for(ri i=0;i<s.size();++i)
		for(ri j=0;j<t.size();++j)
			a[i+1][j+1]=f[s[i]][t[j]];
	printf("%d",det(s.size()));
	return 0;
}