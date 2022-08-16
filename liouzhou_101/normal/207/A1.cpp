#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int LIMIT=200000;

vector<pair<pair<int,int>,int> > v;

int main()
{
	int n;
	cin>>n;
	int ans=0;
	for (int i=1;i<=n;++i)
	{
		int k,a,x,y,m;
		cin>>k>>a>>x>>y>>m;
		int p=0,b=0;
		for (int j=1;j<=k;++j)
		{
			if (a<b) ++p;
			if (v.size()<=LIMIT) v.push_back(make_pair(make_pair(p,a),i));
			b=a;
			a=((long long)a*x+y)%m;
		}
		ans=max(ans,p);
	}
	cout<<ans<<endl;
	if (v.size()<=LIMIT)
	{
		sort(v.begin(),v.end());
		for (int i=0;i<v.size();++i)
			printf("%d %d\n",v[i].first.second,v[i].second);
	}
	return 0;
}