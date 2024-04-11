#include<iostream>
using namespace std;
int a[111],n,sum,g;
bool used[111];
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	g=sum*2/n;
	for (int i=1;i<=n;i++)
	{
		if (used[i]) continue;
		for (int j=i+1;j<=n;j++)
		{
			if (used[j]) continue;
			if (a[i]+a[j]==g) 
			{
				cout<<i<<" "<<j<<endl;
				used[i]=used[j]=1;
				break;
			}
		}
	}
	return 0;
}