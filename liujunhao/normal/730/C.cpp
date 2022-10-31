#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
#define MAXN 5000
#define MAXM 5000
#define MAXW 5000
#define INF 2000000000
typedef pair<int,int> pii;
typedef long long LL;

struct node{
	int v;
	node *next;
}edge[MAXM*2+10],*adj[MAXN+10],*ecnt=&edge[0];

int n,m,w,b[MAXN+10],cntb,dist[MAXN+10];
vector<pii> vec[MAXN+10];
bool vis[MAXN+10];

template<class T>
void Read(T &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return ;
		}
}

void addedge(int u,int v){
	node *p=++ecnt;
	p->v=v;
	p->next=adj[u];
	adj[u]=p;
}
void read(){
	int x,y,cost,num;
	Read(n),Read(m);
	for(int i=1;i<=m;i++){
		Read(x),Read(y);
		addedge(x,y),addedge(y,x);
	}
	Read(w);
	for(int i=1;i<=w;i++){
		Read(x),Read(num),Read(cost);
		vec[x].push_back(make_pair(num,cost));
	}
}
void Bfs(int s){
	int u;
	cntb=0;
	for(int i=1;i<=n;i++)
		dist[i]=INF,vis[i]=0;
	queue<int> que;
	que.push(s);
	dist[s]=0;
	vis[s]=1;
	while(!que.empty()){
		u=que.front(); que.pop();
		b[++cntb]=u;
		for(node *p=adj[u];p;p=p->next)
			if(!vis[p->v]){
				dist[p->v]=dist[u]+1;
				vis[p->v]=1;
				que.push(p->v);
			}
	}
}

struct cmp{
	bool operator () (const pii &x,const pii &y){
		if(x.second==y.second) return x.first<y.first;
		else return x.second<y.second;
	}
};
inline int Calcu(int num,int cost){
	int side,i;
	pii u;
	LL tot=0;
	priority_queue<pii,vector<pii>,cmp> que;
	for(i=1;i<=cntb;i++){
		//printf("i: %d %d\n",i,cntb);
		side=vec[b[i]].size();
		for(int j=0;j<side;j++){
			num-=vec[b[i]][j].first;
			tot+=1LL*vec[b[i]][j].first*vec[b[i]][j].second;
			que.push(vec[b[i]][j]);
		}
		while(!que.empty()&&tot>cost){
			u=que.top(); que.pop();
			//printf("%I64d %d %d %d %d\n",tot,num,cost,u.first,u.second);
			if(1LL*u.first*u.second<=tot-cost)
				tot-=1LL*u.first*u.second,num+=u.first;
			else{
				LL tmp=ceil(1.0*(tot-cost)/u.second);
				//printf("%I64d\n",tmp);
				tot-=tmp*u.second;
				num+=tmp;
				if(u.first!=tmp)
					que.push(make_pair(u.first-tmp,u.second));
			}
		}
		if(num<=0) break;
	}
	return i>cntb?-1:dist[b[i]];
}
void solve(){
	int Q,s,num,cost;
	Read(Q);
	while(Q--){
		Read(s),Read(num),Read(cost);
		Bfs(s);
		printf("%d\n",Calcu(num,cost));
	}
}
int main(){
	read();
	solve();
	return 0;
}