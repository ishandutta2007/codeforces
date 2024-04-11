#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,x;
int a[N];
inline void solve()
{
	int sum=0;
	register int i;
	scanf("%d%d",&n,&x);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
		if((sum+=a[i])==x)
		{
			if(i==n)
				return puts("NO"),void();
			else
			{
				swap(a[i],a[i+1]);
				break;
			}
		}
	puts("YES");
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	putchar('\n');
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