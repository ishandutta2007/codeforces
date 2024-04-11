#include<bits/stdc++.h>
using namespace std;

int n;
int a[210];
char s[210];
bool ok(int x)
{
	int sum=0,num=0;
	for (int i=1;i<=n;i++)
	{
		sum+=a[i];
		if (sum>x)	return false;
		if (sum==x)	sum=0,num++;
	}
	if (sum!=0)	return false;
	return num>1;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
		a[i]=s[i]-'0';
	for (int i=1;i<n;i++)
	{
		int sum=0;
		for (int j=1;j<=i;j++)
			sum+=a[j];
		if (ok(sum))	{printf("YES\n");return 0;}
	}
	printf("NO\n");
	return 0;
}