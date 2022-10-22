#include <bits/stdc++.h>
using namespace std;
int x,ans,a[5];
int main()
{
	scanf("%d %d %d %d",&a[1],&a[2],&a[3],&x);sort(a+1,a+4);
	if(a[2]-a[1]<x) ans=a[1]+x-a[2];if(a[3]-a[2]<x) ans+=a[2]+x-a[3];printf("%d\n",ans);
}