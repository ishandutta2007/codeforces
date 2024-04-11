#include<cstdio>
#include<algorithm>
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
constexpr int N=55,MOD=998244353;
int &reduce(int &x){(x>=MOD)&&(x-=MOD);return x;}
void mul(int n,int a[N][N],const int b[N][N],const int c[N][N])
{
	static int t[N][N];
	F(i,0,n)F(j,0,n)t[i][j]=0;
	F(i,0,n)F(k,0,n)F(j,0,n)t[i][j]=(int)((t[i][j]+(long long)b[i][k]*c[k][j])%MOD);
	F(i,0,n)F(j,0,n)a[i][j]=t[i][j];
}
int d[N],m,e[N],et[N],f[N][N];
long long a[N],v[2*N],x[N],y[N];
bool t[N];
int solve(int l,int r)
{
	int n=(++r)-l;
	m=0;
	F(i,l,r)v[m++]=x[i-l]=min(a[i-1],a[i])+(a[i-1]<a[i]),v[m++]=y[i-l]=max(a[i-1],a[i])+(a[i-1]<a[i]),t[i-l]=a[i-1]<a[i];
	sort(v,v+m);
	m=(int)(unique(v,v+m)-v);
	F(i,0,n)e[i]=0;
	e[n]=1;
	F(i,0,m-1)
	{
		F(j,0,n+1)F(k,0,n+1)f[j][k]=0;
		F(j,0,n)
		{
			if(x[j]<=v[i]&&v[i]<y[j])
			{
				F(k,0,j)f[k][j]=1;
				f[j][j]=t[j];
				f[n][j]=1;
			}
		}
		long long k=v[i+1]-v[i];
		while(k)
		{
			if(k&1)
			{
				F(j,0,n+1)et[j]=0;
				F(j,0,n+1)F(p,0,n+1)et[p]=(int)((et[p]+(long long)e[j]*f[j][p])%MOD);
				F(j,0,n+1)e[j]=et[j];
			}
			if(k>>=1)mul(n+1,f,f,f);
		}
		if(v[i+1]==a[r-1]+1)break;
	}
	int ans=0;
	F(i,0,n)reduce(ans+=e[i]);
	return ans;
}
int n;
int main()
{
	read(n);
	read(a[0]);
	a[1]=a[0]-1;
	++n;
	for(int i=1;i<n;++i)if(read(d[i]))a[i+1]=a[i]+d[i];else --i,--n;
	if(!n)return puts("1 1");
	long long maxd=0;
	int ans=0;
	F(i,1,n)F(j,i,n)maxd=max(maxd,a[j+1]-a[i]);
	if(maxd==0)
	{
		ans=1;
		F(i,0,n)reduce(ans+=abs(d[i]));
		printf("%d %d\n",1,ans);
		return 0;
	}
	F(i,1,n)
	{
		for(int j=n;j>i;--j)if(a[j]==a[i]+maxd)
		{
			reduce(ans+=solve(i,j));
			i=j;
			break;
		}
	}
	printf("%lld %d\n",maxd+1,ans);
	return 0;
}