#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5;
const long long MOD=202108161401;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a,m,c[N],pri[N],cnt,mu[N],e[N];
long long f[N],g;
bool vis[N];
void init()
{
	mu[1]=1;
	F(i,2,m)
	{
		if(!vis[i])mu[pri[cnt++]=i]=-1;
		F(j,0,cnt)
		{
			int x=i*pri[j];if(x>=m)break;
			vis[x]=true;
			if(i%pri[j]==0)break;
			else mu[x]=-mu[i];
		}
	}
}
int main()
{
	read(n);
	F(i,0,n)read(a),m=m>a?m:a,++c[a];
	++m,init();
	F(i,1,m)for(int j=i;j<m;j+=i)e[i]+=c[j];
	F(k,1,8)
	{
		F(i,1,m)
		{
			f[i]=1;
			F(j,0,k)f[i]=f[i]*e[i]%MOD;
		}
		g=0;
		F(j,1,m)g+=mu[j]*f[j];
		g=(g%MOD+MOD)%MOD;
		if(g)return printf("%d\n",k),0;
	}
	puts("-1");
	return 0;
}