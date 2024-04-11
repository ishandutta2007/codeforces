#include <bits/stdc++.h>
using namespace std;
#define N 100005
int T,n,hd,cnt,ans,a[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=30;i>=0;--i)
	{
		hd=cnt=0;
		for(int j=1;j<=n;++j) if(a[j]&(1<<i)) ++cnt,hd=j;
		if(cnt==1) break;else hd=0;
	}if(!hd) hd=1;printf("%d ",a[hd]);
	for(int i=1;i<=n;++i) if(i!=hd) printf("%d ",a[i]);return 0;
}