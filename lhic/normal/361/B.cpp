#include <iostream>

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	k=n-k;
	if (k==0)
	{
		cout<<-1;
		return 0;
	}
	for (int i=0;i<k;i++)
	{
		cout<<(i+1)%k+1<<" ";
	}
	for (int i=k;i<n;i++)
	{
		cout<<i+1<<" ";
	}
}