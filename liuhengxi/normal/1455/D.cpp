#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=505,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,n,x,a[N],f[N][N][N],v,ans;
int main()
{
	read(t);
	while(t--)
	{
		read(n);read(x);v=x;
		F(i,0,n)read(a[i]),v=a[i]>v?a[i]:v;
		++v;
		F(i,0,n+1)F(j,0,v)F(k,0,v)f[i][j][k]=INF;
		ans=INF;
		f[0][0][x]=0;
		F(i,0,n)F(j,0,v)F(k,0,v)
		{
			if(a[i]>=j)f[i+1][a[i]][k]=min(f[i+1][a[i]][k],f[i][j][k]);
			if(k>=j&&a[i]>k)f[i+1][k][a[i]]=min(f[i+1][k][a[i]],f[i][j][k]+1);
		}
		F(j,0,v)F(k,0,v)ans=min(ans,f[n][j][k]);
		printf("%d\n",ans==INF?-1:ans);
	}
	return 0;
}