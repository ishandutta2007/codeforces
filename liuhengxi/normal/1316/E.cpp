#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,M=8;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,p,k,a[N],s[N][M],id[N],t[N],pop[1<<M];
long long f[N][1<<M];
bool cmp(int u,int v){return a[u]>a[v];}
int main()
{
	read(n);read(p);read(k);
	F(i,0,n)read(a[i]),t[i]=i;
	sort(t,t+n,cmp);
	F(i,0,n)id[t[i]]=i;
	F(i,0,n)t[id[i]]=a[i];
	F(i,0,n)a[i]=t[i];
	F(i,0,n)F(j,0,p)read(s[id[i]][j]);
	F(i,1,1<<p)pop[i]=pop[i^(i&-i)]+1;
	F(i,0,n)F(j,0,1<<p)if(pop[j]<=i)
	{
		if(pop[j]==p)
		{
			if(i>=p+k)f[i+1][j]=f[i+1][j]>f[i][j]?f[i+1][j]:f[i][j];
			else f[i+1][j]=f[i+1][j]>f[i][j]+a[i]?f[i+1][j]:f[i][j]+a[i];
		}
		else
		{
			F(r,0,p)if((j>>r&1)==0)
			{
				int u=j^1<<r;
				f[i+1][u]=f[i+1][u]>f[i][j]+s[i][r]?f[i+1][u]:f[i][j]+s[i][r];
			}
			if(i-pop[j]>=k)f[i+1][j]=f[i+1][j]>f[i][j]?f[i+1][j]:f[i][j];
			else f[i+1][j]=f[i+1][j]>f[i][j]+a[i]?f[i+1][j]:f[i][j]+a[i];
		}
	}
	printf("%lld\n",f[n][(1<<p)-1]);
	return 0;
}