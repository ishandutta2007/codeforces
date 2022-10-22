#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define M 400005
#define ll long long
int D=4e5,n,a[N];ll ans,c[M<<1];
int main()
{
	scanf("%d",&n);
	for(int i=1,x;i<=n;++i) scanf("%d",&x),c[x-i+D]+=x,ans=max(ans,c[x-i+D]);
	printf("%lld\n",ans);return 0;
}