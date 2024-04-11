#include <bits/stdc++.h>
using namespace std;
#define N 1005
int T,n,s,k,ps,ans,a[N];
int min(int x,int y) {return x<y?x:y;}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&n,&s,&k);ans=n;
		for(int i=1;i<=k;++i) scanf("%d",&a[i]);
		sort(a+1,a+k+1);
		ps=lower_bound(a+1,a+k+1,s)-a;
		if(ps>k || a[ps]>s) {puts("0");continue;}
		if(a[1]>1) ans=min(ans,a[ps]-a[1]+1);
		if(a[k]<n) ans=min(ans,a[k]+1-a[ps]); 
		for(int i=ps;i<k;++i) if(a[i+1]>a[i]+1)
			ans=min(ans,a[i]+1-a[ps]);
		for(int i=ps;i>1;--i) if(a[i-1]<a[i]-1)
			ans=min(ans,a[ps]-a[i]+1);
		printf("%d\n",ans);
	}return 0;
}