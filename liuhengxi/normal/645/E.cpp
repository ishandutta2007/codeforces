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
constexpr int N=2e6+5,MOD=1000000007;
namespace mat
{
	constexpr int N=31;
	void mul(const int a[N][N],const int b[N][N],int c[N][N],int n,int m,int k)
	{
		static int t[N][N];
		F(i,0,n)F(j,0,k)t[i][j]=0;
		F(i,0,n)F(p,0,m)F(j,0,k)t[i][j]=(int)((t[i][j]+(long long)a[i][p]*b[p][j])%MOD);
		F(i,0,n)F(j,0,k)c[i][j]=t[i][j];
	}
}
using mat::mul;
int n,m,k,mm,a[N],s[N],last[N],f[mat::N][mat::N],ans[mat::N][mat::N];
char str[N];
int main()
{
	read(m,k);
	mm=min(m,k);
	F(i,0,k)last[i]=-1;
	s[0]=1;
	scanf("%s",str);
	while(str[n])++n;
	F(i,0,n)a[i]=str[i]-'a';
	F(i,0,n)s[i+1]=((unsigned)(s[i]<<1)+(~last[a[i]]?MOD-s[last[a[i]]]:0u))%MOD,last[a[i]]=i;
	F(i,n,n+mm)
	{
		F(j,1,k)if(last[j]<last[a[i]])a[i]=j;
		s[i+1]=((unsigned)(s[i]<<1)+(~last[a[i]]?MOD-s[last[a[i]]]:0u))%MOD;
		last[a[i]]=i;
	}
	n+=mm;
	m-=mm;
	if(!m)return printf("%d\n",s[n]),0;
	F(i,0,k+1)ans[0][i]=s[n-k+i];
	F(i,0,k)f[i+1][i]=1;
	f[0][k]=MOD-1;f[k][k]=2;
	while(m)
	{
		if(m&1)mul(ans,f,ans,1,k+1,k+1);
		mul(f,f,f,k+1,k+1,k+1);
		m>>=1;
	}
	printf("%d\n",ans[0][k]);
	return 0;
}