#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5;
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
	int nex,to;
}e[2*N];
int n,m,Q,hd[N],cnt,sta[N],top,ind[N],pos[N],cir,nex[N],q[N],qf,qr;
int r[N],l[N];
long long s[N];
bool vis[N],ok[N];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].nex=hd[u];
	hd[u]=cnt++;
}
void dfs(int u,int f)
{
	vis[u]=true;
	sta[top++]=u;
	for(int i=hd[u];~i;i=e[i].nex)
	{
		int v=e[i].to;if(v==f)continue;
		if(!vis[v])dfs(v,u);
		else if(!ok[v])
		{
			pos[cir+1]=pos[cir];
			++cir;
			while(sta[--top]!=v)ok[ind[pos[cir]++]=sta[top]]=true;
			ok[ind[pos[cir]++]=v]=true;
		}
	}
	if(top&&sta[top-1]==u)--top;
}
int main()
{
	read(n);read(m);
	F(i,0,n)hd[i]=-1,nex[i]=n;
	F(i,0,m)
	{
		int u,v;read(u);read(v);
		adline(--u,--v);adline(v,u);
	}
	F(i,0,n)if(!vis[i])dfs(i,-1);
	F(i,0,cir)
	{
		sort(ind+pos[i],ind+pos[i+1]);
		nex[ind[pos[i]]]=ind[pos[i+1]-1];
	}
	for(int i=0,j=0;i<n;++i)
	{
		while(i==j||j<nex[q[qf]])
		{
			while(qf<qr&&nex[j]<=nex[q[qr-1]])--qr;
			q[qr++]=j++;
		}
		r[i]=j;
		if(q[qf]==i)++qf;
	}
	F(i,0,n)s[i+1]=s[i]+r[i];
	for(int i=0,j=0;i<n;++i)
	{
		while(j<n&&r[j]<=i+1)++j;
		l[i+1]=j;
	}
	read(Q);
	while(Q--)
	{
		int x,y,z;
		long long ans;
		read(x);read(y);--x;
		z=l[y]>x?l[y]:x;
		ans=s[z]-s[x]-(z-x)*(long long)x-(z-x)*(z-x-1ll)/2;
		ans+=(y-z)*(y-z+1ll)/2;
		printf("%lld\n",ans);
	}
	return 0;
}