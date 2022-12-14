#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const long long mod=1e9+7;
char c[1111111];
long long cnt,ans,bc,pr;
int main()
{
	scanf("%s",c);
	for (int i=strlen(c)-1;i>=0;i--)
	{
		if (c[i]=='a')
		{
			bc=(cnt+pr)%mod;
			ans=(ans+bc)%mod;
			pr=(bc*2)%mod;
			cnt=0;
		}
		else cnt++;
	}
	printf("%I64d",ans);
	return 0;
}