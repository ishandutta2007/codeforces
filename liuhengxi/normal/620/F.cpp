#include<cstdio>
#include<utility>
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
constexpr int N=5e4+5;
int n,m,a[N],ans[5005],f[N];
vector<pair<int,int>> qy[N];
int main()
{
	read(n,m);
	F(i,0,n)read(a[i]);
	F(i,0,m)
	{
		int l,r;read(l,r);
		qy[--l].emplace_back(--r,i);
	}
	auto g=[](int x){return ((x>>2)*(x&1)<<2)+((((x&2)>>1)*3)&((x&1)<<1|1));};
	for(int i=n;~--i;)
	{
		F(j,i,n)
		{
			f[j]=max(f[j],g(min(a[i],a[j]))^g(max(a[i],a[j])+1));
			f[j+1]=max(f[j+1],f[j]);
		}
		for(pair<int,int> ri:qy[i])ans[ri.second]=f[ri.first];
	}
	F(i,0,m)printf("%d\n",ans[i]);
	return 0;
}