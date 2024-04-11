#include<bits/stdc++.h>
using namespace std;
int n,num[77],cur;
long long t;
char s[111111];
int main()
{
	scanf("%d%lld",&n,&t);
	scanf("%s",s);
	for (int i=0;i<n;i++)
	{
		if (i<n-1) t+=(1<<(s[i]-'a'));
		else t-=(1<<(s[i]-'a'));
	}
	if (t<0) 
	{
		printf("No\n");
		return 0;
	}
	for (int i=0;i<n-2;i++)
	{
		num[s[i]-'a'+1]++;
	}
	for (int i=0;i<60;i++)
	{
		cur+=num[i];
		if (!cur && (t&(1ll<<i))) 
		{
			printf("No\n");
			return 0;
		}
		if (t&(1ll<<i)) cur--;
		cur>>=1;
	}
	printf("Yes\n");
	return 0;
}