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
int n,m,l[N][N],r[N][N],u[N][N],d[N][N],s[N][N];
long long ans;
char a[N][N+1];
int main()
{
	read(n);read(m);
	F(i,0,n)scanf("%s",a[i]);
	F(i,0,n)F(j,0,m)l[i][j]=1;
	F(i,0,n)F(j,1,m)if(a[i][j]==a[i][j-1])l[i][j]+=l[i][j-1];
	F(i,0,n)F(j,0,m)r[i][j]=1;
	F(i,0,n)for(int j=m-2;~j;--j)if(a[i][j]==a[i][j+1])
		r[i][j]+=r[i][j+1];
	F(j,0,m)u[0][j]=1;
	F(i,1,n)F(j,0,m)
	{
		int line=l[i][j]<r[i][j]?l[i][j]:r[i][j];
		int now=u[i-1][j]+1;
		if(now>line)now=line;
		if(a[i][j]!=a[i-1][j])now=1;
		u[i][j]=now;
	}
	F(j,0,m)d[n-1][j]=1;
	for(int i=n-2;~i;--i)F(j,0,m)
	{
		int line=l[i][j]<r[i][j]?l[i][j]:r[i][j];
		int now=d[i+1][j]+1;
		if(now>line)now=line;
		if(a[i][j]!=a[i+1][j])now=1;
		d[i][j]=now;
	}
	F(i,0,n)F(j,0,m)s[i][j]=u[i][j]<d[i][j]?u[i][j]:d[i][j];
	F(i,0,n)F(j,0,m)ans+=s[i][j];
	printf("%lld\n",ans);
	return 0;
}