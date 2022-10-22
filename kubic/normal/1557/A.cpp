#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define db double
int T,n,a[N];db ans;
void slv()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	sort(a+1,a+n+1);ans=a[n];
	for(int i=1;i<n;++i) ans+=1.0*a[i]/(n-1);
	printf("%.10lf\n",ans);
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}