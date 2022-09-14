#include<iostream>
#include<algorithm>
using namespace std;
int T;
string S,A;
int inv[256];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>S>>A;
		for(int i=0;i<S.size();i++)inv[S[i]]=i;
		int ans=0;
		for(int i=1;i<A.size();i++)ans+=abs(inv[A[i-1]]-inv[A[i]]);
		cout<<ans<<endl;
	}
}