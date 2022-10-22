#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=110;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,f[N][N],q;
int find(int x,int y){return f[x][y]==y?y:f[x][y]=find(x,f[x][y]);}
int main()
{
	read(n);read(m);
	F(i,0,n)F(j,0,m)f[j][i]=i;
	F(i,0,m)
	{
		int u,v,c;read(u);read(v);read(c);--u,--v,--c;
		f[c][find(c,u)]=find(c,v);
	}
	read(q);
	while(q--)
	{
		int u,v,ans=0;
		read(u);read(v);--u,--v;
		F(i,0,m)if(find(i,u)==find(i,v))++ans;
		printf("%d\n",ans);
	}
	return 0;
}