#include<iostream>
using namespace std;
int N;
string S;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>S;
	{
		int fst=0;
		while(fst<N&&S[fst]=='0')fst++;
		S=S.substr(fst);
	}
	int id=0;
	while(id<S.size()&&S[id]=='1')id++;
	if(id==S.size())
	{
		if(S.empty())S="0";
		cout<<S<<endl;
		return 0;
	}
	string ans=S;
	for(int i=0;i<id;i++)
	{
		string now=S;
		int len=S.size()-id;
		for(int j=0;j<len;j++)if(S[i+j]=='1')now[id+j]='1';
		if(ans<now)ans=now;
	}
	cout<<ans<<endl;
}