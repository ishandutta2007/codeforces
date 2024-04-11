#include <bits/stdc++.h>
using namespace std;
#define N 100005 
int T,n,a[N],b[N];bool ans,vs[2];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=1;vs[0]=vs[1]=0;scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		for(int i=1;i<=n;++i) scanf("%d",&b[i]);
		for(int i=1;i<=n;++i)
		{
			if(a[i]<b[i] && !vs[0]) {ans=0;break;}
			if(a[i]>b[i] && !vs[1]) {ans=0;break;}
			if(a[i]>0) vs[0]=1;if(a[i]<0) vs[1]=1;
		}puts(ans?"YES":"NO");
	}return 0;
}