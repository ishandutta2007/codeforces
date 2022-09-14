#include<iostream>
#include<algorithm>
using namespace std;
int T,N;
int A[1<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		if(N%2==1)
		{
			cout<<"NO\n";
			continue;
		}
		sort(A,A+N);
		bool fn=false;
		for(int i=0;i<N/2;i++)
		{
			if(A[i]==A[i+N/2])fn=true;
			int j=i+1==N/2?0:i+1;
			if(A[j]==A[i+N/2])fn=true;
		}
		if(fn)
		{
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		for(int i=0;i<N;i++)
		{
			if(i%2==0)cout<<A[i/2];
			else cout<<A[i/2+N/2];
			cout<<(i+1==N?"\n":" ");
		}
	}
}