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
	ll ans=0,cnt[30]={0},k,i,n;
	char s[MAX];
	scanf("%I64d%I64d",&n,&k);
	scanf("%s",&s);
	ff(i,0,n-1) cnt[s[i]-64]++;
	sort(cnt,cnt+27);
	i=27;
	while(k>cnt[i-1])
	{
		i--;
		ans+=cnt[i]*cnt[i];
		k-=cnt[i];
	}
	ans+=k*k;
	printf("%I64d",ans);
}