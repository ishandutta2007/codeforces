#include<cstdio>
#include<algorithm>
#include<deque>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e4+5,M=1e7+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct line
{
	int next:26;
	unsigned to:24,dis:1;
}e[2*M];
struct node
{
	int hd:26,dis:15;
}t[M];
deque<int> q;
int n,d[N],g,r,cnt,nd;
inline int node(int num,int time){return num*g+time;}
inline void adline(int u,int v,int w)
{
	e[cnt].to=v;
	e[cnt].dis=w;
	e[cnt].next=t[u].hd;
	t[u].hd=cnt++;
}
inline void adline2(int u,int v,int w)
{
	F(i,0,g-w)adline(node(u,i),node(v,i+w),0);
	if(w<=g)adline(node(u,g-w),node(v,0),1);
}
inline void adline3(int u,int v,int w){adline2(u,v,w),adline2(v,u,w);}
void bfs01()
{
	F(i,1,nd)t[i].dis=-1;
	q.push_back(0);
	while(!q.empty())
	{
		int u=q.front();q.pop_front();
		for(int i=t[u].hd;~i;i=e[i].next)
		{
			int v=e[i].to;if(~t[v].dis)continue;
			t[v].dis=t[u].dis+e[i].dis;
			if(e[i].dis)q.push_back(v);
			else q.push_front(v);
		}
	}
}
int main()
{
	int ans=-1;
	read(n);read(n);
	F(i,0,n)read(d[i]);
	read(g);read(r);
	nd=n*g;
	sort(d,d+n);
	F(i,0,nd)t[i].hd=-1;
	F(i,0,n-1)adline3(i,i+1,d[i+1]-d[i]);
	bfs01();
	int tmp=t[node(n-1,0)].dis;
	if(~tmp)if(!~ans||tmp*(g+r)-r<ans)ans=tmp*(g+r)-r;
	F(i,1,g)
	{
		int tmp=t[node(n-1,i)].dis;
		if(~tmp)if(!~ans||tmp*(g+r)+i<ans)ans=tmp*(g+r)+i;
	}
	printf("%d\n",ans);
	return 0;
}