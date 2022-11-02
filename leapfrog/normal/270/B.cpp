#include<bits/stdc++.h>
using namespace std;
int n,r,a[100005];
int main()
{
	scanf("%d",&n),r=0;
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=2;i<=n;i++) if(a[i-1]>a[i]) r=i-1;
	return printf("%d\n",r),0;
}