#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define sta(u,t) ((u)*k+(t))
using namespace std;
const int N=120,M=2*(N+2)*N;
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
}e[2*M];
int n,k,l,d[N+2],p[2*N],hd[M],cnt;
bool vis[M];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u)
{
	if(vis[u])return;
	vis[u]=true;
	for(int i=hd[u];~i;i=e[i].next)dfs(e[i].to);
}
int main()
{
	int T;read(T);
	while(T--)
	{
		read(n);read(k);read(l);
		F(i,0,n)read(d[i+1]);
		F(i,0,2*(n+2)*k)hd[i]=-1,vis[i]=false;
		cnt=0;
		n+=2;
		F(i,0,k)p[i]=i;F(i,0,k)p[i+k]=k-i;k*=2;
		F(j,0,k)
		{
			adline(sta(0,j),sta(0,(j+1)%k));
		}
		F(j,0,k)
		{
			adline(sta(n-1,j),sta(n-1,(j+1)%k));
		}
		F(i,1,n-1)F(j,0,k)if(d[i]+p[(j+1)%k]<=l)
		{
			adline(sta(i,j),sta(i,(j+1)%k));
		}
		F(i,0,n-2)F(j,0,k)if(d[i+1]+p[(j+1)%k]>0&&d[i+1]+p[(j+1)%k]<=l)
		{
			adline(sta(i,j),sta(i+1,(j+1)%k));
		}
		F(j,0,k)
		{
			adline(sta(n-2,j),sta(n-1,(j+1)%k));
		}
		dfs(sta(0,0));
		puts(vis[sta(n-1,0)]?"Yes":"No");
	}
	return 0;
}