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
#define inf 1e9
using namespace std;

inline void read(int &x)
{
	char c; while(!((c=getchar())>='0'&&c<='9'));
	x=c-'0';
	while((c=getchar())>='0'&&c<='9') (x*=10)+=c-'0';
}
inline void up(int &a,const int &b){if(a<b)a=b;}
const int maxn = 210000;

int n,K;
int v[maxn];
struct edge{int y,nex;}a[maxn<<1]; int len,fir[maxn];
inline void ins(const int x,const int y){a[++len]=(edge){y,fir[x]};fir[x]=len;}
int siz[maxn],fa[maxn];
void dfs(const int x)
{
	siz[x]=1;
	for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) if(y!=fa[x])
	{
		fa[y]=x;
		dfs(y);
		siz[x]+=siz[y];
	}
}
int f[maxn],g[maxn],uv;
void dpf(const int x)
{
	f[x]=v[x]>=uv;	int mxf=0;
	for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) if(y!=fa[x])
	{
		dpf(y);
		if(f[x])
		{
			if(f[y]==siz[y]) f[x]+=f[y];
			else up(mxf,f[y]);
		}
	}
	if(f[x]) f[x]+=mxf;
}
int pres[maxn],sufs[maxn],prex[maxn],sufx[maxn];
int t[maxn],tu[maxn],tp;
int ans;
void dpg(const int x)
{
	if(f[x])
	{
		int sum=1,mx=0;
		if(f[x]==siz[x]) sum+=f[x]-1;
		else up(mx,f[x]-1);
		if(g[x]==n-siz[x]) sum+=g[x];
		else up(mx,g[x]);
		sum+=mx;
		up(ans,sum);
	}
	tp=0;
	for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) if(y!=fa[x])
		t[++tp]=f[y],tu[tp]=siz[y];
	pres[0]=prex[0]=0;
	for(int i=1;i<=tp;i++)
	{
		pres[i]=pres[i-1]; prex[i]=prex[i-1];
		if(t[i]==tu[i]) pres[i]+=t[i];
		else up(prex[i],t[i]);
	}
	sufs[tp+1]=sufx[tp+1]=0;
	for(int i=tp;i>=1;i--)
	{
		sufs[i]=sufs[i+1]; sufx[i]=sufx[i+1];
		if(t[i]==tu[i]) sufs[i]+=t[i];
		else up(sufx[i],t[i]);
	}
	
	for(int k=fir[x],y=a[k].y,i=1;k;k=a[k].nex,y=a[k].y) if(y!=fa[x])
	{
		int sum=0,mx=0;
		if(f[x])
		{
			sum=1;
			sum+=pres[i-1]+sufs[i+1];
			if(g[x]==n-siz[x]) sum+=g[x];
			else up(mx,g[x]);
			up(mx,prex[i-1]); up(mx,sufx[i+1]);
			sum+=mx;
		}
		g[y]=sum;
		i++;
	}
	for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) if(y!=fa[x])
		dpg(y);
}
bool judge()
{
	dpf(1);
	ans=0; dpg(1);
	return ans>=K;
}

int list[maxn];

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	read(n); read(K);
	for(int i=1;i<=n;i++) read(v[i]),list[i]=v[i];
	sort(list+1,list+n+1);
	for(int i=1;i<n;i++)
	{
		int x,y; read(x),read(y);
		ins(x,y),ins(y,x);
	}
	dfs(1);
	
	int l=1,r=n;
	while(l<=r)
	{
		int mid=l+r>>1; uv=list[mid];
		if(judge()) l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",list[l-1]);
	
	return 0;
}