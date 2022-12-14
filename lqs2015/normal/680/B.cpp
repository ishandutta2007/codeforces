#include<iostream>
using namespace std;
bool u[111];
int n,k,ans;
int main()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>u[i];
	}
	for (int i=1;i<=n;i++)
	{
		if (u[i])
		{
			int p=k+k-i;
			if (p<=0 || p>n) ans++;
			else if (u[p]) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}