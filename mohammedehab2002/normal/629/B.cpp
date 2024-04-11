#include <iostream>
#include <vector>
using namespace std;
vector <pair<int,int> > m,f;
int main()
{
	int n,maxi=0;
	cin >> n;
	for (int i=0;i<n;i++)
	{
		char g;
		int a,b;
		cin >> g >> a >> b;
		if (g=='M')
		m.push_back(make_pair(a,b));
		else
		f.push_back(make_pair(a,b));
	}
	for (int i=1;i<=366;i++)
	{
		int ma=0,fe=0;
		for (int x=0;x<m.size();x++)
		{
			if (m[x].first<=i && m[x].second>=i)
			ma++;
		}
		for (int x=0;x<f.size();x++)
		{
			if (f[x].first<=i && f[x].second>=i)
			fe++;
		}
		maxi=max(maxi,min(ma,fe)*2);
	}
	cout<< maxi;
}