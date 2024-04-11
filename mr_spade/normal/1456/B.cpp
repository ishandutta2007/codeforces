#include<cstdio>
#include<algorithm>
using std::min;
const int N=1e5+5;
int n,ans;
int a[N];
signed main()
{
	register int i,j,k;
	scanf("%d",&n);
	if(n>=100)
		return puts("1"),0;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]),a[i]^=a[i-1];
	ans=0x3f3f3f3f;
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
			for(k=j+1;k<=n;k++)
				if((a[j]^a[i-1])>(a[k]^a[j]))
					ans=min(ans,k-i-1);
	if(ans==0x3f3f3f3f)
		ans=-1;
	printf("%d\n",ans);
	return 0;
}