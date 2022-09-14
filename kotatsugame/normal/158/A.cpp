#include<iostream>
using namespace std;
int main()
{
	int n,k;cin>>n>>k;
	int a[99];for(int i=0;i<n;i++)cin>>a[i];
	int c=0;
	for(int i=0;i<k;i++)
	{
		if(a[i]<=0)break;
		c++;
	}
	if(a[k-1]>0)
	{
		int i=k;
		while(i<n&&a[i++]==a[k-1])c++;
	}
	cout<<c<<endl;
}