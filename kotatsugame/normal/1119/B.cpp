#include<iostream>
#include<vector>
using namespace std;
int n;
long long h;
main()
{
	cin>>n>>h;
	vector<int>a;
	int ret=0;
	for(int y=0;y<n;y++)
	{
		int x;cin>>x;
		vector<int>now;
		int i=0;
		for(;i<a.size()&&a[i]<x;i++)now.push_back(a[i]);
		now.push_back(x);
		for(;i<a.size();i++)now.push_back(a[i]);
		long long ans=0;
		a=now;
		for(int j=a.size()-1;j>=0;j-=2)ans+=a[j];
		if(ans<=h)ret=y+1;
	}
	cout<<ret<<endl;
}