#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

inline void down(int &a,const int &b){if(a>b)a=b;}
const int maxn = 2100;
const int maxm = 110000;

int n,m,S,T;
int e[maxm][3],ok[maxm];
int t[maxm],tp;
struct edge{int y,i,nex;}a[maxm]; int len,fir[maxn];
inline void ins(const int x,const int y,const int i){a[++len]=(edge){y,i,fir[x]};fir[x]=len;}

int dfn[maxn],low[maxn],dfi,ib[maxm];
int fa[maxn],fai[maxn];
void init()
{
	for(int i=1;i<=n;i++) dfn[i]=fa[i]=fai[i]=0;
	for(int i=1;i<=m;i++) ib[i]=0;
	dfi=0;
}
void tarjan(const int x)
{
	dfn[x]=low[x]=++dfi;
	for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) if(a[k].i!=fai[x]&&!ok[a[k].i])
	{
		if(!dfn[y])
		{
			fai[y]=a[k].i,fa[y]=x;
			tarjan(y);
			down(low[x],low[y]);
			if(low[y]==dfn[y]) ib[a[k].i]=1;
		}
		else down(low[x],dfn[y]);
	}
}

int ans,ansn,re[10];

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	scanf("%d%d",&S,&T);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&e[i][0],&e[i][1],&e[i][2]);
		ins(e[i][0],e[i][1],i);
		ins(e[i][1],e[i][0],i);
	}
	init(); tarjan(S);
	if(!dfn[T])
	{
		puts("0");puts("0");
		putchar('\n');
		return 0;
	}
	ans=INT_MAX;
	for(int i=T;i!=S;i=fa[i])
	{
		int k=fai[i];
		if(ib[k])
		{
			if(ans>e[k][2]) ans=e[k][2],re[ansn=1]=k;
		}
		else t[++tp]=k;
	}
	for(int i=1;i<=tp;i++)
	{
		ok[t[i]]=1;
		init(); tarjan(S);
		for(int j=T;j!=S;j=fa[j])
		{
			int k=fai[j];
			if(ib[k])
			{
				if(ans>e[t[i]][2]+e[k][2]) ans=e[t[i]][2]+e[k][2],ansn=2,re[1]=t[i],re[2]=k;
			}
		}
		ok[t[i]]=0;
	}
	if(ans==INT_MAX) puts("-1");
	else
	{
		printf("%d\n",ans);
		printf("%d\n",ansn);
		for(int i=1;i<=ansn;i++) printf("%d ",re[i]);
	}
	
	return 0;
}