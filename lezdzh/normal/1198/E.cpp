#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

struct ed{int v,f,nx;}e[10000001];
int et=1,h[10001],d[10001],cur[10001],ss,tt;
void jb(int u,int v,int f){
	e[++et]=(ed){v,f,h[u]};
	h[u]=et;
	e[++et]=(ed){u,0,h[v]};
	h[v]=et;
}
bool bfs(){
	for(int i=ss;i<=tt;i++){
		d[i]=0;
		cur[i]=h[i];
	}
	queue<int>q;
	q.push(ss);
	d[ss]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=h[u];i;i=e[i].nx)
			if(e[i].f&&!d[e[i].v]){
				d[e[i].v]=d[u]+1;
				q.push(e[i].v);
			}
	}
	return d[tt];
}
int dfs(int u,int f){
	if(!f||u==tt)return f;
	int F=0;
	for(int&i=cur[u];i;i=e[i].nx)
		if(d[e[i].v]==d[u]+1){
			int ff=dfs(e[i].v,min(e[i].f,f));
			e[i].f-=ff;
			e[i^1].f+=ff;
			f-=ff;
			F+=ff;
			if(!f)break;
		}
	return F;
}
int a[101],b[101],c[101][101];
int x1[101],y1[101],x2[101],y2[101];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
		a[++a[0]]=x1[i];
		a[++a[0]]=x2[i]+1;
		b[++b[0]]=y1[i];
		b[++b[0]]=y2[i]+1;
	}
	sort(a+1,a+a[0]+1);
	a[0]=unique(a+1,a+a[0]+1)-a-1;
	sort(b+1,b+b[0]+1);
	b[0]=unique(b+1,b+b[0]+1)-b-1;
	for(int i=1;i<=m;i++){
		x1[i]=lower_bound(a+1,a+a[0]+1,x1[i])-a;
		x2[i]=lower_bound(a+1,a+a[0]+1,x2[i]+1)-a-1;
		y1[i]=lower_bound(b+1,b+b[0]+1,y1[i])-b;
		y2[i]=lower_bound(b+1,b+b[0]+1,y2[i]+1)-b-1;
		for(int u=x1[i];u<=x2[i];u++)
			for(int v=y1[i];v<=y2[i];v++)
				c[u][v]=1;
	}
	ss=0;
	tt=a[0]+b[0]+1;
	for(int i=1;i<=a[0];i++)
		for(int j=1;j<=b[0];j++)
			if(c[i][j])
				jb(i,a[0]+j,2e9);
	for(int i=1;i<a[0];i++)
		jb(ss,i,a[i+1]-a[i]);
	for(int i=1;i<b[0];i++)
		jb(a[0]+i,tt,b[i+1]-b[i]);
	int ans=0;
	while(bfs()){
		ans+=dfs(ss,2e9);
	}
	printf("%d\n",ans);
}