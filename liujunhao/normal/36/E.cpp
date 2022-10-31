#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 10000
#define MAXM 10000
int color[MAXN+10],d[MAXN+10],pth[MAXN+10];
bool vis[MAXN+10];
int m,cnt,pcnt;
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
struct node{
	int v,pos;
	bool f;
	node *next,*back;
}*adj[MAXN+10],edge[MAXM*2+10],*ecnt=edge;
inline void addedge(int u,int v,int pos){
	node *p=++ecnt;
	p->v=v;
	p->next=adj[u];
	adj[u]=p;
	p->pos=pos;
	p=p->back=++ecnt;
	p->v=u;
	p->next=adj[v];
	adj[v]=p;
	p->back=ecnt-1;
	p->pos=pos;
}
void dfs(int u,int col){
	color[u]=col;
	for(node *p=adj[u];p;p=p->next)
		if(!color[p->v])
			dfs(p->v,col);
}
void read(){
	Read(m);
	if(m<=1){
		puts("-1");
		exit(0);
	}
	int i,u,v;
	for(i=1;i<=m;i++){
		Read(u),Read(v);
		addedge(u,v,i);
		vis[u]=vis[v]=1;
		d[u]++,d[v]++;
	}
}
void Get_euler(int u,node *le){
	node *p;
	while(adj[u]){
		p=adj[u];
		adj[u]=p->next;
		if(p->f)
			continue;
		p->back->f=1;
		Get_euler(p->v,p);
	}
	if(le)
		pth[++pcnt]=le->pos;
}
void solve(){
	int i;
	for(i=1;i<=MAXN;i++)
		if(vis[i]&&!color[i])
			dfs(i,++cnt);
	if(cnt>2){
		puts("-1");
		return;
	}
	int cd[3]={0},st[3]={0},cut;
	if(cnt==2){
		for(i=1;i<=MAXN;i++)
			if(vis[i]&&(d[i]&1))
				cd[color[i]]++,st[color[i]]=i;
		if(cd[1]>2||cd[2]>2){
			puts("-1");
			exit(0);
		}
		for(int k=1;k<=2;k++){
			pcnt=0;
			if(cd[k])
				Get_euler(st[k],0);
			else
				for(i=1;i<=MAXN;i++)
					if(color[i]==k){
						Get_euler(i,0);
						break;
					}
			printf("%d\n",pcnt);
			for(i=pcnt;i;i--)
				printf("%d ",pth[i]);
			puts("");
		}
		return;
	}
	else{
		for(i=1;i<=MAXN;i++)
			if(vis[i]&&(d[i]&1))
				cd[color[i]]++,st[color[i]]=i;
		if(cd[1]>4){
			puts("-1");
			exit(0);
		}
		if(cd[1]==4){
			for(i=1;i<=MAXN;i++)
				if(vis[i]&&(d[i]&1)&&i!=st[1]){
					addedge(st[color[i]],i,m+1);
					d[i]++,d[st[color[i]]]++;
					break;
				}
			for(i=1;i<=MAXN;i++)
				if(vis[i]&&(d[i]&1)){
					st[color[i]]=i;
					break;
				}
			cut=m+1;
		}
		if(cd[1])
			Get_euler(st[1],0);
		else
			for(i=1;i<=MAXN;i++)
				if(color[i]==1){
					Get_euler(i,0);
					break;
				}
		if(cd[1]==4){
			for(i=pcnt;i;i--)
				if(pth[i]==cut)
					break;
			printf("%d\n",pcnt-i);
			for(i=pcnt;i;i--){
				if(pth[i]==cut)
					break;
				printf("%d ",pth[i]);
			}
			printf("\n%d\n",--i);
			for(;i;i--)
				printf("%d ",pth[i]);
			return;
		}
		printf("%d\n",pcnt-1);
		for(i=pcnt;i>1;i--)
			printf("%d ",pth[i]);
		printf("\n1\n%d\n",pth[1]);
		return;
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	read();
	solve();
}