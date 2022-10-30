#include<bits/stdc++.h>
using namespace std;
int n,m;double k,x;string s;map<string,int>mp;
int main()
{
	ios::sync_with_stdio(false),cin>>n>>m>>k;
	for(int i=1;i<=n;i++) cin>>s>>x,x*=k,x>=100?mp[s]=int(x+1e-6):0;
	for(int i=1;i<=m;i++) cin>>s,!mp[s]?mp[s]=0:0;
	cout<<mp.size()<<endl;
	for(map<string,int>::iterator i=mp.begin();i!=mp.end();i++) cout<<(*i).first<<" "<<(*i).second<<endl;
	return 0;
}