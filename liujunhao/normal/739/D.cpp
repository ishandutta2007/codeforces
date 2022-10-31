#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#define MAXN 300
#define INF 0x7fffffff
using namespace std;
queue<int>q;
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF)
		if(c=='-')
			f=1;
		else if(c=='?'){
			x=-1;
			return;
		}
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
	int v,cap;
	node *next,*back;
}*adj[MAXN*3+10],edge[MAXN*MAXN*10+10],*ecnt=edge;
inline void addedge(int u,int v,int cap){
	node *p=++ecnt;
	p->v=v;
	p->next=adj[u];
	p->cap=cap;
	adj[u]=p;
	p=p->back=++ecnt;
	p->v=u;
	p->next=adj[v];
	p->cap=0;
	adj[v]=p;
	p->back=ecnt-1;
}
int tot,dist[MAXN*3+10],vd[MAXN*3+10],n,nxt[MAXN+10],mxx,now,x[MAXN+10],y[MAXN+10],vis[MAXN+10][MAXN+10],S,T;
typedef pair<int,int>pii;
pii b[MAXN*3+10];
vector<int>incir[MAXN+10];
bool flag=0,ex[MAXN+10];
void read(){
	Read(n);
	int i;
	for(i=1;i<=n;i++){
		Read(x[i]),Read(y[i]);
		if(~y[i]){
			ex[y[i]]=1;
			flag=1;
			mxx=max(mxx,x[i]);
			if(!x[i]){
				vis[x[i]][y[i]]=i;
				incir[y[i]].push_back(i);
			}
			else if(x[i]>0)
				vis[x[i]][y[i]]=i;
		}
	}
}
void spfa(int S){
	bool vis[MAXN*3+10]={0};
	int i,u;
	for(i=1;i<=tot;i++)
		dist[i]=INF;
	dist[S]=0;
	q.push(S);
	while(!q.empty()){
		u=q.front();
		q.pop();
		vis[u]=0;
		for(node *p=adj[u];p;p=p->next)
			if(p->back->cap&&dist[p->v]>dist[u]+1){
				dist[p->v]=dist[u]+1;
				if(!vis[p->v])
					q.push(p->v),vis[p->v]=1;
			}
	}
}
int dfs(int u,int augu){
	if(u==T)
		return augu;
	int augv=0,delta,mind=tot-1;
	for(node *p=adj[u];p;p=p->next)
		if(p->cap){
			if(dist[u]==dist[p->v]+1){
				delta=min(p->cap,augu-augv);
				delta=dfs(p->v,delta);
				p->cap-=delta;
				p->back->cap+=delta;
				augv+=delta;
				if(dist[S]>=tot||augv==augu)
					return augv;
			}
			mind=min(mind,dist[p->v]);
		}
	if(!augv){
		if(!--vd[dist[u]])
			dist[S]=tot;
		vd[dist[u]=mind+1]++;
	}
	return augv;
}
int sap(){
	spfa(T);
	int i,flow=0;
	for(i=1;i<=tot;i++)
		vd[i]=0;
	for(i=1;i<=tot;i++)
		if(dist[i]<INF)
			vd[dist[i]]++;
	while(dist[S]<tot){
		flow+=dfs(S,INF);
	}
	return flow;
}
void print(){
	int i,j;
	for(i=1;i<=n;i++){
		if(x[i]<=mxx&&(x[i]==-1||y[i]==-1))
			for(node *p=adj[i];p;p=p->next)
				if(p->v>n&&p->v!=S&&p->v!=T&&!p->cap){
					if(p->v<=2*n){
						incir[p->v-n].push_back(i);
						x[i]=0,y[i]=p->v-n;
						vis[x[i]][y[i]]=i;
					}
					else{
						vis[b[p->v].second][b[p->v].first]=i;
						x[i]=b[p->v].second,y[i]=b[p->v].first;
					}
					break;
				}
	}
	for(i=1;i<=n;i++){
		for(j=0;j<incir[i].size();j++)
			if(j%i==i-1)
				nxt[incir[i][j]]=incir[i][j-i+1];
			else
				nxt[incir[i][j]]=incir[i][j+1];
	}
	for(i=1;i<=n;i++){
		if(x[i]==-1&&y[i]==-1)
			nxt[i]=i;
		else if(x[i]==-1)
			x[i]=1;
		else if(y[i]==-1){
			if(!x[i])
				y[i]=1,nxt[i]=i;
			else
				for(j=1;j<=n;j++)
					if(vis[x[i]-1][j]){
						y[i]=j;
						break;
					}
		}
		if(!nxt[i])
			nxt[i]=vis[x[i]-1][y[i]];
		printf("%d ",nxt[i]);
	}
}
bool check(){
	memset(adj,0,sizeof adj);
	ecnt=edge;
	S=n*2+1,T=tot=S+1;
	int i,cnt=0,need=0,j,k;
	for(i=1;i<=n;i++)
		if(x[i]<=mxx&&(x[i]==-1||y[i]==-1)){
			addedge(S,i,1);
			cnt++;
		}
	for(i=1;i<=n;i++){
		if(ex[i]){
			if(!incir[i].size()||incir[i].size()%i){
				addedge(i+n,T,i-incir[i].size()%i);
				need+=i-incir[i].size()%i;
				if(need>cnt)
					return 0;
				for(j=1;j<=n;j++)
					if((x[j]==-1&&y[j]==-1)||(x[j]==-1&&y[j]==i)||(x[j]==0&&y[j]==-1))
						addedge(j,n+i,1);
			}
			for(j=n;j&&!vis[j][i];j--);
			for(;j;j--){
				if(!vis[j][i]){
					b[++tot]=pii(i,j);
					need++;
					if(need>cnt)
						return 0;
					addedge(tot,T,1);
					for(k=1;k<=n;k++)
						if((x[k]==-1&&y[k]==-1)||(x[k]==-1&&y[k]==i)||(x[k]==j&&y[k]==-1))
							addedge(k,tot,1);
				}
			}
		}
	}
	if(sap()<need)
		return 0;
	print();
	return 1;
}
void solve(){
	int i,j;
	if(flag){
		for(i=1;i<=n;i++)
			if(ex[i]){
				now=i;
				for(j=1;j<=n;j++)
					if(x[j]>mxx)
						vis[x[j]][i]=j,y[j]=i;
				if(check())
					return;
				for(j=1;j<=n;j++)
					if(x[j]>mxx)
						vis[x[j]][i]=0;
			}
	}
	else{
		ex[1]=1;
		for(i=1;i<=n;i++)
			if(~x[i])
				vis[x[i]][1]=i;
			if(check())
				return;
	}
	puts("-1");
}
int main()
{
	read();
	solve();
}