#include<iostream>
using namespace std;
int n,a[55][55];
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		cin>>a[i][j]; 
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (a[i][j]!=1)
			{
				bool f=0;
				for (int x=1;x<=n;x++)
				{
					for (int y=1;y<=n;y++)
					{
						if (a[x][j]+a[i][y]==a[i][j]) f=1;
					}
				}
				if (!f)
				{
					cout<<"No"<<endl;
					return 0;
				}
			}
		}
	}
	cout<<"Yes"<<endl;
	return 0;
 }