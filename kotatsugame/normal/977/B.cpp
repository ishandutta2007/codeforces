#include<iostream>
#include<map>
using namespace std;
int N;
string S;
main()
{
	cin>>N>>S;
	map<string,int>mp;
	for(int i=1;i<N;i++)mp[S.substr(i-1,2)]++;
	int ans=0;
	string ret;
	for(pair<string,int>p:mp)if(ans<p.second)ans=p.second,ret=p.first;
	cout<<ret<<endl;
}