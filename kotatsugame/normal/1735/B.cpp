#include<iostream>
using namespace std;
int N,A[100];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		int cnt=0,sz=2*A[0]-1;
		for(int i=1;i<N;i++)
		{
			cnt+=(A[i]-1)/sz;
		}
		cout<<cnt<<"\n";
	}
}