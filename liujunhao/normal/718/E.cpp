#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<ctime>
#define MAXN 100000
using namespace std;
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF){
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
	}
}
char s[MAXN+10],r[MAXN+10];
int rcnt,n,dist[MAXN+10][8],dist2[8][8],mask[MAXN+10],cnt[8][1<<8],q[MAXN+10],fr,bk;
long long num[MAXN+10];
bool vis[MAXN+10];
struct node{
	int v;
	node *next;
}*adj[8],edge[MAXN+10],*ecnt=edge;
inline void addedge(int u,int v){
	node *p=++ecnt;
	p->v=v;
	p->next=adj[u];
	adj[u]=p;
}
void read(){
	Read(n);
	scanf("%s",s);
	memcpy(r,s,n);
	int i;
	sort(r,r+n);
	rcnt=unique(r,r+n)-r;
	for(i=0;i<n;i++){
		s[i]=lower_bound(r,r+rcnt,s[i])-r;
		addedge(s[i],i);
	}
}
void bfs(int c){
	int i,u;
	fr=1,bk=0;
	for(i=0;i<n;i++){
		if(s[i]==c){
			q[++bk]=i;
			dist[i][c]=0;
			vis[i]=1;
		}
		else
			vis[i]=0;
	}
	for(i=0;i<rcnt;i++)
		vis[i+n]=0;
	vis[c+n]=1;
	while(fr<=bk){
		u=q[fr++];
		if(!vis[s[u]+n]){
			for(node *p=adj[s[u]];p;p=p->next)
				if(!vis[p->v])
					q[++bk]=p->v,dist[p->v][c]=dist[u][c]+1,vis[p->v]=1;
			vis[s[u]+n]=1;
		}
		if(u&&!vis[u-1])
			q[++bk]=u-1,vis[u-1]=1,dist[u-1][c]=dist[u][c]+1;
		if(u+1<n&&!vis[u+1])
			q[++bk]=u+1,vis[u+1]=1,dist[u+1][c]=dist[u][c]+1;
	}
}
void solve(){
	int i,j,d,k,l;
	for(i=0;i<rcnt;i++)
		bfs(i);
	for(i=0;i<rcnt;i++)
		for(j=0;j<rcnt;j++)
			dist2[i][j]=0x7fffffff;
	for(i=0;i<n;i++)
		for(j=0;j<rcnt;j++)
			dist2[s[i]][j]=min(dist2[s[i]][j],dist[i][j]);
	for(i=0;i<n;i++)
		for(j=0;j<rcnt;j++)
			if(dist[i][j]-dist2[s[i]][j])
				mask[i]|=1<<j;
	for(i=0;i<n;i++)
		for(j=min(i+2*rcnt-1,n-1);j>i;j--){
			d=j-i;
			for(k=0;k<rcnt;k++)
				d=min(d,dist[i][k]+1+dist[j][k]);
			num[d]++;
		}
	for(i=n-2*rcnt-1;i>=0;i--){
		cnt[s[i+2*rcnt]][mask[i+2*rcnt]]++;
		for(j=0;j<rcnt;j++){
			for(k=0;k<(1<<rcnt);k++)
				if(cnt[j][k]){
					d=0x7fffffff;
					for(l=0;l<rcnt;l++)
						d=min(d,dist2[j][l]+((k>>l)&1)+1+dist[i][l]);
					num[d]+=cnt[j][k];
				}
		}
	}
}
void print(){
	for(int i=2*rcnt-1;;i--)
		if(num[i]){
			printf("%d %I64d\n",i,num[i]);
			return;
		}
}
int main()
{
	read();
	solve();
	print();
}