#include <bits/stdc++.h>
using namespace std;
#define N 10005
int T,n,m,t,a[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		sort(a+1,a+n+1);t=unique(a+1,a+n+1)-a-1;
		if(t>m) {puts("-1");continue;}
		for(int i=t+1;i<=m;++i) a[i]=a[t];
		printf("%d\n",n*m);
		for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
			printf("%d ",a[j]);puts("");
	}return 0;
}