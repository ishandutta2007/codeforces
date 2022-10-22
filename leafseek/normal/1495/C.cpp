#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxLen=500+5;
char str[MaxLen][MaxLen];
int main()
{
	register int T;
	scanf("%d",&T);
	register int n,m;
	while(T--)
	{
		scanf("%d%d",&n,&m);
		rep(i,1,n)
			scanf("%s",str[i]+1);
		rep(i,1,n)
		{
			if(i%3!=1)
				continue;
			rep(j,1,m)
				str[i][j]='X';
		}
		rep(i,1,n)
		{
			if(i%3!=2)
				continue;
			register int posA=0,posB=0;
			register bool flagA=false,flagB=false;
			rep(j,1,m)
				if(str[i][j]=='X')
					{posA=j,flagA=true;break;}
			rep(j,1,m)
				if(str[i+1][j]=='X')
					{posB=j,flagB=true;break;}
			if(flagA)
				str[i+1][posA]='X';
			else if(flagB)
				str[i][posB]='X';
			else
				str[i][1]=str[i+1][1]='X';
		}
		if(n%3==0)
			rep(j,1,m)
			{
				if(str[n-1][j]=='X')
					str[n][j]='X';
				if(str[n][j]=='X')
					str[n-1][j]='X';
			}
		rep(i,1,n)
			printf("%s\n",str[i]+1);
	}
	return 0;
}