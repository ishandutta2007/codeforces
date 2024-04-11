#include<bits/stdc++.h>
const int N=800005,P=23;
using namespace std;

int n,m;
int cnt,w[N];
int id[N],ct,ps[N];
int lc[P][N],dp[N],ln[N],fa[N];

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx,w;
    bool operator < (edge b){return w<b.w;}
}e[N];int hd[N],S;
void add(int fr,int to,int w){
    e[++S]=(edge){to,hd[fr],w},hd[fr]=S;
}void clear(){
	for(int i=1;i<=n<<1;i++)hd[i]=0;S=0;
}
vector<edge> f,g;
vector<int> v,ed[N],fn[N];
struct dsu{
	int fa[N];
	void init(){for(int i=1;i<=n<<1;i++)fa[i]=i;}
	int gf(int k){return k==fa[k]?k:fa[k]=gf(fa[k]);}
	bool mrg(int x,int y){
		int fx=gf(x),fy=gf(y);
		if(fx==fy)return 0;
		fa[fx]=fy;
		return 1;
	}
}F,G;

void dfs(int k){
	if(k<=n)v.push_back(k);
	id[++ct]=k;
	ps[k]=ct;
	fore(k)
		fa[_to]=k,dp[_to]=dp[k]+1,dfs(_to),id[++ct]=k;
}

int dmin(int x,int y){
	return dp[x]<dp[y]?x:y;
}

void init(){
	ln[0]=-1;
	for(int i=1;i<=ct;i++)
		lc[0][i]=id[i],ln[i]=ln[i>>1]+1;
	for(int i=1;i<P;i++)
		for(int j=1;j<=ct-(1<<i)+1;j++)
			lc[i][j]=dmin(lc[i-1][j],lc[i-1][j+(1<<(i-1))]);
}

int lca(int x,int y){
	x=ps[x],y=ps[y];
	if(x>y)swap(x,y);int z=ln[y-x+1];
	return dmin(lc[z][x],lc[z][y-(1<<z)+1]);
}

int pre[N],con[N],tg[N],vis[N];
bool blvk(){
	int pr=0,cp=0,p2=0,i=0;
	for(int i=1;i<=n;i++)
		con[i]=0;
	for(auto x:v){
		i++;
		int nc=G.gf(x);
		if(nc==cp)pre[i]=p2,pr=i;
		else pre[i]=pr,p2=pr,pr=i,cp=nc;
	}
	for(int i=1;i<=n;i++){
		int x=v[i-1];
		for(auto y:ed[x])vis[y]=1;
		int nw=pre[i];
		while(nw){
			if(!vis[v[nw-1]])break;
			if(nw==1){nw=0;break;}
			if(G.gf(v[nw-2])==G.gf(x))
				nw=pre[nw-1];
			else nw=nw-1;
		}
		for(auto y:ed[x])vis[y]=0;
		if(nw)nw=v[nw-1];
		int y=x;
		x=G.gf(x);
		if(nw!=0&&(con[x]==0||w[lca(con[x],tg[x])]>w[lca(y,nw)]))
			con[x]=nw,tg[x]=y;
	}
	pr=0,cp=0,p2=0,i=0;
	reverse(v.begin(),v.end());
	for(auto x:v){
		i++;
		int nc=G.gf(x);
		if(nc==cp)pre[i]=p2,pr=i;
		else pre[i]=pr,p2=pr,pr=i,cp=nc;
	}
	for(int i=1;i<=n;i++){
		int x=v[i-1];
		for(auto y:ed[x])vis[y]=1;
		int nw=pre[i];
		while(nw){
			if(!vis[v[nw-1]])break;
			if(nw==1){nw=0;break;}
			if(G.gf(v[nw-2])==G.gf(x))
				nw=pre[nw-1];
			else nw=nw-1;
		}
		for(auto y:ed[x])vis[y]=0;
		if(nw)nw=v[nw-1];
		int y=x;
		x=G.gf(x);
		if(nw!=0&&(con[x]==0||w[lca(con[x],tg[x])]>w[lca(y,nw)]))
			con[x]=nw,tg[x]=y;
	}
	int fl=0;
	for(int i=1;i<=n;i++)
		if(con[i]&&G.mrg(i,con[i])){
			fl=1;
//cout<<tg[i]<<' '<<con[i]<<' '<<w[lca(tg[i],con[i])]<<endl;
			add(tg[i],con[i],w[lca(tg[i],con[i])]);
			add(con[i],tg[i],w[lca(tg[i],con[i])]);
		}
	return fl;
}

int fat[P][N],dis[P][N],dep[N];
void df5(int k,int fa,int fw){
	fat[0][k]=fa,dis[0][k]=fw;
	dep[k]=dep[fa]+1;
	for(int i=1;i<P;i++)fat[i][k]=fat[i-1][fat[i-1][k]],dis[i][k]=max(dis[i-1][k],dis[i-1][fat[i-1][k]]);
	fore(k)if(_to!=fa)
		df5(_to,k,e[i].w); 
}
int gdis(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	int res=0; 
	for(int i=P-1;i>=0;i--)
		if(dep[fat[i][x]]>=dep[y])
			res=max(res,dis[i][x]),x=fat[i][x];
	if(x==y)return res;
	for(int i=P-1;i>=0;i--)
		if(fat[i][x]!=fat[i][y]){
			res=max(res,dis[i][x]),res=max(res,dis[i][y]);
			x=fat[i][x],y=fat[i][y];
		}
	res=max(res,dis[0][x]); 
	res=max(res,dis[0][y]); 
	return res;
}

void allclear(){
	f.clear();
	v.clear();
	for(int i=1;i<=n;i++)ed[i].clear();
	clear();
	ct=0;
}

void solve(){
	cin>>n>>m; 
	allclear();
	for(int i=1;i<=m;i++){
		int x,y,z;cin>>x>>y>>z;
		ed[y].push_back(x);
		ed[x].push_back(y);
		f.push_back({x,y,z});
	}
	F.init();
	g=f;
	sort(f.begin(),f.end());
	cnt=n;
	for(int i=0;i<m;i++){
		int x=f[i].to,y=f[i].nx;
		int fx=F.gf(x),fy=F.gf(y);
		if(fx==fy)continue;
		w[++cnt]=f[i].w;
		add(cnt,fx,0),add(cnt,fy,0);
		F.fa[fx]=cnt,F.fa[fy]=cnt;
	}
	dfs(cnt);
	init();
	clear();
//cout<<endl;
	G.init();
//for(auto x:v)cout<<x<<' ';cout<<endl;
	while(blvk());
	df5(1,0,0);
	for(auto x:g)
		cout<<gdis(x.to,x.nx)<<' ';cout<<'\n';
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}