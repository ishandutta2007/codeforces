#include<cstdio>
#include<algorithm>
#include<map>
#define MAXN 100000
using namespace std;
map<int,int>cnt[2],tmp[2];
long long ans;
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF)
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
}
struct node{
	int v,wt;
	node *next;
}*adj[MAXN+10],edge[MAXN*2+10],*ecnt=edge;
int n,MOD,inv[MAXN+10],sum[MAXN+10],size[MAXN+10],mxs[MAXN+10];
bool vis[MAXN+10];
inline void addedge(int u,int v,int wt){
	node *p=++ecnt;
	p->v=v;
	p->wt=wt;
	p->next=adj[u];
	adj[u]=p;
}
//ax+by=d
//ax+by=bx'+a%by'
//ax+by=ay'+b(x-'a/by')
void exgcd(int a,int b,int&d,int &x,int &y){
	if(!b){
		d=a;
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b,d,y,x);
	y-=a/b*x;
}
void read(){
	Read(n),Read(MOD);
	int i,u,v,wt,d,x,y;
	inv[0]=sum[0]=1;
	for(i=1;i<n;i++){
		sum[i]=1ll*sum[i-1]*10%MOD;
		exgcd(sum[i],MOD,d,x,y);
		inv[i]=(x%MOD+MOD)%MOD;
		Read(u),Read(v),Read(wt);
		u++,v++;
		addedge(u,v,wt);
		addedge(v,u,wt);
	}
}
void find_center(int u,int fa,int &heavy,int tot){
	size[u]=1,mxs[u]=0;
	for(node *p=adj[u];p;p=p->next){
		if(p->v!=fa&&!vis[p->v]){
			find_center(p->v,u,heavy,tot);
			mxs[u]=max(size[p->v],mxs[u]);
			size[u]+=size[p->v];
		}
	}
	mxs[u]=max(mxs[u],tot-size[u]);
	if(mxs[u]<mxs[heavy])
		heavy=u;
}
void dfs(int u,int fa,int fs,int bs,int dep){
	int t=1ll*(MOD-bs)*inv[dep]%MOD;
	if(cnt[0].count(t))
		ans+=cnt[0][t];
	if(cnt[1].count(fs))
		ans+=cnt[1][fs];
	tmp[0][fs]++;
	tmp[1][t]++;
	for(node *p=adj[u];p;p=p->next)
		if(p->v!=fa&&!vis[p->v])
			dfs(p->v,u,(fs+1ll*p->wt*sum[dep])%MOD,(1ll*bs*10+p->wt)%MOD,dep+1);
}
void solve(int u,int tot){
	int heavy=0;
	find_center(u,0,heavy,tot);
	vis[heavy]=1;
	cnt[0].clear();
	cnt[1].clear();
	cnt[0][0]=cnt[1][0]=1;
	for(node *p=adj[heavy];p;p=p->next){
		if(!vis[p->v]){
			tmp[0].clear(),tmp[1].clear();
			dfs(p->v,heavy,p->wt%MOD,p->wt%MOD,1);
			for(map<int,int>::iterator j=tmp[0].begin();j!=tmp[0].end();j++)
				cnt[0][j->first]+=j->second;
			for(map<int,int>::iterator j=tmp[1].begin();j!=tmp[1].end();j++)
				cnt[1][j->first]+=j->second;
		}
	}
	for(node *p=adj[heavy];p;p=p->next){
		if(!vis[p->v]){
			if(size[p->v]<size[heavy])
				solve(p->v,size[p->v]);
			else
				solve(p->v,tot-size[heavy]);
		}
	}
}
int main()
{
	mxs[0]=0x7fffffff;
	read();
	solve(1,n);
	printf("%I64d\n",ans);
}