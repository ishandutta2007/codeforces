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
		int cnt=0;
		for(int i=2;i<N;i++)
		{
			if(A[i-2]<A[i-1]&&A[i-1]>A[i])
			{
				if(i+1<N&&A[i-1]<A[i+1])A[i]=A[i+1];
				else A[i]=A[i-1];
				cnt++;
			}
		}
		cout<<cnt<<"\n";
		for(int i=0;i<N;i++)cout<<A[i]<<(i+1==N?"\n":" ");
	}
}