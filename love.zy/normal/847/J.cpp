#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 50001
struct Edge{
	int t, w, next;
}e[1000001];
int head[MAXN], layer[MAXN], num[MAXN];
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
int dfs(int i, int flow)
{
	if (i == dst)return flow;
	int ret = 0, h = cnt;
	for (int j = head[i]; j != -1; j = e[j].next){
		if (e[j].w){
			if (layer[i] == layer[e[j].t] + 1){
				int w = dfs(e[j].t, min(flow - ret, e[j].w));
				e[j].w -= w; e[j ^ 1].w += w;
				ret += w;
				if (ret == flow || layer[src] >= cnt)return ret;
			}
			h = min(h, layer[e[j].t]);
		}
	}
	if (!ret){
		if (!--num[layer[i]])layer[src] = cnt;
		layer[i] = h + 1; num[layer[i]]++;
	}
	return ret;
}
int isap()
{
	int res = 0;
	memset(layer + 1, 0, sizeof(int)*cnt);
	memset(num, 0, sizeof(int)*cnt);
	num[0] = cnt;
	while (layer[src] < cnt)res += dfs(src, 0x7fffffff);
	return res;
}

int n,m;
int a[5005][2];

int gao(int x)
{
    init(10005);
    src=10001;dst=10002;
    for(int i=1;i<=m;i++)
        addEdge(src,i,1);
    for(int i=1;i<=m;i++)
    {
        addEdge(i,m+a[i][0],1);
        addEdge(i,m+a[i][1],1);
    }
    for(int i=1;i<=n;i++)
        addEdge(m+i,dst,x);
    return isap();
}

bool solve(int x)
{return gao(x)>=m;}

void doit(int x)
{
    printf("%d\n",x);
    gao(x);
    for(int i=1;i<=m;i++)
    {
        int p,q;
        if(e[head[i]].w==0)p=a[i][1];else p=a[i][0];
        q=p==a[i][0]?a[i][1]:a[i][0];
        printf("%d %d\n",p,q);
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)scanf("%d%d",&a[i][0],&a[i][1]);
    int l=0,r=m;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        if(solve(mid))r=mid;else l=mid;
    }
    if(!solve(l))l++;
    doit(l);
    return 0;
}