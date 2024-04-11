#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<functional>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
constexpr int N=1e5+5,S=650,K=17;
int n=100000,k=16,pri[N],cnt,phi[N],tc[N],tx[N][S];
long long p[N],ty[N][S];
bool vis[N];
void init()
{
	phi[1]=0;
	F(i,2,n+1)
	{
		if(!vis[i])pri[cnt++]=i,phi[i]=i-1;
		F(j,0,cnt)
		{
			int x=i*pri[j];if(x>n)break;
			vis[x]=true;
			if(i%pri[j])phi[x]=phi[i]*(pri[j]-1);
			else
			{
				phi[x]=phi[i]*pri[j];
				break;
			}
		}
	}
	F(i,1,n+1)p[i]=p[i-1]+phi[i];
	F(i,1,n+1)
	{
		long long sum=0;
		tx[i][tc[i]++]=n;
		for(int l,r=i;r;r=l)
		{
			l=i/(i/r+1);
			tx[i][tc[i]]=l;
			sum+=(long long)(r-l)*p[i/r];
			ty[i][tc[i]++]=sum;
		}
	}
}
long long query(int l,int r)
{
	int i=(int)(lower_bound(tx[r],tx[r]+tc[r],l,greater<int>())-tx[r]);
	if(tx[r][i]==l)return ty[r][i];
	return (ty[r][i]-ty[r][i-1])/(tx[r][i]-tx[r][i-1])*(l-tx[r][i-1])+ty[r][i-1];
}
void dp(const long long *const&g,long long *const&f,int l,int r,int kl,int kr)
{
	if(l==r)return;
	int mid=(l+r)>>1,i=min(kr,mid-1),pos=i;
	long long sum=query(i,mid),mn=sum+g[i];
	while(i>kl)
	{
		sum+=p[mid/i];
		--i;
		if(sum+g[i]<mn)mn=sum+g[i],pos=i;
	}
	f[mid]=mn;
	dp(g,f,l,mid,kl,pos);
	dp(g,f,mid+1,r,pos,kr);
}
long long f[K][N];
int main()
{
	init();
	memset(f,0x3f,sizeof f);
	f[0][0]=0;
	F(i,0,k)dp(f[i],f[i+1],1,n+1,0,n);
	int tt;read(tt);
	while(tt--)
	{
		read(n,k);
		if(k>16)printf("%d\n",n);
		else printf("%lld\n",f[k][n]+n);
	}
	return 0;
}