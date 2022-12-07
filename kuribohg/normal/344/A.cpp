#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100010],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
		if(a[i]!=a[i+1]) ans++;
	printf("%d\n",ans+1);
	return 0;
}