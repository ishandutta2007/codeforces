#include<iostream>
#include<cmath>
using namespace std;
int n,a[11],b[11],ans,x,p;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		a[x]++;
	}
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		b[x]++;
	}
	for (int i=1;i<=5;i++)
	{
		p=abs(a[i]-b[i]);
		if (p%2) 
		{
			cout<<-1<<endl;
			return 0;
		}
		ans=ans+p/2;
	}
	cout<<(ans+1)/2<<endl;
	return 0;
}