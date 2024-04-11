#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,d,a[501000],q[501000],h=1,t=0;bool f[501000];
int main()
{
	scanf("%d%d%d",&n,&k,&d);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);f[0]=1;
	for(int i=k;i<=n;i++)
	{
		while(h<=t&&f[i-k]>=f[q[t]])t--;q[++t]=i-k;
		while(h<=t&&a[i]-a[q[h]+1]>d)h++;
		if(h<=t)f[i]=f[q[h]];
	}
	puts(f[n]==1?"YES":"NO");return 0;
}