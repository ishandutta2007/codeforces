#include<cstdio>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b) 
const int N(1e6+5);
int n,ans;
int l[N];
int book[N];
signed main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&l[i]);
		book[max(1,i-l[i])]++;
		book[i]--;
	}
	for(i=1;i<=n;i++)
		book[i]+=book[i-1];
	for(i=1;i<=n;i++)
		if(!book[i])
			ans++;
	printf("%d\n",ans);
	return 0;
}