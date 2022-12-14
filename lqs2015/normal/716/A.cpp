#include<iostream>
using namespace std;
int x,prev,c,n,ans;
int main()
{
	cin>>n>>c;
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		if (x-prev>c) ans=1;
		else ans++;
		prev=x;
	}
	cout<<ans<<endl;
	return 0;
}