#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T,N,A[2<<17];
string S;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		cin>>S;
		vector<int>R,B;
		for(int i=0;i<N;i++)(S[i]=='R'?R:B).push_back(A[i]);
		sort(R.begin(),R.end());
		sort(B.begin(),B.end());
		bool ok=true;
		for(int i=0;i<B.size();i++)
		{
			if(B[i]<=i)ok=false;
		}
		for(int i=0;i<R.size();i++)
		{
			if(R[R.size()-i-1]>N-i)ok=false;
		}
		cout<<(ok?"YES\n":"NO\n");
	}
}