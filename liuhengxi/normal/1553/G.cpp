#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1.5e5+5,M=1e6+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct edge
{
	int u,v;
	edge(int a=0,int b=0){u=a;v=b;}
	bool operator<(edge b)const{return u!=b.u?u<b.u:v<b.v;}
}e[20*N];
int n,q,a[N],b[M],m,f[M],ecnt;
int pri[M],cnt,pre[M],base[M],p[20],pp;// number theory
bool vis[M];
int dfind(int x){return f[x]==x?x:f[x]=dfind(f[x]);}
void init()
{
	F(i,2,m)
	{
		if(!vis[i])pre[pri[cnt++]=base[i]=i]=1;
		F(j,0,cnt)
		{
			int x=i*pri[j];
			if(x>=m)break;
			vis[x]=true;
			base[x]=pri[j];
			if(i%pri[j]==0)
			{
				pre[x]=pre[i];
				break;
			}
			else pre[x]=i;
		}
	}
}
int main()
{
	read(n);read(q);
	F(i,0,n)read(a[i]),m=a[i]>m?a[i]:m;
	m+=2;init();
	F(i,0,m)f[i]=i;
	F(i,0,n)
	{
		int first=-1;
		for(int j=a[i],k;j!=1;j=pre[j])
		{
			k=base[j/pre[j]];
			if(~first)f[dfind(k)]=dfind(first);
			else first=k;
			f[dfind(a[i])]=dfind(k);
		}
	}
	F(i,0,n)
	{
		pp=0;
		for(int j=a[i];j!=1;j=pre[j])p[pp++]=dfind(base[j/pre[j]]);
		for(int j=a[i]+1;j!=1;j=pre[j])p[pp++]=dfind(base[j/pre[j]]);
		p[pp++]=a[i];
		sort(p,p+pp);
		pp=unique(p,p+pp)-p;
		F(i,0,pp)F(j,i+1,pp)e[ecnt].u=p[i],e[ecnt++].v=p[j];
	}
	sort(e,e+ecnt);
	while(q--)
	{
		int s,t;read(s);read(t);
		s=dfind(a[s-1]);t=dfind(a[t-1]);
		if(s>t)s^=t^=s^=t;
		if(s==t)puts("0");
		else
		{
			int p=lower_bound(e,e+ecnt,edge(s,t))-e;
			if(e[p].u==s&&e[p].v==t)puts("1");
			else puts("2");
		}
	}
	return 0;
}