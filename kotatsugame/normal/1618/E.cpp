#include<iostream>
#include<algorithm>
using namespace std;
int T,N;
int B[40404];
int A[40404];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		long long S=0;
		for(int i=0;i<N;i++)
		{
			cin>>B[i];
			S+=B[i];
		}
		if(S%(N*(N+1)/2)!=0)
		{
			cout<<"NO\n";
			continue;
		}
		S/=N*(N+1)/2;
		bool out=false;
		for(int i=0;i<N;i++)
		{
			A[i]=S-B[i]+B[i==0?N-1:i-1];
			if(A[i]%N!=0||A[i]<=0)out=true;
			A[i]/=N;
		}
		if(out)cout<<"NO\n";
		else
		{
			cout<<"YES\n";
			for(int i=0;i<N;i++)cout<<A[i]<<(i+1==N?"\n":" ");
		}
	}
}