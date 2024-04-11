#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAX (int)1e5+5
#define f(i,n) for(i=1;i<=n;i++)
#define F(i,n) for(i=n;i>=1;i--)
#define ff(i,a,b) for(i=a;i<=b;i++)
typedef long long ll;
using namespace std;
int main(void)
{
	int n,m,i,ans=0,flag=0,j,k;
	char a[105][105];
	scanf("%d%d",&n,&m);
	f(i,n) scanf("%s",&a[i]);
	f(i,n) ff(j,0,m-1)
	{
		flag=0;
		f(k,n) if(a[i][j]<a[k][j]) flag=1;
		if(flag==0)
		{
			ans++;break;
		}
	}
	printf("%d",ans);
}