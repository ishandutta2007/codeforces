#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=405,INF=0x3fffffff;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,m,a[N],f[N][N][N];
long long ans;
int main()
{
	read(n,m);
	F(i,0,n)read(a[i]);
	F(i,0,n)F(j,0,n)F(k,0,n+1)f[i][j][k]=INF;
	F(i,0,n)F(k,0,n+1)f[i][i][k]=0;
	F(i,0,n)F(j,i,n)f[i][j][1]=a[j]-a[i];
	F(k,1,n)F(i,0,n)for(int j=i,mid=i;j<n;++j)
	{
		while(mid<j&&max(f[i][mid][k],f[mid][j][1])>max(f[i][mid+1][k],f[mid+1][j][1]))++mid;
		f[i][j][k+1]=max(f[i][mid][k],f[mid][j][1]);
	}
	while(m--)
	{
		int s,t,c,r;read(s,t,c,r);
		ans=max(ans,(long long)c*f[--s][--t][r+=r<n]);
	}
	printf("%lld\n",ans);
	return 0;
}