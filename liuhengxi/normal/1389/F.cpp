#include<cstdio>
#include<algorithm>
#include<queue>
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
struct event
{
	int time,type,id;
	friend bool operator<(event a,event b)
	{return a.time!=b.time?a.time<b.time:a.type>b.type;}
}e[N<<1];
int n,l[N],r[N],t[N],p[N],ans;
bool ban[N<<1];
struct cmp{bool operator()(int a,int b){return p[a]>p[b];}};
priority_queue<int,vector<int>,cmp> q[2];
int main()
{
	read(n);
	ans=n;
	F(i,0,n)read(l[i],r[i],t[i]),++r[i],--t[i];
	F(i,0,n)
	{
		e[i<<1].type=0,e[i<<1].time=l[i],e[i<<1].id=i;
		e[i<<1|1].type=1,e[i<<1|1].time=r[i],e[i<<1|1].id=i;
	}
	sort(e,e+(n<<1));
	F(i,0,n<<1)if(e[i].type)p[e[i].id]=i;
	F(i,0,n<<1)
	{
		int u=e[i].id;
		if(e[i].type)
		{
			if(!ban[u])
			{
				if(!q[t[u]^1].empty())ban[q[t[u]^1].top()]=true,q[t[u]^1].pop(),--ans;
				q[t[u]].pop();
			}
		}
		else q[t[u]].push(u);
	}
	printf("%d\n",ans);
	return 0;
}