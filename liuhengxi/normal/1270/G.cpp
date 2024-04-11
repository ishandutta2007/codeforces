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
int t,n,a[N],use[N],lim,cnt;
int dfs(int u)
{
	if(~use[u])return -(lim=use[u]);
	use[u]=cnt++;
	return dfs(u-a[u])+1;
}
int main()
{
	read(t);
	while(t--)
	{
		read(n);
		F(i,1,n+1)read(a[i]),use[i]=-1;
		cnt=0;
		printf("%d\n",dfs(1));
		F(i,1,n+1)if(use[i]>=lim)printf("%d ",i);
		puts("");
	}
	return 0;
}