#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 50001
struct Edge{
	int t, w, next;
}e[1000001];
int head[MAXN], layer[MAXN];
int cnt, src, dst, cur;
void init(int n)
{
	cur = 0; cnt = n;
	memset(head + 1, -1, sizeof(int)*n);
}
void addEdge(int s, int t, int w)
{
	e[cur] = { t, w, head[s] };
	head[s] = cur++;
	e[cur] = { s, 0, head[t] };
	head[t] = cur++;
}
void addEdge2(int s, int t, int w)
{
	e[cur] = { t, w, head[s] };
	head[s] = cur++;
	e[cur] = { s, w, head[t] };
	head[t] = cur++;
}
bool bfs()
{
	static int q[MAXN];
	memset(layer + 1, 0, sizeof(int)*cnt);
	q[0] = src; layer[src] = 1;
	for (int front = 0, back = 0; front <= back; front++){
		int k = layer[q[front]];
		for (int i = head[q[front]]; i != -1; i = e[i].next){
			int t = e[i].t;
			if (!layer[t] && e[i].w){
				q[++back] = t;
				layer[t] = k + 1;
				if (t == dst)return true;
			}
		}
	}
	return false;
}
int dfs(int i, int flow)
{
	if (i == dst)return flow;
	int ret = 0;
	for (int j = head[i]; j != -1; j = e[j].next){
		if (layer[e[j].t] == layer[i] + 1 && e[j].w){
			int w = dfs(e[j].t, min(flow - ret, e[j].w));
			e[j].w -= w; e[j ^ 1].w += w;
			ret += w;
			if (ret == flow)break;
		}
	}
	if (!ret)layer[i] = 0;
	return ret;
}
int dinic()
{
	int res = 0;
	while (bfs())res += dfs(src, 0x7fffffff);
	return res;
}

int a[201];
int dis[601][601];
int main()
{
	int v,e,n,k,x,y,z;
	scanf("%d%d%d%d",&v,&e,&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=v;i++)
		dis[i][i]=0;
	for(int i=0;i<e;i++){
		scanf("%d%d%d",&x,&y,&z);
		dis[y][x]=dis[x][y]=min(dis[x][y],z);
	}
	for(int k=1;k<=v;k++){
		for(int i=1;i<=v;i++){
			for(int j=i+1;j<=v;j++){
				int d=dis[i][k]+dis[k][j];
				dis[j][i]=dis[i][j]=min(dis[i][j],d);
			}
		}
	}
	int l=0,r=20000000;
	while(l<r){
		int mid=(l+r)>>1;
		init(n+v+2);
		src=n+v+1;dst=n+v+2;
		for(int i=1;i<=n;i++){
			addEdge(src,i,1);
			for(int j=1;j<=v;j++){
				if(dis[a[i]][j]<=mid)
					addEdge(i,j+n,1);
			}
		}
		for(int i=1;i<=v;i++)
			addEdge(i+n,dst,1);
		if(dinic()>=k)r=mid;
		else l=mid+1;
	}
	printf("%d",l==20000000?-1:l);
}