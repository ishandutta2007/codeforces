#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int main()
{
	int n,i,g1=0,g2=0,g3=0,ans=0,mod,x=0;
	cin >> n;
	int arr[n];
	for (i=0;i<n;i++)
	{
		cin >> arr[i];
		if (arr[i]==1)
		g1++;
		else if (arr[i]==2)
		g2++;
		else if (arr[i]==3)
		g3++;
		else
		{
			ans++;
			arr[i]=0;
		}
	}
	sort (arr,arr+n);
	if (g2==0 || g2==1)
	goto ex;
	mod=g2/2;
	ans+=mod;
	g2-=mod*2;
	for (i=0;i<n && x<mod*2;i++)
	{
		if (arr[i]==2)
		{
			arr[i]=0;
			x++;
		}
	}
	ex: sort (arr,arr+2);
	if (g3==0 || g1==0)
	goto out;
	mod=min(g3,g1);
	g3-=mod;
	g1-=mod;
	ans+=mod;
	x=0;
	for (i=0;i<n && x<mod;i++)
	{
		if (arr[i]==1)
		{
			arr[i]=0;
			x++;
		}
	}
	out: ans+=g3;
	for (i=0;i<n;i++)
	{
		if (arr[i]==3)
		arr[i]=0;
	}
	if (g2==0)
	{
		if (g1<=4 && g1>0)
		{
			cout << ans+1;
			exit(0);
		}
		mod=g1/4;
		if (g1%4)
		cout << ans+mod+1;
		else
		cout << ans+mod;
	}
	else
	{
		if (g1==0 || g1==1 || g1==2)
		cout << ans+1;
		else
		{
			ans++;
			g1-=2;
			mod=g1/4;
			if (g1%4)
			cout << ans+mod+1;
			else
			cout << ans+mod;
		}
	}
}