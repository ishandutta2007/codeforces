#include<iostream>
using namespace std;
bool f[1111111];
int mx[1111111],mn,n;
int main()
{
	for (int i=2;i<=1000000;i++)
	{
		if (!f[i]) mx[i]=i;
		for (int j=i+i;j<=1000000;j+=i)
		{
			mx[j]=max(mx[j],mx[i]);
			f[j]=1;
		}
	}
	cin>>n;
	mn=1e9;
	for (int i=n-mx[n]+1;i<=n;i++)
	{
		if (!f[i]) continue;
		mn=min(mn,i-mx[i]+1);
	}
	cout<<mn<<endl;
	return 0;
}