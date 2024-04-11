#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,n,m,to[N][2],deg[N][4],col[N];
int main()
{
	read(t);
	while(t--)
	{
		int k=0;
		read(n);read(m);
		F(i,0,n)to[i][0]=to[i][1]=-1,deg[i][0]=deg[i][1]=deg[i][2]=0;
		F(i,0,m)
		{
			int u,v;read(u);read(v);--u,--v;
			if(~to[u][0])to[u][1]=v;
			else to[u][0]=v;
		}
		F(u,0,n)
		{
			if(deg[u][1])col[u]=2;
			else if(deg[u][0])col[u]=1;
			else col[u]=0;
			if(~to[u][0])
			{
				++deg[to[u][0]][col[u]];
				if(~to[u][1])++deg[to[u][1]][col[u]];
			}
		}
		F(i,0,n)if(col[i]&2)++k;
		printf("%d\n",k);
		F(i,0,n)if(col[i]&2)printf("%d ",i+1);
		puts("");
	}
	return 0;
}