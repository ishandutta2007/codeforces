#include<iostream>
using namespace std;
int T,N,K;
string S;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>K>>S;
		bool r=true;
		for(int i=0;i<N;i++)if(S[i]!=S[N-i-1])r=false;
		cout<<(K==0||r?1:2)<<"\n";
	}
}