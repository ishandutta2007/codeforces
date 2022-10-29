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

void read(int &x)
{
	char c; while(!((c=getchar())>='0'&&c<='9'));
	x=c-'0';
	while((c=getchar())>='0'&&c<='9') (x*=10)+=c-'0';
}
inline int num(const int x,const int p){return (x-1)*2+p;}
inline void up(int &x,const int &y){if(x<y)x=y;}
const int maxn = 1010000;
const int maxm = 1010000;

int n,m;
struct edge
{
	int y,l,r,rx;
	edge(){}
	edge(const int _y,const int _l,const int _r,const int _rx){y=_y;l=_l;r=_r;rx=_rx;}
};
vector<edge>v[maxn];
inline bool cmp(const edge x,const edge y){return x.l<y.l;}

struct node
{
	int x,t;
	node(){}
	node(const int _x,const int _t){x=_x;t=_t;}
};
inline bool operator <(const node &x,const node &y){return x.t>y.t;}
priority_queue<node>Q;

int li[maxn],ri[maxn],fir[maxn];
bool use[maxn];

int solve()
{
	for(int i=0;i<2*n;i++) li[i]=ri[i]=-1,fir[i]=0;
	li[0]=ri[0]=0;
	if(v[0].size()>0) Q.push(node(0,v[0][0].l));
	while(!Q.empty())
	{
		const node nx=Q.top(); Q.pop();
		int x=nx.x,p=x&1;
		use[x]=false;
		
		int &i=fir[x];
		const edge ne=v[x][i];
		if(ri[x]<ne.l) continue;
		if(li[x]<=ne.rx) 
		{
			const int y=ne.y;
			int rx=(ne.r&1)==p?ne.r-1:ne.r;
			if(ri[y]<ne.l+1)
			{
				li[y]=max(li[x]+1,ne.l+1),ri[y]=rx;
				if(!use[y]&&fir[y]!=v[y].size()) use[y]=true,Q.push(node(y,max(li[y],v[y][fir[y]].l)));
			}
			else if(ri[y]<rx)
			{
				ri[y]=rx;
				if(!use[y]&&fir[y]!=v[y].size()) use[y]=true,Q.push(node(y,max(li[y],v[y][fir[y]].l)));
			}
		}
		i++;
		if(i<v[x].size()) use[x]=true,Q.push(node(x,v[x][i].l));
		
		if(li[2*n-2]!=-1||li[2*n-1]!=-1)
		{
			int xx=li[2*n-2],yy=li[2*n-1];
			if(xx==-1||yy==-1) return max(xx,yy);
			return min(xx,yy);
		}
	}
	return -1;
}

int main()
{
	read(n); read(m);
	if(n==1) { puts("0"); return 0; }
	for(int i=1;i<=m;i++)
	{
		int x,y,l,r; read(x); read(y); read(l); read(r);
		
		int lx=(l&1)?l+1:l,rx=(r&1)?r-1:r-2;
		if(lx<=rx) 
			v[num(x,0)].push_back(edge(num(y,1),lx,r,rx)),
			v[num(y,0)].push_back(edge(num(x,1),lx,r,rx));
		lx=(l&1)?l:l+1,rx=(r&1)?r-2:r-1;
		if(lx<=rx)
			v[num(x,1)].push_back(edge(num(y,0),lx,r,rx)),
			v[num(y,1)].push_back(edge(num(x,0),lx,r,rx));
	}
	for(int i=0;i<2*n;i++) sort(v[i].begin(),v[i].end(),cmp);
	
	printf("%d\n",solve());
	
	return 0;
}