#include <bits/stdc++.h>
using namespace std;
#define N 200005
int T,n,a[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);n<<=1;
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		sort(a+1,a+n+1);n>>=1;printf("%d\n",a[n+1]-a[n]);
	}return 0;
}