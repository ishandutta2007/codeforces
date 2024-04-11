#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N,K;
string s;
bool ex[4<<17];
vector<int>G[26];
main()
{
	cin>>N>>K>>s;
	for(int i=0;i<N;i++)
	{
		ex[i]=true;
		G[s[i]-'a'].push_back(i);
	}
	for(int i=0;i<26;i++)for(int j=0;j<G[i].size()&&K>0;j++)
	{
		K--;
		ex[G[i][j]]=false;
	}
	string ans="";
	for(int i=0;i<N;i++)if(ex[i])ans+=s[i];
	cout<<ans<<endl;
}