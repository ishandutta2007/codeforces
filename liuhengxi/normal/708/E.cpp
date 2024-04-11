#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1505,MOD=1000000007;
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
int pow(int aa,int b)
{
	long long a=aa,c=1;
	for(;b;b>>=1,(a*=a)%=MOD)if(b&1)(c*=a)%=MOD;
	return (int)c;
}
int n,m,ua,ub,p,t,r[N],f[N][N],g[N][N],ans;
int main()
{
	read(n,m,ua,ub,t);
	p=(int)((long long)ua*pow(ub,MOD-2)%MOD);
	r[0]=1;
	F(_,0,t)for(int i=m;~i;--i)
		r[i+1]=(int)((r[i+1]+(long long)p*r[i])%MOD),r[i]=(int)(r[i]*(MOD+1ll-p)%MOD);
	f[0][m]=1;g[0][m]=1;
	ans=1;
	F(i,1,n+1)
	{
		int s=0,sr=0;
		F(j,1,m+1)
		{
			s=(int)((s+(long long)r[j-1]*(MOD+ans-g[i-1][j-1]))%MOD);
			sr=(sr+r[j-1])%MOD;
			f[i][j]=(int)(r[m-j]*(s+MOD-(long long)sr*g[i-1][m-j]%MOD)%MOD);
			g[i][j]=(f[i][j]+g[i][j-1])%MOD;
		}
		ans=g[i][m];
	}
	printf("%d\n",ans);
	return 0;
}