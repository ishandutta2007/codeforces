#include<iostream>
#include<algorithm>
using namespace std;
int T,N,A[15];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		int c=0,mx=0,sum=0;
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			while(A[i]%2==0)A[i]/=2,c++;
			if(mx<A[i])mx=A[i];
			sum+=A[i];
		}
		cout<<sum-mx+((long long)mx<<c)<<"\n";
	}
}