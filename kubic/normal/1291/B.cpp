#include <bits/stdc++.h>
using namespace std;
#define N 300005
int T,n,a[N];bool tg,fl[N][2];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);tg=fl[n+1][1]=0;
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		for(int i=1;i<=n;++i) fl[i][0]=fl[i-1][0]|(a[i]<i-1);
		for(int i=n;i>=1;--i) fl[i][1]=fl[i+1][1]|(a[i]<n-i);
		for(int i=1;i<=n;++i) if(!fl[i-1][0] && !fl[i+1][1] && a[i]>=i-1 && a[i]>=n-i)
		{tg=1;puts("Yes");break;}if(!tg) puts("No");
	}return 0;
}