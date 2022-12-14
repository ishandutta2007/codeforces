#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,vector<int> > mp;
map<int,vector<int> > mpp;
int n,x[55555],y[55555],z[55555];
vector<int> v,gg;
vector<pair<int,int> > ans;
bool cmp1(int i,int j)
{
	return z[i]<z[j];
}
bool cmp2(int i,int j)
{
	return y[i]<y[j];
}
bool cmp3(int i,int j)
{
	return x[i]<x[j];
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		mp[make_pair(x[i],y[i])].push_back(i);
	}
	for (map<pair<int,int>,vector<int> >::iterator it=mp.begin();it!=mp.end();it++)
	{
		v=it->second;sort(v.begin(),v.end(),cmp1);
		while((int)v.size()>=2)
		{
			ans.push_back(make_pair(v[(int)v.size()-1],v[(int)v.size()-2]));
			v.pop_back();v.pop_back();
		}
		if (!v.empty()) mpp[it->first.first].push_back(v[0]); 
	}
	for (map<int,vector<int> >::iterator it=mpp.begin();it!=mpp.end();it++)
	{
		v=it->second;sort(v.begin(),v.end(),cmp2);
		while((int)v.size()>=2)
		{
			ans.push_back(make_pair(v[(int)v.size()-1],v[(int)v.size()-2]));
			v.pop_back();v.pop_back();
		}
		if (!v.empty()) gg.push_back(v[0]);
	}
	sort(gg.begin(),gg.end(),cmp3);
	while(!gg.empty())
	{
		ans.push_back(make_pair(gg[(int)gg.size()-1],gg[(int)gg.size()-2]));
		gg.pop_back();gg.pop_back();
	}
	for (int i=0;i<ans.size();i++)
	{
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}