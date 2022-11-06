#include<cstdio>
const int N=25;
int n;
int a[N];
signed main()
{
	int cur;
	register int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<1<<n;i++)
	{
		cur=0;
		for(j=0;j<n;j++)
			if(i>>j&1)
				cur+=a[j];
			else
				cur-=a[j];
		if(cur%360==0)
			return puts("YES"),0;
	}
	puts("NO");
	return 0;
}