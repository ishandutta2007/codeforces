#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1005,M=1e5+5,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int nd,n1,n2,m,t[2*N][N],u[M],v[M],ans=-1;
int main()
{
	read(n1);read(n2);read(m);
	F(i,0,m)read(u[i]),read(v[i]),--u[i],v[i]+=n1-1;
	F(i,0,n1+n2)F(j,0,max(n1,n2)+1)t[i][j]=-1;
	F(i,0,m)
	{
		int c1=0,c2=0;
		while(~t[u[i]][c1])++c1;
		while(~t[v[i]][c2])++c2;
		t[u[i]][c1]=v[i];
		t[v[i]][c2]=u[i];
		ans=max(ans,max(c1,c2));
		if(c1==c2)continue;
		if(c1<c2)swap(c1,c2),swap(u[i],v[i]);
		for(int x=u[i],c=c1;~x;x=t[x][c],c^=c1^c2)swap(t[x][c1],t[x][c2]);
	}
	printf("%d\n",++ans);
	F(i,0,m)
	{
		F(j,0,ans)if(t[u[i]][j]==v[i])printf("%d ",j+1);
	}
	puts("");
	return 0;
}