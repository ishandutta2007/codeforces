#include <bits/stdc++.h>
using namespace std;
#define N 105
int T,n,a[N],b[N];
void slv()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d %d",&a[i],&b[i]);
	if(a[1]<b[1]) {puts("NO");return;}
	for(int i=2;i<=n;++i)
		if(a[i]<a[i-1] || b[i]<b[i-1] || a[i]<b[i] || a[i]-a[i-1]<b[i]-b[i-1])
		{puts("NO");return;}puts("YES");
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}