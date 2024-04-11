#include <bits\stdc++.h>
using namespace std;
char s[2000000];
int n;
int o[2000000];
int mod=1000000007;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	o[0]=0;
	for(int i=1;i<n;i++)
	{
		o[i]=o[i-1]*2+1;
		if(o[i]>=mod) o[i]-=mod;
	}
	int k=0;
	int r=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='a') k++;
		else
		{
			r+=o[k];
			if(r>=mod) r-=mod;
		}
	}
	printf("%d",r);
	return 0;
}