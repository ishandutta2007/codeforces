#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=100000+5;
int a[MaxN];
int main()
{
	register int t;
	scanf("%d",&t);
	while(t--)
	{
		register int n,k1,k2,w,b;
		scanf("%d%d%d%d%d",&n,&k1,&k2,&w,&b);
		if(!(k1<=k2)) swap(k1,k2);
		register bool flag=true;
		if(!(w<=(k1+((k2-k1)>>1))))
			flag=false;
		if(!(b<=((n-k2)+((k2-k1)>>1))))
			flag=false;
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}