#include<iostream>
#include<vector>
using namespace std;
int a[111111],t;
vector<int> v[111111];
bool vis[111111];
int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]==i)
		{
			cout<<"YES"<<endl;
			for (int j=1;j<=n;j++)
			{
				if (i==j) continue;
				cout<<i<<" "<<j<<endl;
			}
			return 0;
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (vis[i]) continue;
		int k=i;t++;
		while(!vis[k])
		{
			vis[k]=1;
			v[t].push_back(k);
			k=a[k];
		}
		if (v[t].size()%2==1)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	for (int i=1;i<=t;i++)
	{
		if (v[i].size()==2)
		{
			cout<<"YES"<<endl;
			cout<<v[i][0]<<" "<<v[i][1]<<endl;
			for (int j=1;j<=t;j++)
			{
				if (i==j) continue;
				for (int k=0;k<v[j].size();k++)
				{
					cout<<v[i][k%2]<<" "<<v[j][k]<<endl;
				}
			}
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}