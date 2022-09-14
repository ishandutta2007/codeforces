#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,k;
long long a[2<<17];
main()
{
	cin>>n>>m>>k;
	vector<pair<long long,int> >A;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		A.push_back(make_pair(a[i],i));
	}
	sort(A.begin(),A.end());
	reverse(A.begin(),A.end());
	long long ans=0;
	vector<int>id;
	for(int i=0;i<m*k;i++)
	{
		ans+=A[i].first;
		id.push_back(A[i].second);
	}
	cout<<ans<<endl;
	sort(id.begin(),id.end());
	for(int i=1;i<k;i++)
	{
		cout<<id[i*m-1]+1<<(i==k-1?"\n":" ");
	}
}