#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=110,mod=1e9+7;
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
int dis[maxn][maxn],k,n,t_case;
void init(int p,int f){
	dis[p][0]=1;
	for(ri i=1;i<=n;++i)dis[p][i]=0;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f){
			init(e[i].to,p);
			for(ri j=1;j<=n;++j)dis[p][j]+=dis[e[i].to][j-1];
		}
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
    template<class T>friend modint operator/(modint a,T b){return a/=b;}
    friend modint operator^(modint a,int b){return a^=b;}
    friend bool operator==(modint a,int b){return a.val==b;}
    friend bool operator!=(modint a,int b){return a.val!=b;}
    inline bool operator!(){return !val;}
    inline modint operator-(){return val?mod-val:0;}
    inline modint &operator++(int){return *this+=1;}
};
using mi=modint;
mi ans,f[maxn][maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&k);
		memset(hd,0,sizeof hd);
		len=0;
		for(ri i=1,x,y;i<n;++i){
			scanf("%d%d",&x,&y);
			addedge(x,y),addedge(y,x);
		}
		if(k==2){
			printf("%d\n",n*(n-1)>>1);
			continue;
		}
		ans=0;
		for(ri i=1;i<=n;++i){
			init(i,0);
			for(ri l=0;l<n;++l){
				memset(f,0,sizeof f);
				ri pre=0;
				for(ri j=hd[i];j;j=e[j].nxt){
					f[pre][0]=1;
					for(ri m=k;m;--m)
						f[e[j].to][m]=f[pre][m]+dis[e[j].to][l]*f[pre][m-1];
					pre=e[j].to;
				}
				ans+=f[pre][k];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}