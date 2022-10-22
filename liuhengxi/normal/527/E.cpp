#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,M=3e5+5;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
struct line
{
	int next,to;
}e[2*M];
int n,m,hd[N],cnt,deg[N],seq[M],len;
bool used[M];
inline void adline(int u,int v){e[cnt].to=v;e[cnt].next=hd[u];hd[u]=cnt++;}
inline void adline2(int u,int v){adline(u,v);adline(v,u);}
void dfs(int u)
{
	for(int &i=hd[u];~i;)
	{
		int v=e[i].to;
		if(!used[i>>1])used[i>>1]=true,i=e[i].next,dfs(v);
		else i=e[i].next;
	}
	seq[len++]=u;
}
int main()
{
	read(n,m);
	F(i,0,n)hd[i]=-1;
	F(i,0,m)
	{
		int u,v;--read(u);--read(v);
		adline2(u,v);
		++deg[u];++deg[v];
	}
	for(int i=0,last=-1;i<n;++i)if(deg[i]&1)last=~last?adline2(last,i),-1:i;
	if(cnt&2)adline2(0,0);
	dfs(0);
	printf("%d\n",len-1);
	F(i,0,len-1)if(i&1)printf("%d %d\n",seq[i]+1,seq[i+1]+1);else printf("%d %d\n",seq[i+1]+1,seq[i]+1);
	return 0;
}