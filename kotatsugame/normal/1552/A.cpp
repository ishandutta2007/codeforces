#include<iostream>
#include<algorithm>
using namespace std;
int T,N;
string S;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>S;
		string V=S;
		sort(V.begin(),V.end());
		int k=0;
		for(int i=0;i<N;i++)if(S[i]!=V[i])k++;
		cout<<k<<"\n";
	}
}