#include <bits/stdc++.h>

using namespace std;

signed main()
{
	int ans=0;
	cout<<"? ";
	for(int i=1; i<=100; i++)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	int cac;
	cin>>cac;
	ans|=(cac&((1<<14)-(1<<7)));
	cout<<"? ";
	for(int i=1; i<=100; i++)
	{
		cout<<(i<<7)<<" ";
	}
	cout<<endl;
	cin>>cac;
	ans|=(cac&((1<<7)-1));
	cout<<"! "<<ans<<endl;
	
}