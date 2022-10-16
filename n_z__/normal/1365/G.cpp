#include<bits/stdc++.h>
using namespace std;
#define int long long
main(){
	int n;
	cin>>n;
	vector<pair<int,int>>que;
	vector<int>answ(13);
	for(int x=0;que.size()<n;x++)
	if(__builtin_popcountll(x)==6)que.push_back({x,que.size()+1});
	for(auto q:que)
	cerr<<q.first<<','<<q.second<<endl;
	for(int x=0;x<13;x++)
	{
		int cnt=0;
		for(auto q:que)
		cnt+=((q.first>>x)&1);
		if(cnt)
		{
			cout<<"? "<<cnt;
			for(auto q:que)
			if((q.first>>x)&1)cout<<' '<<q.second;
			cout<<endl;
			cin>>answ[x];
		}
	}
	cout<<'!';
	for(auto q:que)
	{
		int ans=0;
		for(int x=0;x<13;x++)
		if((q.first&(1<<x))==0)ans|=answ[x];
		cout<<' '<<ans;
	}
	cout<<endl;
}