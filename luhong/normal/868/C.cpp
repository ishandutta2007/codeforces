#include<iostream>
#include<cstdio>
#include<set>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
int a[100000];
int main()
{
	int n,k;scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		int b[5];b[1]=b[2]=b[3]=b[4]=0;
		for(int j=1;j<=k;j++)scanf("%d",&b[j]);
		a[b[1]*1+b[2]*2+b[3]*4+b[4]*8]=1;
	}
	if(a[0])return 0*puts("YES");
	for(int i=0;i<=15;i++)
	for(int j=0;j<=15;j++)
	{
		if(a[i]&&a[j]&&(!(i&j)))return 0*puts("YES");
	}
	puts("NO");
	return 0;
}