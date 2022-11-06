#include<cstdio>
#include<algorithm>
using std::sort;
const int N=1e5+5;
int n;
int a[N];
signed main()
{
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if(a[1]==a[n])
		return puts("0"),0;
	int l=1,r=n;
	while(a[l]==a[1])
		l++;
	while(a[r]==a[n])
		r--;
	printf("%d\n",r-l+1);
	return 0;
}