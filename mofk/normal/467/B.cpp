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
	int n,k,m,i,j,x[1005],ans=0,cnt;char temp[25];
	scanf("%d%d%d",&n,&m,&k);
	f(i,m+1) scanf("%d",&x[i]);
	f(i,m)
	{
		cnt=0;
		itoa(x[i]^x[m+1],temp,2);
		ff(j,0,strlen(temp)-1) if(temp[j]=='1') cnt++;
		if(cnt<=k) ans++;
	}
	printf("%d",ans);
}