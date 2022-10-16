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
	int i,n,ans=0;
	char s[105];
	scanf("%d",&n);
	scanf("%s",&s);
	ff(i,0,n-1)
	{
		if(s[i]=='0') break;
		ans++;
	}
	if(i!=n) ans++;
	printf("%d",ans);
}