#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[201000],ans=0,h[2020000];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);n=unique(a+1,a+n+1)-a;n--;
	int j=1;
	for(int i=1;i<=2000000;i++)if(j<=n&&i>a[j])h[i]=j++;else h[i]=h[i-1];
	for(int i=1;i<=n;i++)
		for(int j=a[i]*2;j<=2000000;j+=a[i])
			ans=max(ans,a[h[j]]%a[i]);
	printf("%d",ans);
	return 0;
}