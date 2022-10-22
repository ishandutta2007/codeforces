#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define ll long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
bool ST;
const int N=1e6+10;
int head[N],to[N<<1],nxt[N<<1],cnt;
void add(int u,int v){
	to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt;
}int n,m,k,col[N],vis[N],fa[N],sz[N],banc[N];
int Fa[N];int get(int x){return fa[x]==x?x:get(fa[x]);}
int sx[N],sy[N],tp,tt[N];
bool merge(int x,int y){
	x=get(x),y=get(y);
	if(x==y)return 0;
	if(sz[x]>sz[y])swap(x,y);
	fa[x]=y,sz[y]+=sz[x],tp++,sx[tp]=x,sy[tp]=y;
	if(get(x)==get(tt[x]))return 1;return 0;
}
void bk(){
	fa[sx[tp]]=sx[tp],sz[sy[tp]]-=sz[sx[tp]],tp--;
}
ll ans;
vector<int> g[N],e[N];
#define pi pair<int,int>
#define fi first
#define se second
vector<pi> h[N];
int cur[N];map<int,int> mp;
void dfs1(int u){
	vis[u]=1;for(int v:e[u])if(col[u]==col[v]){
		merge(u,v+n),merge(u+n,v);
		if(!vis[v])dfs1(v);
	}else if(col[v]<col[u]&&!banc[col[v]])h[col[v]].push_back(pi(u,v)),mp[col[v]]=1;
}
bool ED;
signed main(){
//	printf("%.2lf MB\n",abs(&ED-&ST)/1024.0/1024.0);
	n=read(),m=read(),k=read(),ans=0;
	For(i,1,n)g[col[i]=read()].push_back(i),fa[i]=i,fa[i+n]=i+n,sz[i]=sz[i+n]=1,tt[i]=i+n,tt[i+n]=i;
	For(i,1,m){
		int u=read(),v=read();
		e[u].push_back(v),e[v].push_back(u);
	}For(i,1,k){
		mp.clear();
		for(int u:g[i])if(!vis[u])dfs1(u);
		for(int u:g[i])if(get(u)==get(u+n))banc[i]=1;
		if(!banc[i]){
			int now=tp;
			for(auto ttt:mp){
				int j=ttt.fi,fl=0;
				for(pi E:h[j])fl|=(merge(E.fi,E.se+n)|merge(E.fi+n,E.se));
				ans-=fl;while(tp>now)bk();
			}
		}for(auto ttt:mp)h[ttt.fi].clear();
	}
	int tot=0;For(i,1,k)if(banc[i])tot++;
//	cout<<tot<<endl;
	ans=ans+1ll*(k-tot)*(k-tot-1)/2;
	cout<<ans<<endl;
	return 0;
}