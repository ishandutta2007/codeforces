#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
long long a[4];
int main()
{
	for(int i=1;i<=3;i++) scanf("%I64d",&a[i]);
	sort(a+1,a+4);
	if(a[3]>=2*(a[1]+a[2])) printf("%I64d\n",a[1]+a[2]);
	else printf("%I64d\n",(long long)(a[1]+a[2]+a[3])/3);
	return 0;
}