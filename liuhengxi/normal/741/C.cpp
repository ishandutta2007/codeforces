#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,f[N],ans[N],pos[N],realans[N];
void dfs(int u)
{
	if(!~ans[f[u]])ans[f[u]]=ans[u]^1,dfs(f[u]);
	if(!~ans[u^1])ans[u^1]=ans[u]^1,dfs(u^1);
}
int main()
{
	read(n);
	F(i,0,n)
	{
		int a,b;read(a);read(b);
		pos[--a]=i<<1;pos[--b]=i<<1|1;
		f[a]=b;f[b]=a;
	}
	F(i,0,n<<1)ans[i]=-1;
	F(i,0,n<<1)if(!~ans[i])ans[i]=0,dfs(i);
	F(i,0,n<<1)realans[pos[i]]=ans[i];
	F(i,0,n)printf("%d %d\n",realans[i<<1]+1,realans[(i<<1)|1]+1);
	return 0;
}