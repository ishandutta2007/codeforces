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

inline void down(int &x,const int &y){if(x>y)x=y;}
const int maxn = 1100;
const int maxm = 41000;

int n,m,st,ed;

struct edge
{
    int y,c,d,nex;
    edge(){}
    edge(const int _y,const int _c,const int _d,const int _nex){y=_y;c=_c;d=_d;nex=_nex;}
}a[maxm<<1]; int len,fir[maxn];
inline void ins(const int x,const int y,const int c,const int d)
{
    a[++len]=edge(y,c,d,fir[x]); fir[x]=len;
    a[++len]=edge(x,0,-d,fir[y]); fir[y]=len;
}

struct node
{
    int x,i;
    node(){}
    node(const int &_x,const int &_i){x=_x;i=_i;}
};
inline bool operator <(node x,node y){return x.x>y.x;}
priority_queue<node>q;
int d[maxn],pre[maxn],pos[maxn];
bool bfs()
{
    for(int i=1;i<=ed;i++) d[i]=INT_MAX;
    q.push(node(0,st)); d[st]=0;
    while(!q.empty())
    {
        const node x=q.top(); q.pop();
        if(x.x!=d[x.i]) continue;
        for(int k=fir[x.i];k;k=a[k].nex)
        {
            const int y=a[k].y;
            if(a[k].c&&d[y]>x.x+a[k].d)
            {
                d[y]=x.x+a[k].d;
                pos[y]=x.i; pre[y]=k;
                q.push(node(d[y],y));
            }
        }
    }
    return d[ed]!=INT_MAX;
}
int Flow()
{
    int re=0;
    while(bfs())
    {
        int c=INT_MAX;
        for(int k=ed;k!=st;k=pos[k]) down(c,a[pre[k]].c);
        re+=d[ed]*c;
        for(int k=ed;k!=st;k=pos[k]) a[pre[k]].c-=c,a[pre[k]^1].c+=c;
    }
    return re;
}
int fi[maxn];

int li[maxn],ri[maxn];

int main()
{
    len=1;
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) li[i]=1,ri[i]=n;
	for(int i=1;i<=m;i++)
	{
		int ti,l,r,v; scanf("%d%d%d%d",&ti,&l,&r,&v);
		if(ti==1) for(int j=l;j<=r;j++) li[j]=max(li[j],v);
		else for(int j=l;j<=r;j++) ri[j]=min(ri[j],v);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(li[i]>ri[i]) {ans=-1;break;}
	if(ans==-1) { puts("-1"); return 0; }
	
	st=2*n+1,ed=st+1;
	for(int i=1;i<=n;i++)
	{
		ins(st,i,1,0);
		int now=0;
		for(int j=li[i];j<=ri[i];j++)
			ins(i,n+j,1,0);
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ins(n+i,ed,1,j*j-(j-1)*(j-1));
	printf("%d\n",Flow());

    return 0;
}