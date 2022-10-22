#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,M=5e5+5,K=N<<7;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,q,a[N],pos[M],fac[K],pri[M],cnt,mu[M],c[M];
long long ans;
bool vis[M],in[N];
int main()
{
	read(n);read(q);
	F(i,0,n)read(a[i]),m=m>a[i]?m:a[i];
	++m;
	mu[1]=1;
	F(i,2,m)
	{
		if(!vis[i])mu[pri[cnt++]=i]=-1;
		F(j,0,cnt)
		{
			int x=i*pri[j];
			if(x>=m)break;
			vis[x]=true;
			if(i%pri[j]==0)break;
			mu[x]=-mu[i];
		}
	}
	F(i,1,m)if(mu[i])for(int j=i;j<m;j+=i)++pos[j];
	F(i,0,m)pos[i+1]+=pos[i];
	F(i,1,m)if(mu[i])for(int j=i;j<m;j+=i)fac[--pos[j]]=i;
	while(q--)
	{
		int id;read(id);--id;
		in[id]=!in[id];
		if(in[id])
		{
			F(i,pos[a[id]],pos[a[id]+1])
			{
				register int x=fac[i];
				ans+=c[x]*mu[x];
				++c[x];
			}
		}
		else
		{
			F(i,pos[a[id]],pos[a[id]+1])
			{
				register int x=fac[i];
				--c[x];
				ans-=c[x]*mu[x];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}