#include<bits/stdc++.h>
#define inf 1000000000
#define N 100005
#define M 1100005
using namespace std;

int n,m,cnt,sta,gol,tx,ty,tot=1,c[N<<1],fst[N<<1],d[N<<1],h[N<<1],sz[N<<1],pnt[M],len[M],nxt[M];
char ch[N];
struct node{ int id,x,y; }a[N],b[N];
void add(int x,int y,int z){
	pnt[++tot]=y; len[tot]=z; nxt[tot]=fst[x]; fst[x]=tot;
}
void link(int x,int y,int z){
	add(x,y,z); add(y,x,0);
}
bool bfs(){
	memset(d,-1,sizeof(d)); d[sta]=1;
	int head=0,tail=1,i,x,y; h[1]=sta;
	while (head<tail){
		x=h[++head];
		for (i=fst[x]; i; i=nxt[i]) if (len[i]){
			y=pnt[i];
			if (d[y]==-1){
				d[y]=d[x]+1; h[++tail]=y;
			}
		}
	}
	return d[gol]!=-1;
}
int dfs(int x,int rst){
	if (x==gol || !rst) return rst;
	int i,y,tmp,flow=0;
	for (i=fst[x]; i && rst; i=nxt[i]) if (len[i]){
		y=pnt[i];
		if (d[x]+1==d[y]){
			tmp=dfs(y,min(rst,len[i]));
			if (tmp){
				flow+=tmp; len[i]-=tmp;
				len[i^1]+=tmp; rst-=tmp;
			}
		}
	}
	if (!flow) d[x]=-1; return flow;
}
int dinic(int x,int y){
	sta=x; gol=y;
	int flow=0;
	while (bfs()) flow+=dfs(sta,inf);
	return flow;
}
bool cmpx(const node &u,const node &v){ return u.x<v.x; }
bool cmpy(const node &u,const node &v){ return u.y<v.y; }
int main(){
	scanf("%d%d%d%d",&n,&m,&tx,&ty);
	int i,j;
	for (i=1; i<=n; i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].id=i;
	}
	for (i=1; i<=m; i++) scanf("%d%d%d",&b[i].id,&b[i].x,&b[i].y);
	sort(b+1,b+m+1,cmpx);
	int x,y,last;
	sort(a+1,a+n+1,cmpx);
	for (i=j=1,last=0; i<=n; i++){
		if (last<a[i].x){
			c[++cnt]=n; last=a[i].x;
			for (; j<=m && b[j].x<=last; j++)
				if (b[j].x==last && b[j].id==1) c[cnt]=min(c[cnt],b[j].y);
		}
		a[i].x=cnt; sz[cnt]++;
	}
	int lim=cnt;
	sort(a+1,a+n+1,cmpy);
	for (i=j=1,last=0; i<=n; i++){
		if (last<a[i].y){
			c[++cnt]=n; last=a[i].y;
			for (; j<=m && b[j].x<=last; j++)
				if (b[j].x==last && b[j].id==2) c[cnt]=min(c[cnt],b[j].y);
		}
		a[i].y=cnt; sz[cnt]++;
	}
	for (i=1; i<=n; i++) link(a[i].x,a[i].y,1);
	int sum1=0,sum2=0;
	for (i=1; i<=cnt; i++){
		c[i]=min(c[i],sz[i]);
		x=sz[i]-c[i]+1>>1; y=sz[i]+c[i]>>1;
		if (x>y){ puts("-1"); return 0; }
		if (i<=lim){
			link(0,i,y-x); link(cnt+2,i,x); sum1+=x;
		} else{
			link(i,cnt+1,y-x); link(i,cnt+3,x); sum2+=x;
		}
	}
	link(0,cnt+3,sum1); link(cnt+2,cnt+1,sum2);
	link(cnt+1,0,inf);
	if (dinic(cnt+2,cnt+3)<sum1+sum2){ puts("-1"); return 0; }
	len[tot]=len[tot-1]=0;
	dinic(0,cnt+1);
	int ans=0;
	for (i=1; i<=n; i++) if (!len[i<<1]) ans++;
	printf("%lld\n",(long long)ans*min(tx,ty)+(long long)(n-ans)*max(tx,ty));
	for (i=1; i<=n; i++) ch[a[i].id]=(len[i<<1]^(tx<ty))?'r':'b';
	for (i=1; i<=n; i++) putchar(ch[i]); puts("");
	return 0;
}