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

inline void read(int &x)
{
	char c; while(!((c=getchar())>='0'&&c<='9'));
	x=c-'0';
	while((c=getchar())>='0'&&c<='9') (x*=10)+=c-'0';
}
const int maxn = 510000;
const int maxm = 510000;
const int maxq = 510000;

int n,m,q;
struct edge{int i,x,y,c;}e[maxm]; int To[maxm];
inline bool cmp(const edge x,const edge y){return x.c<y.c;}

struct node{int i,j,x;};
inline bool operator <(const node x,const node y){return x.x>y.x;}
priority_queue<node>Q;
vector<int>V[maxq];
int ans[maxq];

int fa[maxn],siz[maxn];
int t[maxn][2],tp;
int findfa(const int x){return fa[x]==x?x:findfa(fa[x]);}
bool merge(int ei)
{
	int x=e[ei].x,y=e[ei].y;
	int f1=findfa(x),f2=findfa(y);
	if(f1==f2) return false;
	if(siz[f1]<siz[f2]) swap(f1,f2);
	fa[f2]=f1,siz[f1]+=siz[f2];
	t[++tp][0]=f1,t[tp][1]=f2;
	return true;
}
void gback()
{
	while(tp)
	{
		int x=t[tp][0],y=t[tp--][1];
		fa[y]=y; siz[x]-=siz[y];
	}
}

int main()
{
	read(n); read(m);
	for(int i=1;i<=m;i++) read(e[i].x),read(e[i].y),read(e[i].c),e[i].i=i;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++) To[e[i].i]=i;
	
	read(q);
	for(int i=1;i<=q;i++)
	{
		ans[i]=0; int kk; read(kk);
		while(kk--) 
		{
			int cc; read(cc); cc=To[cc];
			V[i].push_back(cc);
		}kk=V[i].size();
		sort(V[i].begin(),V[i].end());
		Q.push((node){i,0,V[i][0]});
	}
	
	for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
	for(int i=1;i<=m;)
	{
		int j=i+1;for(;j<=m&&e[j].c==e[i].c;j++);j--;
		
		while(!Q.empty())
		{
			node now=Q.top(); if(now.x>j) break;
			Q.pop();
			for(;now.j<V[now.i].size()&&V[now.i][now.j]<=j;now.j++)
				if(!merge(V[now.i][now.j])) break;
			gback();
			if(now.j==V[now.i].size()) { ans[now.i]=1; continue; }
			now.x=V[now.i][now.j];
			if(now.x>j) Q.push(now);
		}
		
		for(;i<=j;i++) merge(i);
		tp=0;
	}
	
	for(int i=1;i<=q;i++) puts(ans[i]==1?"YES":"NO");
	
	return 0;
}