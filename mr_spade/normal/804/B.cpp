#include<cstdio>
#include<cstring>
const int S(1e6+5),mod(1e9+7);
char s[S];
int len,ans,check;
signed main()
{
	int i;
	scanf("%s",s+1);
	len=strlen(s+1);
	for(i=len;i>=1;i--)
		if(s[i]=='a')
			ans=(ans+check)%mod,check=(check<<1)%mod;
		else
			check=(check+1)%mod;
	printf("%d\n",ans);
	return 0;
}