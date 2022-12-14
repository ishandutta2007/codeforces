#include<bits/stdc++.h>
using namespace std;
char s[333333];
int n,L[333333];
long long ans;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	
	for (int i=0;i<n;i++)
	{
		if (i) L[i]=L[i-1];
		else L[i]=-1;
		for (int j=1;i-j*2>L[i];j++)
		{
			if (s[i]==s[i-j] && s[i]==s[i-2*j]) 
			{
				L[i]=i-2*j;
				break;
			}
		}
		ans+=(L[i]+1);
	}
	printf("%lld\n",ans);
	return 0;
}