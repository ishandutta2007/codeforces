// LUOGU_RID: 90774818
#include <bits/stdc++.h>
using namespace std;
mt19937 mt(time(0));
map<pair<int,int>,int>mp;
constexpr int C=15;
constexpr int sample_n=3,sample_p[]={0,1,0,2};
main(){
	int n;
	//n=sample_n;
	cin>>n;
	vector<int>ans(n+1);
	auto ask=[&](int x,int y=-1)
	{
		while(y==-1||y==x)y=mt()%n+1;
		if(mp.count({x,y})==1)return mp[{x,y}];
		cout<<"? "<<x<<' '<<y<<endl;
		int res;
		//res=sample_p[x]|sample_p[y];
		cin>>res;
		return mp[{x,y}]=mp[{y,x}]=res;
	};
	auto aski=[&](int x)
	{
		int res=ask(x);
		for(int t=1;t<=C;t++)
		res&=ask(x);
		return res;
	};
	int u=mt()%n+1,v=aski(u);
	for(int x=1;x<=n;x++)
	if(x!=u&&v==ask(u,x))u=x,v=aski(x);
	for(int x=1;x<=n;x++)
	if(x!=u)ans[x]=ask(x,u);
	cout<<"! ";
	for(int x=1;x<=n;x++)
	cout<<ans[x]<<' ';
}