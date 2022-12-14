#include<iostream>
using namespace std;
int m,n,mx,maxi;
int a[111][111],b[111];
int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		mx=-1e9;
		maxi=1;
		for (int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if (a[i][j]>mx) 
			{
				mx=a[i][j];
				maxi=j;
			}
		}
		b[maxi]++;
	}
	mx=-1e9;
	maxi=1;
	for (int i=1;i<=n;i++)
	{
		if (b[i]>mx)
		{
			mx=b[i];
			maxi=i;
		}
	}
	cout<<maxi;
	return 0;
}