#include <bits/stdc++.h>
using namespace std;
#define N 200005
int T,n,ans,a[N];
void slv()
{
	scanf("%d",&n);ans=0;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) for(int j=i;j<=n;++j) ans+=j-i+1;
	for(int i=1;i<=n;++i) if(!a[i]) ans+=i*(n-i+1);
	printf("%d\n",ans);
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}