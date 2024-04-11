#include<iostream>
using namespace std;
int n;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		if (i-1) cout<<" ";
		if (i<n) 
		{
			if (i&1) cout<<"I hate that";
			else cout<<"I love that";
			continue;
		}
		if (i&1) cout<<"I hate it";
		else cout<<"I love it";
	}
	return 0;
}