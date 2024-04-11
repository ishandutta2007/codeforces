#include<iostream>
using namespace std;
int T,N,A,B;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>A>>B;
		string ans="";
		for(int i=0;i<N;i++)
		{
			if(i<B)ans+=(char)(i+'a');
			else if(i<A)ans+=(char)(B-1+'a');
			else ans+=ans[i-A];
		}
		cout<<ans<<endl;
	}
}