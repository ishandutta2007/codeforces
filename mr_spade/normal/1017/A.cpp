#include<cstdio>
#include<algorithm>
using std::sort;
const int N=1005;
int n;
int a[N],p[N];
inline bool cmp(int x,int y)
{
	return a[x]>a[y];
}
signed main()
{
	int x;
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=4;j++)
		{
			scanf("%d",&x);
			a[i]+=x;
		}
		p[i]=i;
	}
	sort(p+1,p+n+1,cmp);
	for(i=1;i<=n;i++)
		if(p[i]==1)
		{
			x=i;
			while(x>1&&a[p[x-1]]==a[p[x]])
				x--;
			printf("%d\n",x);
			return 0;
		}
}