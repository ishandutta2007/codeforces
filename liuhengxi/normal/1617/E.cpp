#include<cstdio>
#include<queue>
#include<unordered_map>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
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
int n,ans,x,y;
priority_queue<int> q;
unordered_map<int,int> d,t;
int main()
{
	read(n);
	F(i,0,n)
	{
		int a;read(a);
		q.push(a);d[a]=0;t[a]=i;
	}
	while(q.size()>1)
	{
		int u=q.top(),v=u>1?(1<<(32-__builtin_clz(u-1)))-u:0;q.pop();
		if(d.count(v))
		{
			if(d[v]+d[u]+1>ans)
			{
				ans=d[v]+d[u]+1;
				x=t[u],y=t[v];
			}
			if(d[u]+1>d[v])
			{
				d[v]=d[u]+1;
				t[v]=t[u];
			}
		}
		else d[v]=d[u]+1,t[v]=t[u],q.push(v);
	}
	printf("%d %d %d\n",x+1,y+1,ans);
	return 0;
}