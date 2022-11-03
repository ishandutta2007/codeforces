#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

inline void Min(int &a,int b){if(b<a) a=b;}
inline void Min(ll &a,ll b){if(b<a) a=b;}
inline void Max(int &a,int b){if(b>a) a=b;}
inline void Max(ll &a,ll b){if(b>a) a=b;}

const ll infl=0x3f3f3f3f3f3f3f3fll;
const int P=1000000007;
const int N=200005;

int n,d[N],sum,st[N],inst[N],ans,fac[N];
bool vis[N];

void dfs(int x){
	vis[x]=1;
	st[++*st]=x;
	inst[x]=*st;
	if(inst[d[x]]){
		ans=(ll)ans*(fac[*st-inst[d[x]]+1]-2+P)%P;
		sum-=*st-inst[d[x]]+1;
	}
	else if(!vis[d[x]]) dfs(d[x]);
	--*st;
	inst[x]=0;
}

int main(){
	scanf("%d",&n);
	fac[0]=1;
	ans=1;
	rep(i,1,n) fac[i]=fac[i-1]*2%P;
	rep(i,1,n) scanf("%d",d+i);
	sum=n;
	rep(i,1,n) if(!vis[i]) dfs(i);
	ans=(ll)ans*fac[sum]%P;
	printf("%d\n",ans);
	
}