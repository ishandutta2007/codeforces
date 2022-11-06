#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define re register
int a[100100],b[100100];
int main()
{
	re int n;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(re int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
	}if(a[1]!=b[1]||a[n]!=b[n]){puts("No");return 0;}
	for(re int i=1;i<n;i++)a[i]=a[i+1]-a[i],b[i]=b[i+1]-b[i];
	sort(a+1,a+n);
	sort(b+1,b+n);
	for(re int i=1;i<n;i++)if(a[i]!=b[i]){puts("No");return 0;}
	puts("Yes");
}