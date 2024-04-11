#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<climits>
#include<cstdlib>
#define mod 1000000007
#define f(i,n) for(i=1;i<=n;i++)
#define F(i,n) for(i=n;i>=1;i--)
#define FF(i,a,b) for(i=a;i>=b;i--)
#define ff(i,a,b) for(i=a;i<=b;i++)
typedef long long ll;
using namespace std;
const int MAX=(int)1e5+5;
int main(void)
{
	int n,m,k;ll a[5005]={0},p[5005],i,j,f[2][5005]={0};
	scanf("%d%d%d",&n,&m,&k);
	f(i,n) scanf("%I64d",&p[i]);
	f(i,n-m+1) ff(j,i,i+m-1) a[i]+=p[j];
//	f(i,k) for(j=1;j<=1+(i-1)*m;j+=m) f[i][1+(i-1)*m]+=a[j];
//	f(i,k) ff(j,2+(i-1)*m,n) f[i][j]=max(f[i][j-1],a[j]+f[i-1][j-m]);
	f[1][1]=a[1];ff(i,2,n-m+1) f[1][i]=max(f[1][i-1],a[i]);
	ff(i,2,k)
	{
		ff(j,1+(i-2)*m,n-m+1) f[0][j]=f[1][j];
		f[1][1+(i-1)*m]=0;
		for(j=1;j<=1+(i-1)*m;j+=m) f[1][1+(i-1)*m]+=a[j];
		ff(j,2+(i-1)*m,n-m+1) f[1][j]=max(f[1][j-1],a[j]+f[0][j-m]);
	}
	printf("%I64d",f[1][n-m+1]);
}