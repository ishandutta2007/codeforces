#include<iostream>
using namespace std;
int N,K;
string S;
main()
{
	cin>>N>>K>>S;
	int id=1;
	while(S.substr(id)!=S.substr(0,N-id))id++;
	string ans=S;
	for(int i=1;i<K;i++)ans+=S.substr(N-id);
	cout<<ans<<endl;
}