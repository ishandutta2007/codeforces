#include<iostream>
using namespace std;
int n,m;
int k[111],f[111],id[111],ans;
bool ff;
int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		cin>>k[i]>>f[i];
	}
	for (int i=1;i<=100;i++)
	{
		for (int j=1;j<=100;j++)
		{
			if (j%i==0) id[j]=j/i;
			else id[j]=j/i+1;
		}
		ff=0;
		for (int j=1;j<=m;j++)
		{
			if (id[k[j]]!=f[j]) ff=1;
		}
		if (!ff)
		{
			if (ans && id[n]!=ans)
			{
				cout<<-1<<endl;
				return 0;
			}
			ans=id[n];
		}
	}
	cout<<ans<<endl;
	return 0;
}