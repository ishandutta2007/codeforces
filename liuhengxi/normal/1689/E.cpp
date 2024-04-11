#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2005;
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
int tt,n,a[N];
int f[32],g[32];
int find(int x){return g[x]==x?x:g[x]=find(g[x]);}
bool check()
{
	int all=0;
	F(i,0,32)f[i]=0,g[i]=i;
	F(i,0,n)f[__builtin_ctz(a[i])]|=a[i],all|=a[i];
	F(i,0,32)F(j,i+1,32)if(f[i]>>j&1)g[find(i)]=find(j);
	int low=__builtin_ctz(all);
	F(i,0,32)if(all>>i&1)if(find(i)!=find(low))return false;
	return true;
}
int solve()
{
	if(check())return 0;
	F(i,0,n)
	{
		++a[i];
		if(check())return 1;
		--a[i];
		--a[i];
		if(a[i]&&check())return 1;
		++a[i];
	}
	int u=0,v=-1;
	F(i,1,n)if(__builtin_ctz(a[i])>__builtin_ctz(a[u]))u=i,v=-1;
	else if(__builtin_ctz(a[i])==__builtin_ctz(a[u]))v=i;
	--a[u];
	++a[v];
	return 2;
}
int main()
{
	read(tt);
	while(tt--)
	{
		int cnt=0;
		read(n);
		F(i,0,n)if(!read(a[i]))++a[i],++cnt;
		printf("%d\n",solve()+cnt);
		F(i,0,n)printf("%d ",a[i]);
		puts("");
	}
	return 0;
}