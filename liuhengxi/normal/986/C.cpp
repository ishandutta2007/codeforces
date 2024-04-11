#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=(2<<22)+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,tp,fl,a[N],ans;
bool vis[N],exist[N];
void dfs(int u)
{
	if(vis[u]||!exist[u])return;
	vis[u]=true;
	if(u&tp)dfs(u^fl);
	else
	{
		for(int i=u;i;i^=(i&-i))dfs(u^(i&-i));
		dfs(u^tp);
	}
}
int main()
{
	read(n);read(m);tp=1<<n;fl=(2<<n)-1;
	F(i,0,1<<n)exist[i]=true;
	F(i,0,m)read(a[i]),exist[a[i]|tp]=true;
	F(i,0,m)if(!vis[a[i]])dfs(a[i]|tp),++ans;
	printf("%d\n",ans);
	return 0;
}