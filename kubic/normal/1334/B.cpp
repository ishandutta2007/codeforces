#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
int T,n,ans,a[N];ll s,m;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		s=ans=0;scanf("%d %lld",&n,&m);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);sort(a+1,a+n+1);
		for(int i=n;i>=1;--i) if(s+a[i]>=m*(n-i+1)) s+=a[i],ans=n-i+1;else break;
		printf("%d\n",ans);
	}return 0;
}