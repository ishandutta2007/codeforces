#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[200000];
int g;
int main()
{
	scanf("%d %d",&n,&k);
	g=k;
	for(int i=0;i<n;i++) {
		scanf("%d",&a[i]);
		a[i]=a[i]%k;
		if(a[i]==0) a[i]=k;
		g=__gcd(g,a[i]);
	}
	printf("%d\n",k/g);
	for(int i=0;i<k;i=i+g) printf("%d ",i);
	printf("\n");
	return 0;
}