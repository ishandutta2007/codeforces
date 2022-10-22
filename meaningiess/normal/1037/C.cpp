#include<iostream>
#include<cstdio>
using namespace std;
int n,f[1000010],i;
char a[1000010],b[1000010];
int main()
{
	scanf("%d",&n);scanf("%s",a+1);scanf("%s",b+1);
	if (a[1]!=b[1]) f[1]=1;
	for (i=2;i<=n;i++)
	{
		f[i]=f[i-1];if (a[i]!=b[i]) f[i]++;
		if (a[i]==b[i-1 ]&& a[i-1]==b[i]) f[i]=min(f[i],f[i-2]+1);
	}
	cout<<f[n];
}