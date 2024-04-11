#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10,mod=1e9+7;
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
ll a[maxn],ans;
int n;
void dfs(const map<ll,int> &s,int p,int f){
	map<ll,int>t;
	(ans+=a[p])%=mod;
	++t[a[p]];
	for(const auto &i:s){
		ll tmp=__gcd(i.first,a[p]);
		(ans+=tmp*i.second)%=mod;
		t[tmp]+=i.second;
	}
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f)
			dfs(t,e[i].to,p);
}
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%lld",a+i);
	for(ri i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		addedge(x,y),addedge(y,x);
	}
	dfs(map<ll,int>(),1,0);
	printf("%lld",ans);
	return 0;
}