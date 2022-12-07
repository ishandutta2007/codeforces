#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		while(a[i]%2==0) a[i]/=2;
		while(a[i]%3==0) a[i]/=3;
	}
	for(int i=2;i<=n;i++) if(a[i]!=a[1]) {puts("No");return 0;}
	puts("Yes");
	return 0;
}