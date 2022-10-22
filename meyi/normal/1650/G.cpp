#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=2e5+10,mod=1e9+7;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
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
int dep[maxn],n,s;
inline void bfs(){
	clear(dep,n);
	dep[s]=1;
	queue<int>q;
	q.push(s);
	while(q.size()){
		ri p=q.front();q.pop();
		for(ri i=hd[p];i;i=e[i].nxt)
			if(!dep[e[i].to])
				dep[e[i].to]=dep[p]+1,q.push(e[i].to);
	}
}
int m,t,t_case;
mi f[2][maxn];
vector<int>p[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d%d",&n,&m,&s,&t);
		clear(hd,n),len=0;
		while(m--){
			ri x,y;
			scanf("%d%d",&x,&y);
			addedge(x,y),addedge(y,x);
		}
		bfs();
		clear(f[0],n),clear(f[1],n);
		for(ri i=1;i<=n;++i)p[dep[i]].push_back(i);
		f[0][s]=1;
		for(ri i=1;i<=n;++i){
			for(ri j:p[i])
				for(ri k=hd[j];k;k=e[k].nxt)
					if(dep[e[k].to]==dep[j])
						f[1][e[k].to]+=f[0][j];
			for(ri j:p[i])
				for(ri k=hd[j];k;k=e[k].nxt)
					if(dep[e[k].to]==dep[j]+1)
						f[0][e[k].to]+=f[0][j],f[1][e[k].to]+=f[1][j];
			p[i].clear();
		}
		printf("%d\n",f[0][t]+f[1][t]);
	}
	return 0;
}