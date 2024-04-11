#include<cstdio>
#include<cstring>
#include<algorithm>
using std::min;
typedef long long ll;
const int N=2e5+5;
int n,p,k;
long long ans;
const long long inf=0x3f3f3f3f3f3f3f3f;
char s[N];
int a[N];
inline void solve()
{
	int x,y;
	register int i;
	ans=inf;
	scanf("%d%d%d",&n,&p,&k);
	scanf("%s",s+1);scanf("%d%d",&x,&y);
	for(i=1;i<=n;i++)
		a[i]=1-(s[i]-'0');
	for(i=n;i>=p;i--)
	{
		a[i]+=a[i+k];
		ans=min(ans,(ll)y*(i-p)+(ll)x*a[i]);
	}
	memset(a+1,0,sizeof(int)*n);
	printf("%lld\n",ans);
	return;
}
signed main()
{
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}