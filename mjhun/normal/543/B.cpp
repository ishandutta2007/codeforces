#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define INF (1<<30)
using namespace std;

vector<int> g[3005];
int n,m;
int s1,t1,l1,s2,t2,l2;
int d[3005][3005];
queue<int> q;

void bfs(int x){
	d[x][x]=0;
	q.push(x);
	while(!q.empty()){
		int v=q.front();
		q.pop();
		for(int i=0;i<g[v].size();++i){
			int s=g[v][i];
			if(d[x][s]==-1){
				d[x][s]=1+d[x][v];
				q.push(s);
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		int a,b;
		scanf("%d%d",&a,&b);a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	scanf("%d%d%d%d%d%d",&s1,&t1,&l1,&s2,&t2,&l2);s1--;t1--;s2--;t2--;

	memset(d,-1,sizeof(d));
	for(int i=0;i<n;++i)bfs(i);

	int r=INF;
	if(d[s1][t1]<=l1&&d[s2][t2]<=l2)r=d[s1][t1]+d[s2][t2];
	for(int x=0;x<n;++x){
		for(int y=x+1;y<n;++y){
			int d1,d2;
			d1=d[x][y]+min(d[x][s1]+d[y][t1],d[x][t1]+d[y][s1]);
			d2=d[x][y]+min(d[x][s2]+d[y][t2],d[x][t2]+d[y][s2]);
			if(d1<=l1&&d2<=l2)r=min(r,d1+d2-d[x][y]);
		}
	}
	printf("%d\n",r==INF?-1:m-r);	
	return 0;
}