#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1005,MOD=998244353;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,k,a[N],v,ans,f[N][N],g[N][N];
int dp(int x)
{
	int ans=0;
	F(i,0,k+1)F(j,0,n+1)f[i][j]=0;
	f[0][0]=1;
	F(i,0,k)
	{
		int left=0;
		g[i][0]=f[i][0];
		F(j,0,n)g[i][j+1]=(g[i][j]+f[i][j+1])%MOD;
		F(j,1,n+1)
		{
			while(a[left]+x<=a[j-1])++left;
			f[i+1][j]=g[i][left];
		}
	}
	F(i,1,n+1)(ans+=f[k][i])%=MOD;
	return ans;
}
int main()
{
	read(n);read(k);
	F(i,0,n)read(a[i]),v=a[i]>v?a[i]:v;
	sort(a,a+n);
	F(i,1,v/(k-1)+2)(ans+=dp(i))%=MOD;
	printf("%d\n",ans);
	return 0;
}