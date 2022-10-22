#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc ((p<<1)+1)
#define rc ((p<<1)+2)
using namespace std;
const int N=2e5+5,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,k1,k2,k3,a[3][N+1],f[N+1],ff=INF,g[N+1],ans=INF;
void add(int *a,int x){for(++x;x<=n;x+=x&-x)++a[x];}
int query(int *a,int x)
{
	int res=0;
	for(;x;x-=x&-x)res+=a[x];
	return res;
}
int main()
{
	read(k1);read(k2);read(k3);
	n=k1+k2+k3;
	F(i,0,k1)
	{
		int x;read(x);
		add(a[0],--x);
	}
	F(i,0,k2)
	{
		int x;read(x);
		add(a[1],--x);
	}
	F(i,0,k3)
	{
		int x;read(x);
		add(a[2],--x);
	}
	F(i,0,n+1)f[i]=i-query(a[0],i);
	F(i,0,n+1)
	{
		int tmp=f[i]+query(a[1],i)-i;
		if(tmp<ff)ff=tmp;
		g[i]=ff+i-query(a[1],i);
	}
	F(i,0,n+1)
	{
		int tmp=n-i-query(a[2],n)+query(a[2],i)+g[i];
		if(tmp<ans)ans=tmp;
	}
	printf("%d\n",ans);
	return 0;
}