#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int a[5],i;for (i=1;i<=3;i++) cin>>a[i];
	sort(a+1,a+4);if (a[1]+a[2]>a[3]) cout<<0;
	else cout<<a[3]-a[2]-a[1]+1;
}