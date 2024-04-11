#include<iostream>
using namespace std;
int T;
int A[50];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		int N;cin>>N;
		int mn=1e9;
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			mn=min(mn,A[i]);
		}
		int s=0;
		for(int i=0;i<N;i++)s+=A[i]-mn;
		cout<<s<<"\n";
	}
}