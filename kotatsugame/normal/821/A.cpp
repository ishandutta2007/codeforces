#include<iostream>
using namespace std;
int a[50][50];
main()
{
	int n;cin>>n;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
	bool flag=true;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]==1)continue;
			int now=a[i][j];
			bool ok=false;
			for(int k=0;k<n;k++)
			{
				for(int l=0;l<n;l++)
				{
					ok|=now==a[i][k]+a[l][j];
				}
			}
			flag&=ok;
		}
	}
	cout<<(flag?"Yes":"No")<<endl;
}