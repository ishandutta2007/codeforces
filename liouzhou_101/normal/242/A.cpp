#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int x,y,a,b;
vector<pair<int,int> > v;

int main()
{
	cin>>x>>y>>a>>b;
	for (int i=a;i<=x;++i)
		for (int j=b;j<=y;++j)
			if (i>j)
				v.push_back(make_pair(i,j));
	cout<<v.size()<<endl;
	for (int i=0;i<v.size();++i)
		printf("%d %d\n",v[i].first,v[i].second);
	return 0;
}