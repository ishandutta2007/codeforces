#include <bits/stdc++.h>
using namespace std;
#define N 1005
int T,n,m,a[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);m=log2(n);--n;a[0]=1;printf("%d\n",m);
		for(int i=1;i<=m;++i)
		{
			a[i]=ceil(1.0*n/((1<<m-i+1)-1));n-=a[i];
			printf("%d ",a[i]-a[i-1]);
		}puts("");
	}return 0;
}