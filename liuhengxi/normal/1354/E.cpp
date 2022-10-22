#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5005,M=1e5+5;
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
int n,m,k,n1,n2,n3,hd[N],cnt,col[N],num[N][2],p[N][N],node[N],ind,two[N];
bool vis[N],f[N][N]={true};
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
bool dfs(int u)
{
	vis[u]=true;
	++num[k][col[u]];
	node[ind++]=u;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		if(vis[v])
		{
			if(col[u]+col[v]!=1)return true;
		}
		else
		{
			col[v]=1-col[u];
			if(dfs(v))return true;
		}
	}
	return false;
}
int main()
{
	read(n);read(m);
	read(n1);read(n2);read(n3);
	F(i,0,n)hd[i]=-1;
	F(i,0,m)
	{
		int u,v;read(u);read(v);
		adline(--u,--v);adline(v,u);
	}
	F(i,0,n)if(!vis[i])
	{
		if(dfs(i))return puts("NO"),0;
		F(j,0,n+1)
		{
			f[k+1][j]=false;
			if(j>=num[k][0]&&f[k][j-num[k][0]])f[k+1][j]=true;
			if(j>=num[k][1]&&f[k][j-num[k][1]])f[k+1][j]=true,p[k+1][j]=1;
		}
		++k;
	}
	if(!f[k][n2])return puts("NO"),0;
	for(int i=k-1,q=n2;~i;--i)
	{
		two[i]=p[i+1][q];
		q-=num[i][two[i]];
	}
	for(int i=0,j=0,l;i<k;j+=l,++i)
	{
		l=num[i][0]+num[i][1];
		F(p,j,j+l)if(col[node[p]]==two[i])col[node[p]]=2;
	}
	for(int i=0,j=0;i<n;++i)if(col[i]!=2)
	{
		if(j<n1)++j,col[i]=1;
		else col[i]=3;
	}
	puts("YES");
	F(i,0,n)putchar('0'+col[i]);
	putchar('\n');
	return 0;
}