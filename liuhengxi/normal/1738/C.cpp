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
int tt,n=102,a[N];
bool f[N][N][2][2];
int main()
{
	F(i,0,n)F(j,0,n)
	{
		if(!i&&!j)
		{
			f[i][j][0][0]=1;
			f[i][j][1][1]=1;
			continue;
		}
		if(i)
		{
			f[i][j][0][0]|=!f[i-1][j][1][0];
			f[i][j][0][1]|=!f[i-1][j][1][1];
			f[i][j][1][0]|=!f[i-1][j][0][0];
			f[i][j][1][1]|=!f[i-1][j][0][1];
		}
		if(j)
		{
			f[i][j][0][0]|=!f[i][j-1][1][1];
			f[i][j][0][1]|=!f[i][j-1][1][0];
			f[i][j][1][0]|=!f[i][j-1][0][0];
			f[i][j][1][1]|=!f[i][j-1][0][1];
		}
	}
	read(tt);
	while(tt--)
	{
		int e=0,o=0;
		read(n);
		F(i,0,n)read(a[i]);
		F(i,0,n)if(a[i]&1)++o;else ++e;
		puts(f[e][o][0][0]?"Alice":"Bob");
	}
	return 0;
}