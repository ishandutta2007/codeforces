#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=1e6+10;
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int clr,cnt,dfn[maxn],id[maxn],low[maxn],st[maxn],tp;
bool vis[maxn];
void tarjan(int p){
	dfn[p]=low[p]=++cnt;
	st[++tp]=p;
	vis[p]=true;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(!dfn[e[i].to])tarjan(e[i].to),ckmin(low[p],low[e[i].to]);
		else if(vis[e[i].to])ckmin(low[p],dfn[e[i].to]);
	if(dfn[p]==low[p]){
		++clr;
		int k;
		do{
			k=st[tp--];
			id[k]=clr;
			vis[k]=false;
		}while(k!=p);
	}
}
int a[maxn],m,n,t_case;
vector<int>v[maxn];
int main(){
	scanf("%d",&n);
	if(n&1){
		puts("Second");
		fflush(stdout);
		for(ri i=1;i<=(n<<1);++i)scanf("%d",a+i),v[a[i]].push_back(i);
		auto getid=[&](int k,bool t){return a[k]+(k==v[a[k]][t]?n:0);};
		for(ri i=1;i<=n;++i){
			addedge(getid(i,1),getid(i+n,0));
			addedge(getid(i+n,1),getid(i,0));
		}
		for(ri i=1;i<=(n<<1);++i)
			if(!dfn[i])
				tarjan(i);
		ll sum=0;
		for(ri i=1;i<=n;++i){
			assert(id[i]!=id[i+n]);
			sum+=v[i][id[i]>id[i+n]];
		}
		bool flag=(sum%(n<<1)!=0);
		for(ri i=1;i<=n;++i)printf("%d ",v[i][(id[i]>id[i+n])^flag]);
	}
	else{
		puts("First");
		for(ri i=1;i<=n;++i)printf("%d ",i);
		for(ri i=1;i<=n;++i)printf("%d ",i);
	}
	fflush(stdout);
	return 0;
}