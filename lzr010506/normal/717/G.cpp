#include <bits/stdc++.h>
#define ll long long
#define MN 1000010
#define MM 600
using namespace std;
int n,m,p[233333],x,lg[MM];
char bs[MM],gs[MM][MM];
int N=0,M=1,S,T,fst[MN],nxt[MN],va[MN],vb[MN];
ll cap[MN],cost[MN];
void ins(int a,int b,ll ca,ll co)
{
    ++ M; 
    nxt[M] = fst[a]; 
    fst[a] = M; 
    va[M] = a; 
    vb[M] = b; 
    cap[M] = ca; 
    cost[M] = co;
}
void insert(int a,int b,ll ca,ll co) 
{
	ins(a,b,ca,co); 
	ins(b,a,0,-co);
}
ll dis[MN]; 
int q[MN],fe[MN];
bool inq[MN];
bool spfa()
{
    ll inf = 2000000000000000LL;
    for(int i = 1; i <= N; i ++) 
    	dis[i] = inf;
    inq[S] = 1; 
    q[1] = S; 
    dis[S] = 0; 
    int head = 1, tail = 2;
    while(head != tail)
    {
        int cur = q[head ++]; head &= 131071;
        for(int e = fst[cur]; e; e = nxt[e])
        {
            if(!cap[e]||dis[vb[e]] <= dis[cur] + cost[e]) continue;
            int b = vb[e], co = cost[e];
            dis[b] = dis[cur] +co; 
            fe[b] = e;
            if(!inq[b]) {inq[b] = 1; q[tail ++] = b; tail &= 131071;}
        }
        inq[cur]=0;
    }
    return dis[T]!=inf;
}
ll mcf()
{
    ll ans=0;
    while(spfa())
    {
        ll cur=2000000000000000LL;
        for(int i=fe[T];i;i=fe[va[i]]) cur=min(cur,cap[i]);
        for(int i=fe[T];i;i=fe[va[i]])
        {
            ans+=cur*cost[i];
            cap[i]-=cur; cap[i^1]+=cur;
        }
    }
    return ans;
}
int main()
{
	scanf("%d%s%d",&n,bs,&m);
	for(int i = 1; i <= m; i ++)
	{
		scanf("%s%d",gs[i], p + i);
		lg[i] = strlen(gs[i]);
	}

	int x; 
	scanf("%d",&x);
	N = n + 1;
	int in = 0;
	for(int i = 1; i <= m; i ++)
		for(int j = 0; j + lg[i] <= n; j ++)
		{
			bool ok = 1;
			for(int k = 0; k < lg[i]; k ++) ok &= gs[i][k] == bs[j + k];
			if(ok) insert(j+1,j+lg[i]+1,1,-p[i]);
		}
	for(int i = 1; i <= n; i ++) 
		insert(i,i+1,x,0);
	S = ++ N; 
	T = ++ N; 
	insert(S,1,x,0); 
	insert(n+1,T,x,0);
	cout<<-mcf();
	return 0;
}