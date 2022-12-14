#include<iostream>
#include<cstdio>
using namespace std;
long long n,sum00,sum10,sum11,sum01,ans;
char a[111111],b[111111];
int main()
{
	scanf("%I64d",&n);
	scanf("%s%s",a,b);
	for (long long i=n-1;i>=0;i--)
	{
		if (a[i]=='0')
		{
			if (b[i]=='0') ans+=(sum10+sum11);
			else ans+=sum10;
		}
		else
		{
			if (b[i]=='0') ans+=(sum00+sum01);
			else ans+=sum00;
		}
		if (a[i]=='0' && b[i]=='0') sum00++;
		else if (a[i]=='0' && b[i]=='1') sum01++;
		else if (a[i]=='1' && b[i]=='0') sum10++;
		else sum11++;
	}
	printf("%I64d\n",ans);
	return 0;
}