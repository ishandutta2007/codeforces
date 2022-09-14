#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,h;
int a[100],b[100];
int ha[100][100];
int ans[100][100];
main()
{
	cin>>n>>m>>h;
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>ha[i][j];
	for(int H=h;H;H--)
	{
		for(int i=0;i<n;i++)
		{
			if(b[i]>=H)
			{
				for(int j=0;j<m;j++)
				{
					if(a[j]>=H)
					{
						if(ha[i][j]==1)ans[i][j]=H,ha[i][j]=0;
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)cout<<ans[i][j]<<(j==m-1?"\n":" ");
	}
}