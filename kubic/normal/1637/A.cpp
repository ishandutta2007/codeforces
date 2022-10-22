#include <bits/stdc++.h>
using namespace std;
#define N 200005
int T,n,a[N];bool ans;
void slv()
{
	scanf("%d",&n);ans=1;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<n;++i) if(a[i]>a[i+1]) ans=0;
	puts(ans?"NO":"YES");
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}