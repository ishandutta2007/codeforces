#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,M=2e5+5;
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
}e[M];
int n,m,hd[N],cnt,deg[N],q[2*N],qf,qr,nex[2][N],s;
bool incyc[N],f[2][N],deg0[N];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
#ifdef ZKYAKIOI
	printf("\t\t%d %d\n",v+1,u+1);
#endif
}
void topo()
{
	F(i,0,n)incyc[i]=true;
	F(i,0,n)if(!deg[i])deg0[q[qr++]=i]=true;
	while(qf<qr)
	{
		int u=q[qf++];
		incyc[u]=false;
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to;
			if((--deg[v])==0)q[qr++]=v;
		}
	}
	qf=qr=0;
}
void bfs()
{
	F(i,0,n)if(deg0[i])f[0][q[qr++]=i]=true,nex[0][i]=-1;
	while(qf<qr)
	{
		int u=q[qf++];
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to;
			if(f[0][u]&&!f[1][v])f[1][q[qr++]=v]=true,nex[1][v]=u;
			if(f[1][u]&&!f[0][v])f[0][q[qr++]=v]=true,nex[0][v]=u;
		}
	}
}
int main()
{
	read(n);read(m);
	F(i,0,n)hd[i]=-1;
	F(i,0,n)
	{
		int c,v;
		read(c);
		while(c--)
		{
			read(v);
			++deg[i];
			adline(--v,i);
		}
	}
	topo();
	bfs();
	read(s);--s;
	if(f[1][s])
	{
		puts("Win");
		for(int j=s,k=0;~j;j=nex[k^=1][j])printf("%d ",j+1);
		return puts(""),0;
	}
	if(incyc[s])return puts("Draw"),0;
	puts("Lose");
	return 0;
}