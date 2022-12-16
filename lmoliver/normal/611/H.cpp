#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,tn;
const int X=6;
int cnt[X+1][X+1]={0};
int e[X+1];
int ten[X+1]={(int)1e0,(int)1e1,(int)1e2,(int)1e3,(int)1e4,(int)1e5,(int)1e6};
const int N=100;
struct UFS{
	int fa[N];
	stack<pair<int,int> > ops;
	void init(){
		for(int i=0;i<N;i++){
			fa[i]=-1;
		}
	}
	int find(int x){
		return fa[x]<0?x:find(fa[x]);
	}
	bool merge(int x,int y){
		x=find(x);
		y=find(y);
		if(x==y){
			return false;
		}
		if(-fa[x]<-fa[y]){
			swap(x,y);
		}
		ops.push(make_pair(x,fa[x]));
		ops.push(make_pair(y,fa[y]));
		fa[x]+=fa[y];
		fa[y]=x;
		return true;
	}
	void undo(){
		pair<int,int> p1=ops.top();
		ops.pop();
		pair<int,int> p2=ops.top();
		ops.pop();
		fa[p1.first]=p1.second;
		fa[p2.first]=p2.second;
	}
};
UFS ufs;
int es[N][N]={0};
void init(){
	tn=n;
	int _n=n;
	for(int i=1;i<=X;i++){
		e[i]=min(ten[i]-ten[i-1],_n);
		_n-=e[i];
		if(_n==0){
			n=i;
			break;
		}
	}
	ufs.init();
}
void gg(){
	puts("-1");
	exit(0);
}
bool ie[X][X]={false};
const int INF=1e7;
int dis[N];
bool vis[N];
int v;
void bfs(int u){
	// cerr<<"bfs "<<u<<endl;
	memset(vis,false,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	queue<int> q;
	vis[u]=true;
	dis[u]=0;
	q.push(u);
	// cerr<<"bfs @ "<<u<<" "<<dis[u]<<endl;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<=v;i++){
			if(!vis[i]&&es[x][i]>0){
				vis[i]=true;
				dis[i]=dis[x]+1;
				q.push(i);
				// cerr<<"bfs @ "<<i<<" "<<dis[i]<<endl;
			}
		}
	}
}
int dfs(int x,int f){
	// cerr<<"dfs "<<x<<" "<<f<<endl;
	// assert(f>=0);
	if(x==v){
		// cerr<<"reached"<<endl;
		return f;
	}
	else{
		int ans=0;
		for(int i=0;i<=v;i++){
			if(es[x][i]>0&&dis[x]+1==dis[i]){
				int da=dfs(i,min(es[x][i],f));
				// cerr<<"qaq "<<i<<" "<<x<<" "<<da<<endl;
				// cerr<<"es["<<x<<"]["<<i<<"] = "<<es[x][i]<<endl;
				// cerr<<"es["<<i<<"]["<<x<<"] = "<<es[i][x]<<endl;
				ans+=da;
				f-=da;
				es[x][i]-=da;
				es[i][x]+=da;
				assert(es[i][x]<=INF);
				if(f==0){
					break;
				}
			}
		}
		return ans;
	}
}
int flow(){
	// cerr<<"flow"<<endl;
	int ans=0;
	do{
		bfs(0);
		if(dis[v]>=INF){
			break;
		}
		ans+=dfs(0,INF);
	}
	while(true);
	return ans;
}
int cur[N]={0};
void ge(int u,int v){
	printf("%d %d\n",u,v);
}
void doit(){
	// cerr<<"doit"<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(ie[i][j]){
				// cerr<<"edge "<<i<<", "<<j<<endl;
			}
		}
	}
	int id=n;
	v=n+n*(n+1)/2+1;
	for(int i=0;i<=v;i++){
		for(int j=0;j<=v;j++){
			es[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		es[0][i]=e[i]-1;
		// cerr<<"es["<<0<<"]["<<i<<"] = "<<e[i]-1<<endl;
		for(int j=i;j<=n;j++){
			id++;
			es[i][id]=INF;
			// cerr<<"es["<<i<<"]["<<id<<"] = INF"<<endl;
			if(i!=j){
				es[j][id]=INF;
				// cerr<<"es["<<j<<"]["<<id<<"] = INF"<<endl;
			}
			es[id][v]=cnt[i][j]-(ie[i][j]?1:0);
			// cerr<<"es["<<id<<"]["<<v<<"] = "<<(cnt[i][j]-(ie[i][j]?1:0))<<endl;
		}
	}
	int ans=flow();
	// cerr<<"ans = "<<ans<<endl;
	if(ans==tn-n){
		for(int i=1;i<=n;i++){
			cur[i]=ten[i-1];
		}
		id=n;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(ie[i][j]){
					ge(ten[i-1],ten[j-1]);
				}
				id++;
				int li=INF-es[i][id];
				// cerr<<"f["<<i<<"]["<<id<<"] = "<<li<<endl;
				while(li--){
					ge(++cur[i],ten[j-1]);
				}
				if(i!=j){
					int ri=INF-es[j][id];
					// cerr<<"f["<<j<<"]["<<id<<"] = "<<ri<<endl;
					while(ri--){
						ge(++cur[j],ten[i-1]);
					}
				}
			}
		}
		exit(0);
	}
}
int ec=0;
void et(int i,int j){
	if(i>n){
		if(ec==n-1){
			doit();
		}
	}
	else{
		// cerr<<"et "<<i<<" "<<j<<endl;
		et(j<n?i:i+1,j<n?j+1:i+1);
		if(cnt[i][j]>0&&ufs.merge(i,j)){
			ie[i][j]=true;
			ec++;
			et(j<n?i:i+1,j<n?j+1:i+1);
			ie[i][j]=false;
			ec--;
			ufs.undo();
		}
	}
}
void solve(){
	init();
	et(1,1);
	gg();
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		char u[N],v[N];
		scanf("%s%s",u,v);
		int ul=strlen(u),vl=strlen(v);
		assert(ul>0);
		assert(vl>0);
		if(ul>vl){
			swap(ul,vl);
		}
		cnt[ul][vl]++;
	}
	solve();
	return 0;
}