#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
pair<int,int>b[2<<17];
int a[2<<17],out[2<<17];
main()
{
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)
	{
		cin>>b[i].first;
		b[i].second=i;
	}
	sort(a,a+n);
	sort(b,b+n);
	for(int i=0;i<n;i++)
	{
		out[b[i].second]=a[n-i-1];
	}
	for(int i=0;i<n;i++)cout<<out[i]<<(i==n-1?"\n":" ");
}