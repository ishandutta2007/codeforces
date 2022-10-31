#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;
#define MAXN 1000
#define MAXM 1000
#define MAXQ 100000
int n,m,q,ans[MAXQ+10],cnt;
template<class T>
bool Read(T &x){
	char c;
	bool f=0;
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return 1;
		}
	}
	return 0;
}
struct Query{
	int p,i,j;
}Q[MAXQ+10];
struct node{
	int v;
	node *next;
}*adj[MAXQ+10],edge[MAXQ+10],*ecnt=edge;
inline void addedge(int u,int v){
	node *p=++ecnt;
	p->v=v;
	p->next=adj[u];
	adj[u]=p;
}
void read(){
	Read(n),Read(m),Read(q);
	int i,la=0;
	for(i=1;i<=q;i++){
		Read(Q[i].p),Read(Q[i].i);
		if(Q[i].p==1||Q[i].p==2){
			Read(Q[i].j);
			addedge(i-1,i);
			la=i;
		}
		else if(Q[i].p==3){
			addedge(i-1,i);
			la=i;
		}
		else
			addedge(Q[i].i,i);
	}
}
bool vis[MAXN+10][MAXM+10];
void dfs(int u){
	ans[u]=cnt;
	bool flag;
	for(node *p=adj[u];p;p=p->next){
		flag=0;
		if(Q[p->v].p==1){
			if(!vis[Q[p->v].i][Q[p->v].j]){
				vis[Q[p->v].i][Q[p->v].j]=1;
				flag=1,cnt++;
			}
		}
		else if(Q[p->v].p==2){
			if(vis[Q[p->v].i][Q[p->v].j]){
				vis[Q[p->v].i][Q[p->v].j]=0;
				flag=1,cnt--;
			}
		}
		else if(Q[p->v].p==3){
			for(int j=1;j<=m;j++)
				if(!vis[Q[p->v].i][j])
					cnt++,vis[Q[p->v].i][j]=1;
				else
					cnt--,vis[Q[p->v].i][j]=0;
		}
		dfs(p->v);
		if(Q[p->v].p==1){
			if(flag){
				vis[Q[p->v].i][Q[p->v].j]=0;
				cnt--;
			}
		}
		else if(Q[p->v].p==2){
			if(flag){
				vis[Q[p->v].i][Q[p->v].j]=1;
				cnt++;
			}
		}
		else if(Q[p->v].p==3){
			for(int j=1;j<=m;j++)
				if(!vis[Q[p->v].i][j])
					cnt++,vis[Q[p->v].i][j]=1;
				else
					cnt--,vis[Q[p->v].i][j]=0;
		}
	}
}
void print(){
	int i;
	for(i=1;i<=q;i++){
		if(Q[i].p==4)
			ans[i]=ans[Q[i].i];
		printf("%d\n",ans[i]);
	}
}
int main()
{
	read();
	dfs(0);
	print();
}