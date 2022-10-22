#include <bits/stdc++.h>
using namespace std;
#define N 200005
int T,n,ps1,ps2,a[N];
void slv()
{
	scanf("%d",&n);ps1=ps2=1;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		if(a[i]<a[ps1]) ps1=i;
		if(a[i]>a[ps2]) ps2=i;
	}printf("%d %d\n",ps1,ps2);
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}