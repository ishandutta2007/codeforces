#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int test,n,len,xlen,x,tim,l,r,ln;
char s[1111111];
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%s",&x,s);
		len=xlen=strlen(s);
		n=strlen(s);
		if (n==1)
		{
			printf("1\n");
			continue;
		}
		for (int i=0;i<x;i++)
		{
			tim=s[i]-'0'-1;l=i+1;r=len-1;
			if (tim && len<x)
			{
				for (int j=1;j<=tim;j++)
				{
					for (int k=l;k<=r;k++)
					{
						s[len++]=s[k];
						if (len>=x) break;
					}
					if (len>=x) break;
				}
			}
			ln=(xlen-i-1)%mod;
			xlen=(1ll*ln*tim+xlen)%mod;
		}
		printf("%d\n",(xlen+mod)%mod);
	}
	return 0;
}