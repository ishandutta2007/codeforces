#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=1000000+5;
char str[MaxN];
char a[MaxN],b[MaxN];
int main()
{
	register int T;
	scanf("%d",&T);
	register int n;
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",str+1);
		register int cnt=0;
		rep(i,1,n+2)
			a[i]=b[i]=0;
		rep(i,1,n)
			if(str[i]=='1')
				++cnt;
		if(cnt&1)
		{
			printf("NO\n");
			continue;
		}
		register int deg=0;
		rep(i,1,n)
		{
			if(str[i]=='1')
			{
				++deg;
				if((deg<<1)<=cnt)
				{
					a[i]='(';
					b[i]='(';
				}
				else
				{
					a[i]=')';
					b[i]=')';
				}
			}
		}
		deg=0;
		rep(i,1,n)
		{
			if(str[i]=='0')
			{
				++deg;
				if(deg&1)
				{
					a[i]='(';
					b[i]=')';
				}
				else
				{
					a[i]=')';
					b[i]='(';
				}
			}
		}
		register bool flag=true;
		register int p1=0,p2=0;
		rep(i,1,n)
		{
			if(a[i]=='(')
				++p1;
			else
				--p1;
			if(p1<0)
			{
				flag=false;
				break;
			}
		}
		if(p1!=0)
			flag=false;
		rep(i,1,n)
		{
			if(b[i]=='(')
				++p2;
			else
				--p2;
			if(p2<0)
			{
				flag=false;
				break;
			}
		}
		if(p2!=0)
			flag=false;
		if(!flag)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		printf("%s\n",a+1);
		printf("%s\n",b+1);
	}
	return 0;
}