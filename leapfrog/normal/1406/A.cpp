#include<bits/stdc++.h>
using namespace std;
int t,n,a[105],res;
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n),memset(a,0,sizeof(a)),res=0;
		for(int i=1,x;i<=n;i++) scanf("%d",&x),a[x]++;
		int i;for(i=0;i<=101;i++) if(a[i]<2) {res+=i;break;}
		for(;i<=101;i++) if(a[i]<1) {res+=i;break;}
		printf("%d\n",res);
	}
	return 0;
}