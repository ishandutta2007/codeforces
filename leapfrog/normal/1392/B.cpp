//
//  
//
//
//  
//   
//
#include<bits/stdc++.h>
using namespace std;
int t,n,a[200005];long long k;
inline void wrk()
{
	int x=-1e9-5;
	for(int i=1;i<=n;i++) x=max(x,a[i]);
	for(int i=1;i<=n;i++) a[i]=x-a[i];
}
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d%lld",&n,&k);
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		if(n==1) {puts("0");continue;}
		wrk();if(!(k&1)) wrk();
		for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
	}
	return 0;
}