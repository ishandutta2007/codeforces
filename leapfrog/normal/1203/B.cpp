#include<bits/stdc++.h>
using namespace std;
int q,n,a[405];
int main()
{
	for(scanf("%d",&q);q--;)
	{
		scanf("%d",&n),n<<=2;int f=1,k;
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		sort(a+1,a+n+1),k=a[1]*a[n-1];
		for(int i=1;i<=n&&f;i+=2) if(a[i]!=a[i+1]) f=0;
		for(int i=3,j=n-3;i<=j&&f;i+=2,j-=2) if(k!=a[i]*a[j]) f=0;
		if(f) puts("YES");else puts("NO");
	}
	return 0;
}