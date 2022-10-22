#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=100000+5;
char str[MaxN];
int main()
{
	register int T;
	scanf("%d",&T);
	register int n,k;
	while(T--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",str+1);
		register bool flag=true;
		rep(i,1,k)
			if(!(str[i]==str[n-i+1]))
				flag=false;
		if(flag&&((k<<1)!=n))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}