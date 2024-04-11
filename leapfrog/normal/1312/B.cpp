#include<bits/stdc++.h>
using namespace std;
int t,n,a[1005];
inline bool cmp(int a,int b) {return a>b;}
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
	}
	return 0;
}