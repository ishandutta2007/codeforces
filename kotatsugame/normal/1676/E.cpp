#include<iostream>
#include<algorithm>
using namespace std;
int T;
int N,Q;
int A[2<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>Q;
		for(int i=0;i<N;i++)cin>>A[i+1];
		A[0]=0;
		sort(A+1,A+N+1);
		reverse(A+1,A+N+1);
		for(int i=0;i<N;i++)A[i+1]+=A[i];
		for(;Q--;)
		{
			int X;cin>>X;
			int id=lower_bound(A,A+N+1,X)-A;
			if(id==N+1)id=-1;
			cout<<id<<"\n";
		}
	}
}