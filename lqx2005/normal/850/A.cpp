#include<bits/stdc++.h>
using namespace std;
int a[10005][6];
int k[10005];
int main()
{
	int n,all=0;
	cin>>n;
	memset(k,0,sizeof(k));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4]>>a[i][5];
	}
	for(int i=1;i<=n;i++)
	{
		int kk=1;
		for(int j=1;j<=n;j++)
		{
			for(int r=j+1;r<=n;r++)
			{
				if(i!=r&&i!=j)
				{
					int ans=0;
					for(int q=1;q<=5;q++)
					{
						ans=ans+(a[j][q]-a[i][q])*(a[r][q]-a[i][q]);
					}
					if(ans>0)
					{
						kk=0;
						break;
					} 							
				}
			}
			if(kk==0)
			{
				break;
			}
		}
		if(kk) 
		{
			k[i]=1;
			all++;	
		}		
	}
	cout<<all<<endl;
	for(int i=1;i<=n;i++)
	{
		if(k[i]) 
		{
			cout<<i<<" ";	
		}
	}
	cout<<endl;
	return 0;
}