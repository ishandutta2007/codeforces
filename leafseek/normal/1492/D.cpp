#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
inline void Write(const register int dis,const register char typ)
	{rep(i,1,dis) printf("%c",typ);}
int main()
{
	register int a,b,k;
	scanf("%d%d%d",&a,&b,&k);
	if(k==0)
	{
		printf("Yes\n");
		Write(b,'1'),Write(a,'0'),printf("\n");
		Write(b,'1'),Write(a,'0'),printf("\n");
	}
	else if(b>=2&&a>=1&&a+b>=k+2)
	{
		printf("Yes\n");
		register int help=min(a-1,k-1);
		Write(b-(k-help),'1'),Write(a-(help+1),'0'),Write(1,'1'),Write((k-1)-help,'1'),Write(help,'0'),Write(1,'0'),printf("\n");
		Write(b-(k-help),'1'),Write(a-(help+1),'0'),Write(1,'0'),Write((k-1)-help,'1'),Write(help,'0'),Write(1,'1'),printf("\n");
	}
	else
		printf("No\n");
	return 0;
}