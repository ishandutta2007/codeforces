#include<cstdio>
#include<cstring>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=25,MOD=998244353,w[19]={1%MOD,10%MOD,100%MOD,1000%MOD,10000%MOD,100000%MOD,1000000%MOD,10000000%MOD,100000000%MOD,1000000000%MOD,10000000000%MOD,100000000000%MOD,1000000000000%MOD,10000000000000%MOD,100000000000000%MOD,1000000000000000%MOD,10000000000000000%MOD,100000000000000000%MOD,1000000000000000000%MOD};
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct result
{
	int cnt,sum;
}f[N/*digit*/][2/*0 - < , 1 - =*/][1<<10];
int k;
long long l,r;
void add(result &a,const result &b,int c)
{
	(a.cnt+=b.cnt)%=MOD;
	(a.sum+=(b.sum+b.cnt*(long long)c%MOD)%MOD)%=MOD;
}
long long solve(long long x)
{
	long long d=1000000000000000000;int ans=0;
	memset(f,0,sizeof f);
	f[19][1][0].cnt=1;
	for(int i=18;~i;--i,d/=10)
	{
		int y=x/d%10;
		add(f[i][0][0],f[i+1][0][0],0);
		F(k,1,10)add(f[i][0][1<<k],f[i+1][0][0],(long long)k*w[i]%MOD);
		add(f[i][y?0:1][0],f[i+1][1][0],0);
		F(k,1,y)add(f[i][0][1<<k],f[i+1][1][0],(long long)k*w[i]%MOD);
		if(y)add(f[i][1][1<<y],f[i+1][1][0],(long long)y*w[i]%MOD);
		F(j,1,1<<10)
		{
			F(k,0,10)add(f[i][0][j|(1<<k)],f[i+1][0][j],(long long)k*w[i]%MOD);
			F(k,0,y)add(f[i][0][j|(1<<k)],f[i+1][1][j],(long long)k*w[i]%MOD);
			add(f[i][1][j|(1<<y)],f[i+1][1][j],(long long)y*w[i]%MOD);
		}
	}
	F(i,0,1<<10)if(__builtin_popcount(i)<=k)(ans+=f[0][0][i].sum)%=MOD;
	return ans;
}
int main()
{
	read(l);read(r);read(k);
	printf("%lld\n",(solve(r+1)-solve(l)+MOD)%MOD);
	return 0;
}