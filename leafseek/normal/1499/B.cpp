#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=100000+5;
char str[MaxN];
bool usd[MaxN];
int main()
{
	register int T;
	scanf("%d",&T);
	register int n;
	while(T--)
	{
		scanf("%s",str+1);
		n=strlen(str+1);
		register bool Flag=false;
		rep(i,0,n)
		{
			rep(j,0,n)
				usd[j]=false;
			rep(j,0,i)
				if(str[j]=='1')
					usd[j]=true;
			rep(j,i+1,n)
				if(str[j]=='0')
					usd[j]=true;
			register bool flag=true;
			rep(j,1,n)
				if(usd[j-1]&&usd[j])
					flag=false;
			if(flag)
			{
				Flag=true;
				break;
			}
		}
		if(Flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}