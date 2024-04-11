#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;
pair<int,int>a[1<<17];int n;
main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a,a+n);
	int m=1e9,i=0;
	while(i<n-1&&a[i].first==a[i+1].first)m=min(m,a[i+1].second-a[i].second),i++;
	cout<<m<<endl;
}