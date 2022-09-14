#include<iostream>
using namespace std;
int N,M;
string s[20],t[20];
main()
{
	cin>>N>>M;
	for(int i=0;i<N;i++)cin>>s[i];
	for(int i=0;i<M;i++)cin>>t[i];
	int Q;cin>>Q;
	for(;Q--;)
	{
		int y;cin>>y;
		y--;
		cout<<s[y%N]<<t[y%M]<<endl;
	}
}