#include<cstdio>
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
int n,c[N][N],cc[N][N],m,d[N*N][N];
bool ok[N];
int main()
{
	read(n);
	F(i,0,n)
	{
		int x;
		F(j,0,n)++c[i][--read(x)];
	}
	F(i,0,n)F(j,0,n)++cc[i][c[i][j]];
	while(true)
	{
		bool allok=true;
		F(i,0,n)allok=(ok[i]=cc[i][1]==n)&&allok;
		if(allok)break;
		F(i,0,n)if(!ok[i])
		{
			int j=0,k=i==n-1?0:i+1;
			while(c[i][j]<=1)++j;
			d[m][i]=j;
			while(ok[k])d[m][k]=j,++k,(k>=n)&&(k-=n);
			--cc[i][c[i][j]];
			--c[i][j];
			++cc[i][c[i][j]];
			--cc[k][c[k][j]];
			++c[k][j];
			++cc[k][c[k][j]];
		}
		++m;
	}
	F(i,0,n)for(int j=i;j;--j)
	{
		F(k,0,n)d[m][k]=(k+j)%n;
		++m;
	}
	printf("%d\n",m);
	F(i,0,m)
	{
		F(j,0,n)printf("%d ",d[i][j]+1);
		puts("");
	}
	return 0;
}