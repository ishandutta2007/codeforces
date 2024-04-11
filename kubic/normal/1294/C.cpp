#include <bits/stdc++.h>
using namespace std;
#define N 1005
int T,n,a,b;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		a=b=0;scanf("%d",&n);
		for(int i=2;i*i<=n;++i) if(!(n%i)) {a=i;n/=i;break;}
		for(int i=a+1;i*i<=n;++i) if(!(n%i)) {b=i;n/=i;break;}
		if(!a || !b || n<2 || a==n || b==n) puts("NO");
		else printf("YES\n%d %d %d\n",a,b,n);
	}
	return 0;
}