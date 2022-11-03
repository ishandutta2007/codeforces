#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
#define LL long long
#define LB long double
#define mod 1000000007
using namespace std;
inline int lowbit(int x){return x&-x;}
inline int ABS(int x){return x<0?-x:x;}
inline LL ABS(LL x){return x<0?-x:x;}
inline void MAX(int &a,int b){if(b>a)a=b;}
inline void MAX(LL &a,LL b){if(b>a)a=b;}
inline void MIN(int &a,int b){if(b<a)a=b;}
inline void MIN(LL &a,LL b){if(b<a)a=b;}
int fast(int x,int v){int ans=1;for(;v;v>>=1,x=(LL)x*x%mod)if(v&1)ans=(LL)ans*x%mod;return ans;}
LL fast(LL x,LL v){LL ans=1;for(;v;v>>=1,x=x*x%mod)if(v&1)ans=ans*x%mod;return ans;}

#define N 100005
#define M 2000005

int n,q,a[N],p[M],prime[M],len,ans[N],son[N],next[N<<1],ed[N<<1],m,d[M],
	stack[M*4],yu[M*4],top,deep[N]; 

void dfs(int x,int fa){
	ans[x]=-1;
	int de=-1;
	for(int c=a[x];c^1;c/=p[c]){
		if(d[p[c]]!=-1 && deep[d[p[c]]]>de){
			de=deep[d[p[c]]];
			ans[x]=d[p[c]];
		}
	}
	int tmp=top;
	for(int c=a[x];c^1;c/=p[c]){
		if(d[p[c]]!=x){
			stack[++top]=p[c];
			yu[top]=d[p[c]];
		}
		d[p[c]]=x;
	}
	for(int j=son[x];j;j=next[j])
		if(ed[j]^fa){
			deep[ed[j]]=deep[x]+1;
			dfs(ed[j],x);
		}
	while(tmp<top){
		d[stack[top]]=yu[top];
		top--;
	}
}

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	
	scanf("%d%d",&n,&q);
	rep(i,2,M-5){
		if(!p[i]){
			p[i]=i;
			prime[++len]=i;
		}
		for(int j=1;j<=len && prime[j]<=p[i] && (LL)prime[j]*i<=M-5;++j)
			p[i*prime[j]]=prime[j];
	}
	rep(i,1,n) scanf("%d",a+i);
	rep(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		next[++m]=son[x],son[x]=m,ed[m]=y;
		next[++m]=son[y],son[y]=m,ed[m]=x;
	}
	rep(i,0,M-5) d[i]=-1;
	dfs(1,0);
	while(q--){
		int opt,x,y;
		scanf("%d%d",&opt,&x);
		if(opt==1) printf("%d\n",ans[x]);
		if(opt==2){
			scanf("%d",a+x);
			dfs(1,0);
			top=0;
		}
	}	
}