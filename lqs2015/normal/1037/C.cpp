#include<iostream>
#include<cstdio>
using namespace std;
bool used[1111111];
char a[1111111],b[1111111];
int n,ans;
int main()
{
	scanf("%d",&n);
	scanf("%s%s",a,b);
	for (int i=0;i<n;i++)
	{
		if (a[i]!=b[i]) used[i]=1;
	}
	for (int i=0;i<n-1;i++)
	{
		if (used[i] && used[i+1] && a[i]!=a[i+1])
		{
			used[i]=used[i+1]=0;
			ans++;
		}
	}
	for (int i=0;i<n;i++) 
	{
		if (used[i]) ans++;
	}
	printf("%d\n",ans);
	return 0;
}