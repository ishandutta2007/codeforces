#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,MOD=998244353;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
struct line
{
	int next,t;
}e[2*N];
int tt,n,hd[N],cnt,f[N],q[N],qf,qr,d[N],t[N],a[N];
inline void adline(int u,int v)
{
	e[cnt].t=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
int main()
{
	for(read(tt);tt--;)
	{
		read(n);
		F(i,cnt=0,n)hd[i]=-1,d[i]=0;
		f[1]=1;
		F(i,0,n-1)
		{
			int u,v;--read(u),--read(v);
			adline(u,v);adline(v,u);
			++d[u],++d[v];
			f[1]=(f[1]<<1)%MOD;
		}
		qf=qr=0;
		F(i,0,n)if(d[i]==1)q[qr++]=i;
		while(qf<qr)
		{
			int u=q[qf++];
			d[u]=0;
			for(int i=hd[u];~i;i=e[i].next)
			{
				int v=e[i].t;
				if(d[v])
				{
					t[u]=v;
					if(--d[v]==1)q[qr++]=v;
				}
			}
		}
		F(k,2,n)if((n-1)%k==0)
		{
			F(i,0,n)a[i]=0;
			F(i,0,n-1)
			{
				int u=q[i];
				++a[a[u]%k?u:t[u]];
			}
			f[k]=1;
			F(i,0,n)if(a[i]%k)f[k]=0;
		}
		else f[k]=0;
		f[n]=0;
		for(int i=n;--i;)for(int j=i<<1;j<n;j+=i)f[i]-=f[j],f[i]+=f[i]>>31&MOD;
		F(i,1,n+1)printf("%d ",f[i]);
		puts("");
	}
	return 0;
}