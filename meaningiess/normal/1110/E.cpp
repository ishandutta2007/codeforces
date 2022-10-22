#include<bits/stdc++.h>
#define N 100005
using namespace std;
int a[N],n,b[N],i;
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	for (i=1;i<=n;i++) scanf("%d",&b[i]);
	if (a[1]!=b[1] && a[n]!=b[n]) puts("No"),exit(0);
	for (i=1;i<n;i++) b[i]=b[i+1]-b[i];sort(b+1,b+n);
	for (i=1;i<n;i++) a[i]=a[i+1]-a[i];sort(a+1,a+n);
	for (i=1;i<n;i++) if(a[i]!=b[i]) puts("No"),exit(0);
	puts("Yes");
}