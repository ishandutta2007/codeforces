#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,b[222222],a[222222],mx;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	a[1]=b[1];mx=a[1];
	for (int i=2;i<=n;i++)
	{
		a[i]=b[i]+mx;
		mx=max(mx,a[i]);
	}
	for (int i=1;i<=n;i++) printf("%d ",a[i]);
	printf("\n");
	return Accepted;
}