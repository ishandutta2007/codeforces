#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2005;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,u[N][N],d[N][N],l[N][N],r[N][N];
long long ans;
char s[N][N];
int main()
{
	read(n);read(m);
	F(i,0,n)gets(s[i]);
	F(i,0,n)F(j,0,m)u[i][j]=d[i][j]=l[i][j]=r[i][j]=s[i][j]=s[i][j]=='.'?1:0;
	F(i,1,n-1)
	{
		int ok=1;
		F(j,0,m)ok&=s[i][j];
		ans+=ok;
	}
	F(j,1,m-1)
	{
		int ok=1;
		F(i,0,n)ok&=s[i][j];
		ans+=ok;
	}
	F(i,1,n)F(j,0,m)u[i][j]&=u[i-1][j];
	F(i,0,n)F(j,1,m)l[i][j]&=l[i][j-1];
	for(int i=n-2;~i;--i)for(int j=m-1;~j;--j)d[i][j]&=d[i+1][j];
	for(int i=n-1;~i;--i)for(int j=m-2;~j;--j)r[i][j]&=r[i][j+1];
	F(i,1,n-1)F(j,1,m-1)ans+=(u[i][j]+d[i][j])*(l[i][j]+r[i][j]);
	F(i,1,n-1)
	{
		int sum=u[i][1]+d[i][1];
		F(j,2,m-1)
		{
			ans+=sum*(u[i][j]+d[i][j]);
			ans-=u[i][j]*u[i][j-1]+d[i][j]*d[i][j-1];
			sum+=u[i][j]+d[i][j];
			if(!s[i][j])sum=0;
		}
	}
	F(j,1,m-1)
	{
		int sum=l[1][j]+r[1][j];
		F(i,2,n-1)
		{
			ans+=sum*(l[i][j]+r[i][j]);
			ans-=l[i][j]*l[i-1][j]+r[i][j]*r[i-1][j];
			sum+=l[i][j]+r[i][j];
			if(!s[i][j])sum=0;
		}
	}
	printf("%lld\n",ans);
	return 0;
}