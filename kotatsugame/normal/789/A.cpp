#include<iostream>
#define int long long
using namespace std;
int s;
main()
{
	int n,k,w;cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>w;
		s+=(w-1)/k+1;
	}
	cout<<(s-1)/2+1<<endl;
}