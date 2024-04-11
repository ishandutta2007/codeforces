#include<bits/stdc++.h>
using namespace std;
int n,ans;
int main()
{
	cin>>n;
	for (int i=2;i<n;i++)
	{
		ans+=i*(i+1);
	}
	cout<<ans<<endl;
	return 0;
}