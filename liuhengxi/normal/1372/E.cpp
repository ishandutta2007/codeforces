#include<cstdio>
#include<vector>
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
int m,n,s[N],g[N][N][N],f[N][N];
vector<int> left[N];
int main()
{
	read(m,n);
	F(i,0,m)
	{
		int k;read(k);
		while(k--)
		{
			int l,r;read(l,r);
			left[r].emplace_back(l);
		}
	}
	F(l,1,n+1)
	{
		F(j,1,n+1)s[j]=0;
		F(r,l,n+1)
		{
			for(int x:left[r])if(x>=l)
			{
				F(i,x,r+1)++s[i];
			}
			F(k,l,r+1)g[l][r][k]=s[k]*s[k];
		}
	}
	F(d,0,n)F(l,1,n-d+1)
	{
		int r=l+d;
		F(k,l,r+1)f[l][r]=max(f[l][r],f[l][k-1]+f[k+1][r]+g[l][r][k]);
	}
	printf("%d\n",f[1][n]);
	return 0;
}