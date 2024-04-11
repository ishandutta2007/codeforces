#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=4005;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,f[N][N],u[N],v[N],deg[N],ans;
int main()
{
	read(n);read(m);ans=3*n;
	F(i,0,m)read(u[i]),read(v[i]),f[--u[i]][--v[i]]=1,f[v[i]][u[i]]=1,++deg[u[i]],++deg[v[i]];
	F(x,0,n)F(i,0,m)
	{
		int y=u[i],z=v[i];if(!f[x][y]||!f[x][z])continue;
		ans=min(ans,deg[x]+deg[y]+deg[z]);
	}
	if(ans==3*n)puts("-1");
	else printf("%d\n",ans-6);
	return 0;
}