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
constexpr int N=105;
int n,m,a,b,c,ax,ay,ans[N][N],pa;
char str[N<<1][N<<1];
int main()
{
	read(n,m);
	read(a,b,c);
	ax=a/m;ay=a%m;
	F(i,0,ax)F(j,0,m)ans[i][j]=8;
	F(i,0,ay)ans[ax][i]=8;
	F(i,ay,m)ans[ax][i]=4|((i-ay)&1);
	F(i,0,ay)ans[ax+1][i]=4|((ay-1-i)&1);
	c-=m;++ax;
	while(c>1&&ax<n-1)
	{
		if(pa)
		{
			int x=min(ay,c>>1),y=0,t=(x^1)&1;
			c-=x<<1;
			while(x--)
			{
				ans[ax][y]=t|6;
				ans[ax+1][y]=t|4;
				++y;
				t^=1;
			}
		}
		else
		{
			int x=min(m-ay,c>>1),y=m,t=x&1;
			c-=x<<1;
			while(x--)
			{
				--y;
				ans[ax][y]=t|6;
				ans[ax+1][y]=t|4;
				t^=1;
			}
		}
		pa^=1;
		++ax;
	}
	if(c)
	{
		ax=n-1;
		if(pa)
		{
			int y=0,t=(c^1)&1;
			while(c--)
			{
				ans[ax][y]=t|6;
				++y;
				t^=1;
			}
		}
		else
		{
			int y=m,t=c&1;
			while(c--)
			{
				--y;
				ans[ax][y]=t|6;
				t^=1;
			}
		}
	}
	F(i,0,n)F(j,0,m)
	{
		char &a00=str[i<<1][j<<1],&a01=str[i<<1][j<<1|1],&a10=str[i<<1|1][j<<1],&a11=str[i<<1|1][j<<1|1];
		if(ans[i][j]&8)a00=a01=a10=a11='#';
		else if(ans[i][j]&4)
		{
			if(ans[i][j]==4)a00='#',a01=a10='/',a11='.';
			if(ans[i][j]==5)a01='#',a00=a11='\\',a10='.';
			if(ans[i][j]==6)a01='.',a00=a11='\\',a10='#';
			if(ans[i][j]==7)a00='.',a01=a10='/',a11='#';
		}
		else a00=a01=a10=a11='.';
	}
	F(i,0,n<<1)puts(str[i]);
	return 0;
}