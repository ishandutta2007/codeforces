#include<iostream>
using namespace std;
int a[55][55],n,b[55];
bool u[1111111];
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int mx=0;
		for (int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if (a[i][j]>mx) mx=a[i][j];
		}
		while(u[mx]) mx++;
		b[i]=mx;
		u[mx]=true;
	}
	for (int i=1;i<=n;i++)
	{
		if (i!=n) cout<<b[i]<<" ";
		else cout<<b[i]<<endl;
	}
	return 0;
}