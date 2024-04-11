#include<iostream>
using namespace std;
int T,N;
int A[2<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		int l=-1,r=-1;
		for(int i=0;i<N-1;i++)if(A[i]==A[i+1])
		{
			if(l==-1)l=i;
			r=i;
		}
		if(l==r)
		{
			cout<<"0\n";
			continue;
		}
		else if(l+1==r)cout<<"1\n";
		else cout<<r-l-1<<"\n";
	}
}