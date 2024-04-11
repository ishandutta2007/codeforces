#include<cstdio>
#include<cstring>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e3+5,M=55,MOD=1000000007;
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
void reduce(int &x){x>=MOD&&(x-=MOD);}
namespace ac
{
	const int N=3e4+5,Sigma=10;
	const char startchar='0';
	int to[N][10],fail[N],ind,q[N],qf,qr;
	bool is[N];
	void insert(const char *s)
	{
		int u=0;
		for(;*s;++s)
		{
			int x=*s-startchar;
			if(!to[u][x])to[u][x]=++ind;
			u=to[u][x];
		}
		is[u]=true;
	}
	void build()
	{
		qf=qr=0;
		F(i,0,10)if(to[0][i])q[qr++]=to[0][i];
		while(qf<qr)
		{
			int u=q[qf++];
			F(i,0,10)(to[u][i]?fail[q[qr++]=to[u][i]]:to[u][i])=to[fail[u]][i];
		}
	}
}
int d,f[M][ac::N][2/*0 - <; 1 - =*/][2/*occured*/];
int dp(char *lim,int bound)
{
	using ac::to;using ac::q;using ac::qf;using ac::qr;
	int n=ac::ind+1,ans=0;
	memset(f,0,sizeof f);
	f[0][0][1][0]=1;
	F(i,0,d)
	{
		F(j,0,n)
		{
			F(k,0,10)
			{
				reduce(f[i+1][to[j][k]][0][ac::is[to[j][k]]]+=f[i][j][0][0]);
				reduce(f[i+1][to[j][k]][0][1]+=f[i][j][0][1]);
			}
			int x=lim[i]-'0';
			F(k,0,x)
			{
				reduce(f[i+1][to[j][k]][0][ac::is[to[j][k]]]+=f[i][j][1][0]);
				reduce(f[i+1][to[j][k]][0][1]+=f[i][j][1][1]);
			}
			reduce(f[i+1][to[j][x]][1][ac::is[to[j][x]]]+=f[i][j][1][0]);
			reduce(f[i+1][to[j][x]][1][1]+=f[i][j][1][1]);
		}
	}
	F(i,0,n)reduce(ans+=f[d][i][0][1]),reduce(ans+=bound*f[d][i][1][1]);
	return ans;
}
char s[N],x[N],y[N];
int n,ans;
int main()
{
	scanf("%s%s%s",s,x,y);
	while(s[n])++n;
	while(x[d])++d;
	for(int i=n-d/2,j=n;i>=0;--i,--j)
	{
		s[j]=0;
		ac::insert(s+i);
	}
	ac::build();
	ans=dp(y,1)-dp(x,0);
	ans+=ans>>31&MOD;
	printf("%d\n",ans);
	return 0;
}