#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
void upd(int a,int b,int c,int d)
{
	if(a!=b or c!=d)
	{
		ans.push_back({a,c,b,d});
	}
}
int main()
{
	pair<int,int> x[5];
	for(int i=1;i<=3;i++)
	{
		cin>>x[i].first>>x[i].second;
	}
	sort(x+1,x+4);
	for(int i=1;i<=3;i++)
	{
		upd(x[i].first,x[2].first,x[i].second,x[i].second);
	}
	upd(x[2].first,x[2].first,min({x[1].second,x[2].second,x[3].second}),max({x[1].second,x[2].second,x[3].second}));
	cout<<ans.size()<<endl;
	for(auto z:ans)
	{
		for(auto t:z)
		{
			cout<<t<<' ';
		}
		cout<<endl;
	}
	return 0;
}