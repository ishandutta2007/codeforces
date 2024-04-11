#include<cstdio>
#include<algorithm>
using std::sort;
const int N(1e5+5);
int n;
long long sum;
long long a[N],b[N];
signed main()
{
	int i;
	scanf("%I64d\n",&n);
	for(i=1;i<=n;i++)
		scanf("%I64d",&a[i]),sum+=a[i];
	for(i=1;i<=n;i++)
		scanf("%I64d",&b[i]);
	sort(b+1,b+n+1);
	puts(sum<=b[n-1]+b[n]?"YES":"NO");
	return 0;
}