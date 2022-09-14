#include<iostream>
using namespace std;
int n,m;
int c[1000],a[1001];
main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>c[i];
	for(int i=0;i<m;i++)cin>>a[i];
	int cnt=0,j=0;
	for(int i=0;i<n;i++)
	{
		if(a[j]>=c[i])
		{
			cnt++;
			j++;
		}
	}
	cout<<cnt<<endl;
}