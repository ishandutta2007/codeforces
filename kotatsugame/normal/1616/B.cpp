#include<iostream>
using namespace std;
int T;
string S;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		int N;
		cin>>N>>S;
		if(N==1||S[0]<=S[1])
		{
			cout<<S[0]<<S[0]<<"\n";
			continue;
		}
		int k=0;
		while(k+1<N&&S[k]>=S[k+1])k++;
		cout<<S.substr(0,k+1);
		for(int i=k+1;i--;)cout<<S[i];
		cout<<"\n";
	}
}