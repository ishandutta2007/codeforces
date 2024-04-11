#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,F[27]={1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418};
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct line
{
	int next,to;
}e[2*N];
int n,hd[N],cnt,siz[N],fa[N];
bool vis[N];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u,int f)
{
	fa[u]=f;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==f)continue;
		dfs(v,u);
	}
}
int findsize(int u,int s)
{
	if(vis[u])return siz[u]=0,-1;
	siz[u]=1;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to,tmp;if(v==fa[u])continue;
		tmp=findsize(v,s);
		if(~tmp)return tmp;
		siz[u]+=siz[v];
	}
	if(siz[u]==s)return u;
	return -1;
}
bool check(int u,int k)
{
	int v;
	if(k<3)return true;
	v=findsize(u,F[k-1]);
	if(!~v)
	{
		v=findsize(u,F[k-2]);
		if(!~v)return false;
		if(!check(v,k-2))return false;
		vis[v]=true;
		return check(u,k-1);
	}
	if(!check(v,k-1))return false;
	vis[v]=true;
	return check(u,k-2);
}
int main()
{
	read(n);
	F(i,0,n)hd[i]=-1;
	F(i,0,n-1)
	{
		int u,v;read(u);read(v);
		adline(--u,--v);adline(v,u);
	}
	dfs(0,0);
	F(i,0,27)if(n==F[i])return puts(check(0,i)?"Yes":"No"),0;
	puts("No");
	return 0;
}