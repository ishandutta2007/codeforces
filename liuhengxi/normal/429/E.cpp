#include<cstdio>
#include<vector>
#include<algorithm>
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
constexpr int N=2e5+5;
int n,m,l[N],r[N],v[N],c[N],ans[N];
vector<int> adj[N];
vector<int>::iterator hd[N];
bool used[N];
void dfs(int u)
{
	int i;
	do
	{
		if(hd[u]==adj[u].end())return;
		i=*hd[u];
		++hd[u];
	}
	while(used[i]);
	used[i]=true;
	ans[i]=u==l[i];
	dfs(l[i]^r[i]^u);
}
int main()
{
	read(n);
	F(i,0,n)read(l[i],r[i]),v[i<<1]=l[i],v[i<<1|1]=++r[i];
	sort(v,v+2*n);
	F(i,0,n)l[i]=(int)(lower_bound(v,v+2*n,l[i])-v),r[i]=(int)(lower_bound(v,v+2*n,r[i])-v),++c[l[i]],++c[r[i]];
	m=n;
	F(i,0,2*n)if(c[i]&1)
	{
		int j=i+1;
		while(!(c[j]&1))++j;
		l[m]=i,r[m++]=j;
		i=j;
	}
	F(i,0,m)
	{
		adj[l[i]].emplace_back(i);
		adj[r[i]].emplace_back(i);
	}
	F(i,0,2*n)hd[i]=adj[i].begin();
	F(i,0,2*n)dfs(i);
	F(i,0,n)printf("%d ",ans[i]);
	puts("");
	return 0;
}