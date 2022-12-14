#include<bits/stdc++.h>
using namespace std;
int t,n,a[222222];
bool used[222222],flg;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for (int i=0;i<n;i++) used[i]=0;
		flg=0;
		for (int i=0;i<n;i++)
		{
			if (used[((i+a[i])%n+n)%n]) flg=1;
			used[((i+a[i])%n+n)%n]=1;
		}
		if (!flg) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}