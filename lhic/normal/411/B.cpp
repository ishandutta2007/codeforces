#include <iostream>


using namespace std;

int ans[1000];

int bl[1000];

int a[1000][1000];

int n,m,k;

int main()
{
	cin>>n>>m>>k;
	
	for (int i=0;i<n;++i)
		for (int j=1;j<=m;++j)
			cin>>a[j][i];
	
	for (int i=1;i<=m;++i)
	{
		for (int j=0;j<n;++j)
		{
			if (ans[j] || !a[i][j])
				continue;
			++bl[a[i][j]];
		}
		for (int j=0;j<n;++j)
		{
			if (ans[j])
				continue;
			if (bl[a[i][j]] > 1)
			{
				ans[j]=i;
			}
			else
				--bl[a[i][j]];
		}
	}
	for (int i=0;i<n;++i)
		cout<<ans[i]<<"\n";
}