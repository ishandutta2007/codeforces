#include<iostream>
using namespace std;
int T,N,A,B;
string S;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>A>>B>>S;
		int ans=N*A;
		if(B>0)ans+=N*B;
		else
		{
			int c=1;
			for(int i=1;i<N;i++)if(S[i-1]!=S[i])c++;
			ans+=(c/2+1)*B;
		}
		cout<<ans<<endl;
	}
}