#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10,mod=998244353;
int a[maxn],m,n,t_case;
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
mi ans[maxn];
bool flag;
int cur,g;
vector<int>e[maxn];
bool dfs(int p,int f){
	ri tmp=e[p].size();
	for(auto i:e[p])
		if(i!=f)
			tmp-=dfs(i,p);
	if(tmp%cur&&(tmp-1)%cur)flag=false;
	if(tmp%cur==0){
		g=__gcd(g,tmp);
		return 1;
	}
	else{
		g=__gcd(g,tmp-1);
		return 0;
	}
}
signed main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i){
			ans[i]=0;
			e[i].clear();
		}
		for(ri i=1,x,y;i<n;++i){
			scanf("%d%d",&x,&y);
			e[x].push_back(y),e[y].push_back(x);
		}
		m=n-1;
		for(ri i=2;i<=m;++i)
			if(m%i==0){
				cur=i,flag=true,g=0;dfs(1,0);
				if(flag)ans[g]=1;
				while(m%i==0)m/=i;
			}
		ans[1]=mi(2)^(n-1);
		for(ri i=2;i<=n;++i)ans[1]-=ans[i];
		for(ri i=1;i<=n;++i)printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}