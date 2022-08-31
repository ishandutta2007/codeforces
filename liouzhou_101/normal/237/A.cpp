#include<cstdio>
#include<iostream>

using namespace std;

int a[100][100];

int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[x][y]++;
	}
	int ans=0;
	for (int i=0;i<24;++i)
		for (int j=0;j<60;++j)
			ans=max(ans,a[i][j]);
	cout<<ans<<endl;
	return 0;
}