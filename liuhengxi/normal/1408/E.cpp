#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct edge
{
	int u,v,w;
	bool operator<(edge b)const{return w>b.w;}
}e[2*N];
int m,n,f[2*N],cnt,a[N],b[N];
long long ans;
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int main()
{
	read(m);read(n);
	F(i,0,m)read(a[i]);
	F(i,0,n)read(b[i]);
	F(i,0,m+n)f[i]=i;
	F(i,0,m)
	{
		int s;read(s);
		while(s--)
		{
			int j;read(j);--j;
			e[cnt].u=i+n;e[cnt].v=j;
			ans+=e[cnt++].w=a[i]+b[j];
		}
	}
	sort(e,e+cnt);
	F(i,0,cnt)if(find(e[i].u)!=find(e[i].v))ans-=e[i].w,f[find(e[i].u)]=find(e[i].v);
	printf("%lld\n",ans);
	return 0;
}