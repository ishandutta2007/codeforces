#include<cstdio>
#include<queue>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a,b,smallest;
long long hp[N],dmg[N],ans,delta,ori,fsb[N];
bool use[N];
struct cmp
{
	bool operator()(int u,int v){return hp[u]-dmg[u]<hp[v]-dmg[v];}
};
priority_queue<int,vector<int>,cmp> q;
int main()
{
	read(n);read(a);read(b);
	F(i,0,n)read(hp[i]),read(dmg[i]),ori+=dmg[i];
	F(i,0,n)q.push(i);
	if(b>n)b=n;
	F(i,0,b)
	{
		int u=q.top();q.pop();use[u]=true;
		if(hp[u]>dmg[u])fsb[u]=hp[u]-dmg[u];else fsb[u]=0;
		delta+=fsb[u];
		if(i==b-1)smallest=fsb[u];
	}
	ans=delta;
	if(b)F(i,0,n)ans=max(ans,delta-(use[i]?fsb[i]:smallest)+(hp[i]<<a)-dmg[i]);
	printf("%lld\n",ans+=ori);
	return 0;
}