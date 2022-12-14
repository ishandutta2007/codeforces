#include<iostream>
using namespace std;
int n,x,s;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		s+=(x-1);
		if (s&1) cout<<1<<endl;
		else cout<<2<<endl;
	}
	return 0;
}