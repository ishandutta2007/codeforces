#include<iostream>
using namespace std;
int T;
main()
{
	cin>>T;
	for(;T--;)
	{
		long long N;
		cin>>N;
		long long L=0,R=N*(N-1)/2+1;
		while(R-L>1)
		{
			long long mid=(L+R)/2;
			long long B=(mid+1)/2;
			long long n=N-B;
			if(n>0&&n*(n-1)/2>=mid-B)L=mid;
			else R=mid;
		}
		cout<<L<<"\n";
	}
}