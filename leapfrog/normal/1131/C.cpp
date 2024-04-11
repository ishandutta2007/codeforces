#include<bits/stdc++.h>
using namespace std;
int n,a[100005],o[100005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(int i=1,l=1,r=n;i<=n;) o[l++]=a[i++],i<=n?o[r--]=a[i++]:0;
	for(int i=1;i<=n;i++) printf("%d%c",o[i],i==n?'\n':' ');
	return 0;
}