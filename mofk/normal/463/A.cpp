#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAX (int)1e5+5
#define f(i,n) for(i=1;i<=n;++i)
#define F(i,n) for(i=n;i>=1;--i)
#define ff(i,a,b) for(i=a;i<=b;++i)
typedef long long ll;
using namespace std;
int main(void)
{
	int i,n,s,x[105],y[105],ans=-1;
	scanf("%d%d",&n,&s);
	f(i,n)
	{
		scanf("%d%d",&x[i],&y[i]);
		if(x[i]<=s&&y[i]==0&&ans==-1) ans=0;
		if(x[i]<s&&y[i]!=0&&(100-y[i])>ans) ans=100-y[i];
	}
	printf("%d",ans);
}