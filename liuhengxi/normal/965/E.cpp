#include<cstdio>
#include<queue>
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
int n,c[N],d[N],to[N][26],ind,ans;
char s[N];
priority_queue<int> q[N];
void insert()
{
	int j=0;
	for(int i=0;s[i];d[j]=++i)
	{
		int x=s[i]-'a';
		if(!to[j][x])to[j][x]=++ind;
		j=to[j][x];
	}
	++c[j];
}
void dfs(int u)
{
	F(i,0,26)if(to[u][i])
	{
		int v=to[u][i];
		dfs(v);
		while(!q[v].empty())q[u].push(q[v].top()),q[v].pop();
	}
	if(c[u])ans+=d[u],q[u].push(d[u]);
	else ans+=d[u]-q[u].top(),q[u].pop(),q[u].push(d[u]);
}
int main()
{
	read(n);
	insert();
	F(i,0,n)
	{
		scanf("%s",s);
		insert();
	}
	dfs(0);
	printf("%d\n",ans);
	return 0;
}