#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
struct line
{
	int next,to;
}e[2*N];
int n,m,hd[N],cnt,q[N],qf,qr,deg[N],p[N],s[N],ac;
char ans[N];
inline void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
int main()
{
	read(n,m);
	F(i,0,n)hd[i]=-1;
	F(i,0,m)
	{
		int u,v;--read(u);--read(v);
		adline(u,v);adline(v,u);
		++deg[v];
	}
	F(i,0,n)if(!deg[i])q[qr++]=i;
	while(qf<qr)
	{
		int u=q[qf++];
		for(int i=hd[u];~i;i=e[i].next)if((i&1)==0)
		{
			int v=e[i].to;
			if(!--deg[v])q[qr++]=v;
		}
	}
	if(qr<n)return puts("-1"),0;
	F(i,0,n)p[i]=s[i]=i;
	for(int ii=n,u;~--ii&&(u=q[ii],1);)
		for(int i=hd[u];~i;i=e[i].next)if((i&1)==0)p[u]=min(p[u],p[e[i].to]);
	for(int ii=0,u=q[0];ii<n;u=q[++ii])
		for(int i=hd[u];~i;i=e[i].next)if((i&1)==1)s[u]=min(s[u],s[e[i].to]);
	F(i,0,n)ans[i]=s[i]==i&&p[i]==i?++ac,'A':'E';
	printf("%d\n",ac);
	puts(ans);
	return 0;
}