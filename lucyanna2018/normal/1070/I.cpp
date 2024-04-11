#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
int n, m, k;
map<int, int> e[999];
int col[999];

map<pair<int,int>,int> Map;

namespace Maxflow{
    const int maxn=6666;
    const int maxm=666666;
    const int inf=1000000000;

    int g[maxn],to[maxm],np[maxm],cp;
    int n,u,v,now,source,sink;
    int sum,cap[maxm],a[maxn];
    int d[maxn],p[maxn],cur[maxn],cnt[maxn];

    void add_edge(int x,int y,int z){
    //    printf("%d - %d: %d\n",x,y,z);
        Map[make_pair(x,y)] = cp;
        cap[cp]=z;to[cp]=y;np[cp]=g[x];g[x]=cp++;
        Map[make_pair(y,x)] = cp;
		cap[cp]=0;to[cp]=x;np[cp]=g[y];g[y]=cp++;
    }

    void init(){
        cp=2; memset(g,0,sizeof(g));
    }
    int maxflow(){
        sum=0;
        for(u=1;u<=n;u++)cur[u]=g[u]; a[u=source]=inf; memset(d,0,sizeof(int)*(n+1)); memset(cnt,0,sizeof(int)*(n+1)); cnt[0]=n;
        while(d[source]<n)
        {
            for(now=cur[u];now;now=np[now])if(cap[now]&&d[v=to[now]]+1==d[u])break; cur[u]=now;
            if(now)
            {
                p[v]=now; a[v]=cap[now]; if(a[v]>a[u])a[v]=a[u];
                if((u=v)==sink)
                {
                    do{cap[p[u]]-=a[sink]; cap[p[u]^1]+=a[sink]; u=to[p[u]^1];}while(u!=source);
                    sum+=a[sink]; a[source]=inf;
                }
            }
            else
            {
                if(--cnt[d[u]]==0)break; d[u]=n; cur[u]=g[u];
                for(now=g[u];now;now=np[now]) if(cap[now] && d[u]>d[to[now]]+1) d[u]=d[to[now]]+1;
                cnt[d[u]]++;
                if(u!=source)u=to[p[u]^1];
            }
        }
    //    printf("maxflow\n");
        return sum;
    }
}

int flow_rem_cap(int st,int en){
	return Maxflow::cap[Map[make_pair(st, en)]];
}

bool proc() {
	Maxflow::init();
	Maxflow::n = n+m+2;
	Maxflow::source = 0;
	Maxflow::sink = n+m+1;
	
	int cap = 0;
	for(int i=1;i<=n;i++) {
		int deg = e[i].size();
		if(deg>k*2) return false;
		
		map<int, int>::iterator it;
		for(it = e[i].begin();it!=e[i].end();it++)
			Maxflow::add_edge(i, n+(*it).second, 1);
		
		if (deg > k) {
			int det = (deg-k)*2;
			cap += det;
			Maxflow::add_edge(Maxflow::source, i, det);
		}
	}
	for(int i=1;i<=m;i++)
		Maxflow::add_edge(i+n, Maxflow::sink, 1);
	int flow = Maxflow::maxflow();
	if (flow < cap) return false;
	
	int color = 2;
	for(int i=1;i<=n;i++) {
		map<int, int>::iterator it;
		for(it = e[i].begin();it!=e[i].end();it++) {
			int fr = i, to = (*it).first, id = (*it).second;
			if (flow_rem_cap(fr, n+id) > 0) continue;
			
			col[id] = color/2;
			color++;
		}
	}
	for(int i=1;i<=m;i++)
		if (!col[i]) col[i] = color++;
	return true;
}
int main() {
	int _;
	for (scanf("%d", &_); _--;) {
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= n; i++)e[i].clear();
		for (int i = 1; i <= m; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			e[x][y] = e[y][x] = i;
			col[i] = 0;
		}
		if (!proc())
			for (int i = 1; i <= m; i++)
				printf("0%c", i < m ? ' ' : '\n');
		else
			for (int i = 1; i <= m; i++)
				printf("%d%c", col[i], i < m ? ' ' : '\n');
	}
	return 0;
}