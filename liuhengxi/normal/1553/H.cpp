#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=6e5+5,LogN=21,INF=0x2aaaaaaa;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,k,a[N],ans[N],now;
int dis[LogN][N],minv[LogN][N],maxv[LogN][N],lc[LogN][N],rc[LogN][N];
int main()
{
	read(n);read(k);
	F(i,0,n)read(a[i]);
	sort(a,a+n);
	for(int i=0,i_end=1<<k,j=0;i<i_end;++i)
	{
		while(j<n&&a[j]<i)++j;
		dis[k][i]=INF;
		if(a[j]==i)
			minv[k][i]=maxv[k][i]=0;
		else minv[k][i]=INF,maxv[k][i]=-INF;
	}
	for(int i=k-1;~i;--i)
	{
		int half=1<<(k-1-i);
		F(j,0,1<<i)
		{
			lc[i][j]=2*j;rc[i][j]=2*j+1;
			dis[i][j]=min(dis[i+1][lc[i][j]],dis[i+1][rc[i][j]]);
			minv[i][j]=min(minv[i+1][lc[i][j]],minv[i+1][rc[i][j]]+half);
			maxv[i][j]=max(maxv[i+1][lc[i][j]],maxv[i+1][rc[i][j]]+half);
			dis[i][j]=min(dis[i+1][lc[i][j]],dis[i+1][rc[i][j]]);
			dis[i][j]=min(dis[i][j],minv[i+1][rc[i][j]]-maxv[i+1][lc[i][j]]+half);
		}
	}
	ans[0]=dis[0][0];
	F(i,1,1<<k)
	{
		int c=0;
		while(!(i>>c&1))++c;
		now^=1<<(k-1-c);
		F(j,0,1<<c)lc[c][j]^=rc[c][j]^=lc[c][j]^=rc[c][j];
		for(int i=c;~i;--i)
		{
			int half=1<<(k-1-i);
			F(j,0,1<<i)
			{
				dis[i][j]=min(dis[i+1][lc[i][j]],dis[i+1][rc[i][j]]);
				minv[i][j]=min(minv[i+1][lc[i][j]],minv[i+1][rc[i][j]]+half);
				maxv[i][j]=max(maxv[i+1][lc[i][j]],maxv[i+1][rc[i][j]]+half);
				dis[i][j]=min(dis[i+1][lc[i][j]],dis[i+1][rc[i][j]]);
				dis[i][j]=min(dis[i][j],minv[i+1][rc[i][j]]-maxv[i+1][lc[i][j]]+half);
			}
		}
		ans[now]=dis[0][0];
	}
	F(i,0,1<<k)printf("%d ",ans[i]);
	puts("");
	return 0;
}