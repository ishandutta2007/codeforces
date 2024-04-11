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
	ll ans=1;
	int i,j,n,m,k,flag;
	long int cnt[105]={0};
	char c[105][105];
	scanf("%d%d",&n,&m);
	f(i,n) scanf("%s",&c[i]);
	ff(j,0,m-1)
	{
		cnt[j]=1;
		ff(i,2,n) 
		{
			flag=0;
			f(k,i-1) if(c[i][j]==c[k][j]) flag++;
			if(flag==0) cnt[j]++;
		}
	}
	ff(j,0,m-1)
	{
		ans*=cnt[j];
		ans%=(int)1e9+7;
	}
	printf("%ld",ans);
}