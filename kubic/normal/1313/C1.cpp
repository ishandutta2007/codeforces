#include <bits/stdc++.h>
using namespace std;
#define N 1005
#define ll long long
int n,a[N],b[N],ans[N];ll nw,mx;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
	{
		nw=0;b[i]=a[i];
		for(int j=i-1;j>=1;--j) b[j]=min(b[j+1],a[j]);
		for(int j=i+1;j<=n;++j) b[j]=min(b[j-1],a[j]);
		for(int j=1;j<=n;++j) nw+=b[j];
		if(nw>mx) mx=nw,swap(b,ans);
	}for(int i=1;i<=n;++i) printf("%d ",ans[i]);puts("");
	return 0;
}