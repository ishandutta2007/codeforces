#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <pair<int,string> > v[10005];
int main()
{
	int n,m;
	cin >> n >> m;
	for (int i=0;i<n;i++)
	{
		string s;
		int a,b;
		cin >> s >> a >> b;
		v[a].push_back(make_pair(b,s));
	}
	for (int i=1;i<=m;i++)
	sort(v[i].begin(),v[i].end());
	for (int i=1;i<=m;i++)
	{
		if (v[i].size()==2)
		cout << v[i][0].second << ' ' << v[i][1].second << endl;
		else
		{
			if (v[i][v[i].size()-3].first==v[i][v[i].size()-2].first)
			cout << "?\n";
			else
			cout << v[i][v[i].size()-1].second << ' ' << v[i][v[i].size()-2].second << endl;
		}
	}
}