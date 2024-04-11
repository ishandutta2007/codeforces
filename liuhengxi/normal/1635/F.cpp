#include<cstdio>
#include<cstring>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5;
const long long LLINF=0x3f3f3f3f3f3f3f3f;
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
struct query{int l,r,id;}qy[N];
bool operator<(query u,query v){return u.l>v.l;}
int n;
long long c[N];
void add(int x,long long y){for(++x;x<=n;x+=x&-x)c[x]=min(c[x],y);}
long long sum(int x){long long ans=LLINF;for(;x;x-=x&-x)ans=min(ans,c[x]);return ans;}
int q,x[N],w[N],sta[N],top;
long long ans[N];
void update(int u,int v){add(v,(long long)(w[u]+w[v])*(x[v]-x[u]));}
int main()
{
	memset(c,0x3f,sizeof c);
	read(n,q);
	F(i,0,n)read(x[i],w[i]);
	F(i,0,q)--read(qy[i].l),read(qy[i].r),qy[i].id=i;
	sort(qy,qy+q);
	for(int i=0,j=n;i<q;++i)
	{
		for(;j>qy[i].l;top&&(update(j,sta[top-1]),1),sta[top++]=j)for(--j;top&&w[sta[top-1]]>=w[j];)update(j,sta[--top]);
		ans[qy[i].id]=sum(qy[i].r);
	}
	F(i,0,q)printf("%lld\n",ans[i]);
	return 0;
}