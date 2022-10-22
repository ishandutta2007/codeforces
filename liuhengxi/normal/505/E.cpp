#include<cstdio>
#include<algorithm>
#include<queue>
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
constexpr int N=1e5+5;
int n,m,k,p,h[N],a[N],d[N];
long long t[N];
struct cmp{bool operator()(int u,int v){return d[u]<d[v];}};
priority_queue<int,vector<int>,cmp> q;
bool check(long long v)
{
	F(i,0,n)d[i]=(int)max(m-v/a[i],0ll),t[i]=v-(long long)a[i]*m;
	while(!q.empty())q.pop();
	F(i,0,n)if(t[i]<h[i])q.push(i);
	for(int i=m;~--i;)
	{
		F(j,0,k)
		{
			if(q.empty())return true;
			int u=q.top();q.pop();
			if(t[u]+(long long)a[u]*i<0)return false;
			t[u]+=p;
			d[u]=(int)max(i-(t[u]+(long long)a[u]*i)/a[u],0ll);
			if(t[u]<h[u])q.push(u);
		}
	}
	return q.empty();
}
long long br;
long long solve()
{
	long long l=-1,r=br,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid;
	}
	return r;
}
int main()
{
	read(n,m,k,p);
	F(i,0,n)read(h[i],a[i]),br=max(br,h[i]+m*(long long)a[i]);
	printf("%lld\n",solve());
	return 0;
}